#pragma once

class ClientInstance {
private:
	char pad_0x0000[0xA0]; //0x0000
public:
	MinecraftGame* mcGame; //0x00A8

public:
	auto getMcGame() { // couldn't offset sigify this
		return reinterpret_cast<MinecraftGame*>((uintptr_t)(this) + 0xA8);
	};

	auto getLocalPlayer() { //0x148
		static unsigned int offset = 0x138; // redoing this later
		static unsigned int offset2 = 0xD0;
		static unsigned int offset3 = 0x278;

		Actor* plr1 = reinterpret_cast<Actor*>((uintptr_t)(this) + offset);
		Actor* plr2 = reinterpret_cast<Actor*>((uintptr_t)(plr1) + 0xD0);
		Actor* plr3 = reinterpret_cast<Actor*>((uintptr_t)(plr2) +0x278);

		return plr3;
	};

	auto getGuiData() { //0x4D0
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("48 8B 81 ? ? ? ? C3 CC CC CC CC CC CC CC CC 48 8B 81 ? ? ? ? C3 CC CC CC CC CC CC CC CC 40 53 48 83 EC 30") + 3);
		return *reinterpret_cast<GuiData**>((uintptr_t)(this) + offset);
	};

	auto getTimerCls() { // 0xC0 + 0xD8
		static unsigned int offset1 = *reinterpret_cast<int*>(MCM::findSig("48 8B 91 ? ? ? ? 48 85 D2 74 17 48 8B CB E8 ? ? ? ? 48 83 3B ? 74 09 48 8B C3 48 83 C4 ? 5B C3 E8 ? ? ? ? CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC 40") + 3);
		static unsigned int offset2 = *reinterpret_cast<int*>(MCM::findSig("48 8B 88 ? ? ? ? F3 ? ? 49 08") + 3);

		return *reinterpret_cast<TimerCls**>(*reinterpret_cast<TimerCls**>((uintptr_t)(this) + offset1) + offset2);
	};

	auto getLoopbackSender() { // 0xE0
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("48 8B 81 ? ? ? ? C3 CC CC CC CC CC CC CC CC 48 8B 89 ? ? ? ? 48 8B 01 48 FF A0 ? ? ? ? CC CC CC CC CC CC CC CC CC CC CC CC CC CC CC 40 53 48 83 EC ? 48 8B DA 48 8D 91 ? ? ? ? 48 3B D3") + 3);
		return *reinterpret_cast<LoopbackSender**>((uintptr_t)(this) + offset);
	};


	auto getLevelRenderer() { //0xD0
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("48 8B 81 ? ? ? ? C3 CC CC CC CC CC CC CC CC 48 8B 81 ? ? ? ? 48 8B") + 3);
		return *reinterpret_cast<LevelRenderer**>((uintptr_t)(this) + offset);
	};

	auto getFovX() {
		return reinterpret_cast<float*>((uintptr_t)(this) + 0x678); // cant make offset sigs for these
	};

	auto getFovY() {
		return reinterpret_cast<float*>((uintptr_t)(this) + 0x68C);
	};

	auto getMatrix() {
		//static unsigned int a = *reinterpret_cast<int*>(MCM::findSig("48 8B 81 ? ? ? ? 48 85 C0 74 04 F0 FF 40 ? 48 8B 81 ? ? ? ? 48 89 42") + 3);
		//static unsigned int b = *reinterpret_cast<int*>(MCM::findSig("? ? 83 ? ? ? ? ? ? 44 24 40 ? ? 83 ? ? ? ? ? ? 44 24 50") + 3);

		//return reinterpret_cast<GLMatrix*>((uintptr_t)(this) + a + 0x10 + b); //0x300
		return reinterpret_cast<GLMatrix*>((uintptr_t)(this) + 0x2F0); //0x300

		//a = "48 8B 81 ? ? ? ? 48 85 C0 74 04 F0 FF 40 ? 48 8B 81 ? ? ? ? 48 89 42" + 3
		//b = "? ? 83 ? ? ? ? ? ? 44 24 40 ? ? 83 ? ? ? ? ? ? 44 24 50" + 2
		//CI + a + 0x10 + b
	};

	auto getMatrixCorrection() {
		GLMatrix toReturn = GLMatrix();

		GLMatrix* matrix = getMatrix();

		for (int i = 0; i < 4; i++) {
			toReturn.matrix[i * 4 + 0] = matrix->matrix[0 + i];
			toReturn.matrix[i * 4 + 1] = matrix->matrix[4 + i];
			toReturn.matrix[i * 4 + 2] = matrix->matrix[8 + i];
			toReturn.matrix[i * 4 + 3] = matrix->matrix[12 + i];
		}

		return &toReturn;
	};

	auto getFov() {
		return Vector2(*getFovX(), *getFovY());
	};

	__forceinline float transformx(const Vector3& p) {
		auto matrix = getMatrixCorrection()->matrix;
		return p.x * matrix[0] + p.y * matrix[4] + p.z * matrix[8] + matrix[12];
	}

	__forceinline float transformy(const Vector3& p) {
		auto matrix = getMatrixCorrection()->matrix;
		return p.x * matrix[1] + p.y * matrix[5] + p.z * matrix[9] + matrix[13];
	}

	__forceinline float transformz(const Vector3& p) {
		auto matrix = getMatrixCorrection()->matrix;
		return p.x * matrix[2] + p.y * matrix[6] + p.z * matrix[10] + matrix[14];
	}

	inline bool WorldToScreen(Vector3 pos, Vector2& screen) { // pos = pos 2 w2s, screen = output screen coords
		auto displaySize = getGuiData()->scaledResolution;
		auto origin = getLevelRenderer()->getOrigin();
		auto fov = getFov();

		pos.x -= origin.x;
		pos.y -= origin.y;
		pos.z -= origin.z;

		float x = transformx(pos);
		float y = transformy(pos);
		float z = transformz(pos);

		if (z > 0) return false;

		float mX = (float)displaySize.x / 2.0F;
		float mY = (float)displaySize.y / 2.0F;

		screen.x = mX + (mX * x / -z * fov.x);
		screen.y = mY - (mY * y / -z * fov.y);

		return true;
	}

	auto Print(const char* txt) {
		if (getLocalPlayer() == nullptr) return;
		// testing

		getLocalPlayer()->displayClientMessage(TextInput::Merge("%s[Netherite]%s %s", TextInput::Gray, TextInput::Reset, txt));
	};

