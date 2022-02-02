#pragma once
#include <corecrt_math.h>

class Killaura : public Module {
public:
    Killaura() : Module("Killaura", "Combat", "what else u fucking twat", GameInput::KEY_NONE) {
        addSetting("Mode", {
            "Normal", "Silent"
            });
    }

    int tick = 0;
    int tick2 = 0;

    void onTick() override {
        if (tick2 == 1) {
            tick2 = 0;
            return;
        }
        if (clientInst->getLocalPlayer() == nullptr) return;
        auto player = clientInst->getLocalPlayer();

        for (auto ent : clientInst->getEntityList()) {
            auto entity = ent.second;
            auto dis = (*player->getPos()).distance(entity->getPosition()->lower);

            auto maxRange = 8;
            auto minRange = 0.8f;

            if (moduleSettings[1]->currentIndex == 1)
                maxRange = 5;

            if (dis <= maxRange && dis > minRange && controllerInst->leftClickDown
                && entity->getFormattedNameTag().length() > 6
                && entity->getFormattedNameTag().length() < 48) {

                if (entity->getHitbox()->x != 0.6f) continue; // antiHitbox
                if (entity->getHitbox()->y != 1.8f) continue;

                _gm->attack(*entity);
                player->swing();
            }
        }
        tick2++;
    }

    void onGameTick(GameMode* gm) override {
        if (clientInst->getLocalPlayer() == nullptr) return;
        auto player = clientInst->getLocalPlayer();

        for (auto ent : clientInst->getEntityList()) {
            auto entity = ent.second;
            auto dis = (*player->getPos()).distance(entity->getPosition()->lower);

            auto maxRange = 8;
            auto minRange = 0.8f;

            if (moduleSettings[1]->currentIndex == 1)
                maxRange = 5;

            if (dis <= maxRange && dis > minRange && controllerInst->leftClickDown) {

                auto eyeHeight = entity->getPosition()->lower;
                eyeHeight.y += 1.6f; // match penis height yes

                eyeHeight.x += 0.3f; // match center
                eyeHeight.z += 0.3f; // match center

                auto calcAngle = Vector3::CalcAngle(*player->getPos(), eyeHeight);

                if (entity->getHitbox()->x != 0.6f) continue; // antiHitbox
                if (entity->getHitbox()->y != 1.8f) continue;

                if (calcAngle.x > 89) continue;
                if (calcAngle.x < -89) continue;

                //player->setRot(calcAngle);
                player->bodyYaw()->x = calcAngle.y;
                player->yawUnused1()->x = calcAngle.y;

                player->getRotations()->x = calcAngle.x;

                if (moduleSettings[1]->currentIndex == 1)
                    player->getRotations()->y = calcAngle.y; // dont use this

            }
        }
    }
};