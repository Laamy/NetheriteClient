#pragma once
#include <corecrt_math.h>

class Killaura : public Module {
public:
    Killaura() : Module("Killaura", "Combat", "what else u fucking twat", GameInput::KEY_NONE) {
        addSetting("Mode", {
            "Silent", "Aimbot"
            });
    }

    int tick = 0;
    int tick2 = 0;

    void onTick() override {
        if (clientInst->getLocalPlayer() == nullptr) return;
        if (tick2 == 1) {
            tick2 = 0;
            return;
        }

        auto player = clientInst->getLocalPlayer();

        float maxRange = 8;
        float minRange = 0.8f;

        for (auto ent : clientInst->getEntityList()) {
            auto entity = ent.second;

            DWORD oldProtc = MCM::unprotect((uintptr_t)entity, 1920);
            
            Actor* plr = clientInst->getLocalPlayer(); // get player
            AABB* plrPos = plr->getPosition();
            if (plr == nullptr) return;

            AABB* entPos = entity->getPosition();
            Vector2* entBox = entity->getHitbox();

            if (entBox->x != 0.6f) continue; // antiHitbox
            if (entBox->y != 1.8f) continue;

            float dis = plrPos->lower.distance(entPos->lower);

            if (dis <= maxRange && dis > minRange) {
                if (!controllerInst->leftClickDown) return;

                _gm->attack(*entity);
                player->swing();
            }

            MCM::protect((uintptr_t)entity, 1920, oldProtc);
        }
        tick2++;
    }

    void onGameTick(GameMode* gm) override {
        if (clientInst->getLocalPlayer() == nullptr) return;
        auto player = clientInst->getLocalPlayer();

        for (auto ent : clientInst->getEntityList()) {
            auto entity = ent.second;

            DWORD oldProtc = MCM::unprotect((uintptr_t)entity, 1920);

            auto dis = player->getPosition()->lower.distance(entity->getPosition()->lower);

            auto maxRange = 8;
            auto minRange = 0.8f;

            if (dis <= maxRange && dis > minRange) {
                if (!controllerInst->leftClickDown) return;

                auto eyeHeight = entity->getPosition()->lower;
                eyeHeight.y += 1.6f; // match penis height yes

                eyeHeight.x += 0.3f; // match center
                eyeHeight.z += 0.3f; // match center

                auto calcAngle = Vector3::CalcAngle(player->getPosition()->lower, eyeHeight);

                if (entity->getHitbox()->x != 0.6f) continue;
                if (entity->getHitbox()->y != 1.8f) continue;

                if (calcAngle.x > 89) continue;
                if (calcAngle.x < -89) continue;

                //player->setRot(calcAngle);
                player->bodyYaw()->x = calcAngle.y;
                player->yawUnused1()->x = calcAngle.y;

                player->getRotations()->x = calcAngle.x;

                if (moduleSettings[0]->currentIndex == 1)
                    player->getRotations()->y = calcAngle.y;

            }

            MCM::protect((uintptr_t)entity, 1920, oldProtc);
        }
    }
};