public: // custom
	auto getGameFont() {
		return mcGame->getMcFont();
	};

	void releaseMouse() {
		rMouse();
	};

	void grabMouse() {
		gMouse();
	};

	void refocusMouse() {
		rfMouse();
	};

public: //vtable

private:
	virtual void Function0(); //
	virtual void Function1(); //
	virtual void Function2(); //
	virtual void Function3(); //
	virtual void Function4(); //
	virtual void Function5(); //
	virtual void Function6(); //
	virtual void Function7(); //
	virtual void Function8(); //
	virtual void Function9(); //
	virtual void Function10(); //
	virtual void Function11(); //
	virtual void Function13(); //
	virtual void Function12(); //
	virtual void Function14(); //
	virtual void Function15(); //
	virtual void Function16(); //
	virtual void Function17(); //
	virtual void Function18(); //
	virtual void Function19(); //
	virtual void Function20(); //
	virtual void Function21(); //
	virtual void Function22(); //
	virtual void Function23(); //
	virtual void Function24(); //
	virtual void Function25(); //
	virtual void Function26(); //
	virtual void Function27(); //
	virtual void Function28(); //
	virtual void Function29(); //
	virtual void Function30(); //
	virtual void Function31(); //
	virtual void Function32(); //
	virtual void Function33(); //
	virtual void Function34(); //
	virtual void Function35(); //
	virtual void Function36(); //
	virtual void Function37(); //
	virtual void Function38(); //
	virtual void Function39(); //
	virtual void Function40(); //
	virtual void Function41(); //
	virtual void Function42(); //
	virtual void Function43(); //
	virtual void Function44(); //
	virtual void Function45(); //
	virtual void Function46(); //
	virtual void Function47(); //
	virtual void Function48(); //
	virtual void Function49(); //
	virtual void Function50(); //
	virtual void Function51(); //
	virtual void Function52(); //
	virtual void Function53(); //
	virtual void Function54(); //
	virtual void Function55(); //
	virtual void Function56(); //
	virtual void Function57(); //
	virtual void Function58(); //
	virtual void Function59(); //
	virtual void Function60(); //
	virtual void Function61(); //
	virtual void Function62(); //
	virtual void Function63(); //
	virtual void Function64(); //
	virtual void Function65(); //
	virtual void Function66(); //
	virtual void Function67(); //
	virtual void Function68(); //
	virtual void Function69(); //
	virtual void Function70(); //
	virtual void Function71(); //
	virtual void Function72(); //
	virtual void Function73(); //
	virtual void Function74(); //
	virtual void Function75(); //
	virtual void Function76(); //
	virtual void Function77(); //
	virtual void Function78(); //
	virtual void Function79(); //
	virtual void Function80(); //
	virtual void Function81(); //
	virtual void Function82(); //
	virtual void Function83(); //
	virtual void Function84(); //
	virtual void Function85(); //
	virtual void Function86(); //
	virtual void Function87(); //
	virtual void Function88(); //
	virtual void Function89(); //
	virtual void Function90(); //
	virtual void Function91(); //
	virtual void Function92(); //
	virtual void Function93(); //
	virtual void Function94(); //
	virtual void Function95(); //
	virtual void Function96(); //
	virtual void Function97(); //
	virtual void Function98(); //
	virtual void Function99(); //
	virtual void Function100(); //
	virtual void Function101(); //
	virtual void Function102(); //
	virtual void Function103(); //
	virtual void Function104(); //
	virtual void Function105(); //
	virtual void Function106(); //
	virtual void Function107(); //
	virtual void Function108(); //
	virtual void Function109(); //
	virtual void Function110(); //
	virtual void Function111(); //
	virtual void Function112(); //
	virtual void Function113(); //
	virtual void Function114(); //
	virtual void Function115(); //
	virtual void Function116(); //
	virtual void Function117(); //
	virtual void Function118(); //
	virtual void Function119(); //
	virtual void Function120(); //
	virtual void Function121(); //
	virtual void Function122(); //
	virtual void Function123(); //
	virtual void Function124(); //
	virtual void Function125(); //
	virtual void Function126(); //
	virtual void Function127(); //
	virtual void Function128(); //
	virtual void Function129(); //
	virtual void Function130(); //
	virtual void Function131(); //
	virtual void Function132(); //
	virtual void Function133(); //
	virtual void Function134(); //
	virtual void Function135(); //
	virtual void Function136(); //
	virtual void Function137(); //
	virtual void Function138(); //
	virtual void Function139(); //
	virtual void Function140(); //
	virtual void Function141(); //
	virtual void Function142(); //
	virtual void Function143(); //
	virtual void Function144(); //
	virtual void Function145(); //
	virtual void Function146(); //
	virtual void Function147(); //
	virtual void Function148(); //
	virtual void Function149(); //
	virtual void Function150(); //
	virtual void Function151(); //
	virtual void Function152(); //
	virtual void Function153(); //
	virtual void Function154(); //
	virtual void Function155(); //
	virtual void Function156(); //
	virtual void Function157(); //
	virtual void Function158(); //
	virtual void Function159(); //
	virtual void Function160(); //
	virtual void Function161(); //
	virtual void Function162(); //
	virtual void Function163(); //
	virtual void Function164(); //
	virtual void Function165(); //
	virtual void Function166(); //
	virtual void Function167(); //
	virtual void Function168(); //
	virtual void Function169(); //
	virtual void Function170(); //
	virtual void Function171(); //
	virtual void Function172(); //
	virtual void Function173(); //
	virtual void Function174(); //
	virtual void Function175(); //
	virtual void Function176(); //
	virtual void Function177(); //
	virtual void Function178(); //
	virtual void Function179(); //
	virtual void Function180(); //
	virtual void Function181(); //
	virtual void Function182(); //
	virtual void Function183(); //
	virtual void Function184(); //
	virtual void Function185(); //
	virtual void Function186(); //
	virtual void Function187(); //
	virtual void Function188(); //
	virtual void Function189(); //
	virtual void Function190(); //
	virtual void Function191(); //
	virtual void Function192(); //
	virtual void Function193(); //
	virtual void Function194(); //
	virtual void Function195(); //
	virtual void Function196(); //
	virtual void Function197(); //
	virtual void Function198(); //
	virtual void Function199(); //
	virtual void Function200(); //
	virtual void Function201(); //
	virtual void Function202(); //
	virtual void Function203(); //
	virtual void Function204(); //
	virtual void Function205(); //
	virtual void Function206(); //
	virtual void Function207(); //
	virtual void Function208(); //
	virtual void Function209(); //
	virtual void Function210(); //
	virtual void Function211(); //
	virtual void Function212(); //
	virtual void Function213(); //
	virtual void Function214(); //
	virtual void Function215(); //
	virtual void Function216(); //
	virtual void Function217(); //
	virtual void Function218(); //
	virtual void Function219(); //
	virtual void Function220(); //
	virtual void Function221(); //
	virtual void Function222(); //
	virtual void Function223(); //
	virtual void Function224(); //
	virtual void Function225(); //
	virtual void Function226(); //
	virtual void Function227(); //
	virtual void Function228(); //
	virtual void Function229(); //
	virtual void Function230(); //
	virtual void Function231(); //
	virtual void Function232(); //
	virtual void Function233(); //
	virtual void Function234(); //
	virtual void Function235(); //
	virtual void Function236(); //
	virtual void Function237(); //
	virtual void Function238(); //
	virtual void Function239(); //
	virtual void Function240(); //
	virtual void Function241(); //
	virtual void Function242(); //
	virtual void Function243(); //
	virtual void Function244(); //
	virtual void Function245(); //
	virtual void Function246(); //
	virtual void Function247(); //
	virtual void Function248(); //
	virtual void Function249(); //
	virtual void Function250(); //
	virtual void Function251(); //
	virtual void Function252(); //
	virtual void Function253(); //
	virtual void Function254(); //
	virtual void Function255(); //
	virtual void Function256(); //
	virtual void Function257(); //
	virtual void Function258(); //
	virtual void Function259(); //
	virtual void Function260(); //
	virtual void Function261(); //
	virtual void Function262(); //
	virtual void Function263(); //
	virtual void Function264(); //
	virtual void Function265(); //
	virtual void Function266(); //
	virtual void Function267(); //
	virtual void Function268(); //
	virtual void Function269(); //
	virtual void Function270(); //
	virtual void Function271(); //
	virtual void Function272(); //
	virtual void Function273(); //
	virtual void Function274(); //
	virtual void Function275(); //
	virtual void Function276(); //
	virtual void Function277(); //
public:
	virtual void rMouse(); //278 (279)
	virtual void gMouse(); //279 (280)
	virtual void rfMouse(); //280 (281)
}; 