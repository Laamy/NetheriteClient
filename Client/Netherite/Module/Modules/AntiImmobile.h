#pragma once

class AntiImmobile : public Module {
public:
	void* funcPtr;
	void* ptr;
	AntiImmobile() : Module("AntiImmobile", "Exploit", "Stops the server from freezing you in place", GameInput::KEY_NONE) {
		uintptr_t address = MCM::findSig(GameSigs::SIG_AntiImmobile);
		ptr = reinterpret_cast<void*>(address);
		MH_CreateHook(this->ptr, isImmobile, &this->funcPtr);
	};

	void onEnable() override {
		MH_EnableHook(ptr);
	};

	void onDisable() override {
		MH_DisableHook(ptr);
	};

	static bool isImmobile(Actor* ent) { return false; }
};