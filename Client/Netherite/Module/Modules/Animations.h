#pragma once
#include <corecrt_math.h>

class Animations : public Module {
public:
    Animations() : Module("Animations", "Visual", "Changes the swing/hitting animation", GameInput::KEY_NONE) {
        addSetting("Mode", std::vector<std::string> {
            "Custom" /*custom is for XYZ pos of hand*/, "1.7", "None"
        });
    }
    void* targetAddress;

	void onEnable() override {
        //if (moduleSettings[1]->currentIndex == 1) return;
        if (moduleSettings[0]->currentIndex == 3) return;

        if (targetAddress == nullptr)
            targetAddress = (void*)MCM::findSig(GameSigs::SIG_Animation_SmoothSwing);
        BYTE* patch = (BYTE*)"\x90\x90\x90\x90\x90";
        MCM::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 5);
	}

    void onDisable() override {
        BYTE* patch = (BYTE*)"\xE8\xC7\xF4\x3B\xFF";
        MCM::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 5);
    }
};