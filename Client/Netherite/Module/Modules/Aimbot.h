#pragma once
#include <corecrt_math.h>

class Aimbot : public Module {
public:
    Aimbot() : Module("Aimbot", "Combat", "what else u fucking twat", GameInput::KEY_NONE) {
        addSetting("Mode", {
            "Normal", "Silent"
            });
    }

    int tick = 0;

    void onTick() override {
        if (clientInst->getLocalPlayer() == nullptr) return;
        auto player = clientInst->getLocalPlayer();

        tick++;
        if (tick != 40) {
            for (auto ent : clientInst->getEntityList()) {
                auto entity = ent.second;
                auto dis = (*player->getPos()).distance(entity->getPosition()->lower);

                if (dis <= 8 && dis > 0.1f && controllerInst->leftClickDown) {
                    auto calcAngle = Vector3::CalcAngle(*player->getPos(), *entity->eyePos0());

                    if (entity->isInvisible()) continue; // antiInvisible

                    if (entity->getHitbox()->x != 0.6f) continue; // antiHitbox
                    if (entity->getHitbox()->y != 1.8f) continue;

                    if (calcAngle.y > 90) continue; // antiRotation
                    if (calcAngle.y < -90) continue;

                    player->setRot(calcAngle);
                    player->resetRot();
                }
            }
            tick = 0;
        }
    }
};