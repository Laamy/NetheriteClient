#pragma once
#include <corecrt_math.h>

class KillInsults : public Module {
public:
    KillInsults() : Module("KillInsults", "Misc", "fucks people", GameInput::KEY_NONE) {
        addSetting("Mode", {
            "Normal", "Custom"
            });
    }

    bool found = true;
    bool dead = false;

    void onGameTick(GameMode* gm) override {
        if (clientInst->getLocalPlayer() == nullptr) return;
        auto player = clientInst->getLocalPlayer();

        for (auto ent : clientInst->getEntityList()) {
            if (ent.first == reinterpret_cast<uintptr_t>(player))
                return;

            if (ent.second == nullptr)
                continue;

            //if (ent->isAlive() && targetList->damageTime >= 1) found = true;
           // if (found && !targetList->isAlive() && targetList->getDeathTime() >= 0) dead = true;
        }

        if (dead) {
            std::string textStr2 = "u died L";
            renderer->drawText(Vector2(0, 70.5), UIColor(255, 255, 255), textStr2, 1.f);
            dead = false;
        }
    }

};