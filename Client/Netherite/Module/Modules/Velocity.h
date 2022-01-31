#pragma once

class Velocity : public Module {
public:
	void* funcPtr;
	void* ptr;
	Velocity() : Module("Velocity", "Movement", "Adjusts Knockback", GameInput::KEY_NONE) {
		uintptr_t address = MCM::findSig(GameSigs::SIG_KnockBack);
		ptr = reinterpret_cast<void*>(address);
		MH_CreateHook(this->ptr, lerpmotion, &this->funcPtr);
	}

	void onEnable() override {
		MH_EnableHook(ptr);
	}

	void onDisable() override {
		MH_DisableHook(ptr);
	}

	static bool lerpmotion(Vector3* ent) { return false; }
};