#pragma once
#include <corecrt_math.h>

class Killaura : public Module {
public:
    Killaura() : Module("Killaura", "Combat", "fucks people", GameInput::KEY_P) {
        addSetting("Rotations", {
            "Normal",
            "Smooth",
            "Silent",
            "None"
        });
    }

    void onTick() override {
        if (clientInst->getLocalPlayer() == nullptr) return;
        auto player = clientInst->getLocalPlayer();

        for (auto ent : clientInst->getEntityList()) {
            auto entity = ent.second;

            if (player->getPosition()->lower.distance((*entity).getPosition()->lower) <= 6 && player != clientInst->getLocalPlayer()) {
                player->swing();
                _gm->attack(*entity);
            }
        }
    };

    void onGameTick(GameMode* gm) override {
        if (clientInst->getLocalPlayer() == nullptr) return;
        auto player = clientInst->getLocalPlayer();

        for (auto ent : clientInst->getEntityList()) {
            auto entity = ent.second;
            auto calcAngle = Vector3::CalcAngle(*player->getPos(), *entity->eyePos0());
            player->getRotations()->x = calcAngle.y;
        }
    };
};