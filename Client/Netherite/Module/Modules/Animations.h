#pragma once
#include <corecrt_math.h>

class Animations : public Module {
public:
    Animations() : Module("Animations", "Visual", "Changes the swing/hitting animation", GameInput::KEY_NONE) {
        addSetting("Mode", std::vector<std::string> {
            "Custom" /*custom is for XYZ pos of hand*/, "1.7"
        });
    };
    void* targetAddress;

	void onEnable() override {
        if (targetAddress == nullptr)
            targetAddress = (void*)MCM::findSig(GameSigs::SIG_Animation_SmoothSwing);
        BYTE* patch = (BYTE*)"\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90\x90";
        MCM::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 6);
	}

    void onDisable() override {
        BYTE* patch = (BYTE*)"\x0F\x84\x83\x02\x00\x00\x48\x8B\x46\x40\x48\x85\xC0";
        MCM::patchBytes((BYTE*)((uintptr_t)targetAddress), patch, 6);
    }
};