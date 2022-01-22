#pragma once

class GuiData {
private:
	char pad_0x0000[0x18]; //0x0000
public:
	Vector2 resolution; //0x0018
	Vector2 resolution2; //0x0020
	Vector2 scaledResolution; //0x0028
private:
	char pad_0x0030[0x8]; //0x0030
public:
	float guiScale; //0x0034
private:
	char pad_0x004A[0x16]; //0x004A
public:
	short MouseX; //0x0052
	short MouseY; //0x0054

public:

	auto getResolution() { //0x18
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("48 8B 81 ? ? ? ? C3 CC CC CC CC CC CC CC CC 48 8B 81 ? ? ? ? C3 CC CC CC CC CC CC CC CC 40 53 48 83 EC 30") + 3);
		return *reinterpret_cast<GuiData**>((uintptr_t)(this) + offset);
	};

	Vector2 scaledMousePos() {
		return Vector2((this->MouseX) * this->guiScale, (this->MouseY) * this->guiScale);
	};
};