#pragma once

class NoLagBack : public Module {
public:
	void* funcPtr;
	void* ptr;
	NoLagBack() : Module("NoLagBack", "Exploit", "Prevents the server from changing your position", GameInput::KEY_NONE) {
		uintptr_t address = MCM::findSig(GameSigs::SIG_SetPosition);
		ptr = reinterpret_cast<void*>(address);
		MH_CreateHook(this->ptr, lagBackHook, &this->funcPtr);
	}

	void onEnable() override {
		MH_EnableHook(ptr);
	}

	void onDisable() override {
		MH_DisableHook(ptr);
	}

	static bool lagBackHook(Actor* ent) { return false; }
};