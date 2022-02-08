#pragma once
#include <corecrt_math.h>

class Speed : public Module {
public:
    Speed() : Module("Speed", "Movement", "Sped", GameInput::KEY_G) {
        addSetting("Mode", {
            "Vanilla",
            "Flareon",
            "Kow",
            "Debug",
            "NG",
            "Boost",
            "SArray"
        });
        addSetting("Height", {
            "Vanilla",
            "Flareon",
            "NG"
        });
        addSetting("Speed", {
            "Vanilla",
            "Flareon",
            "NG"
        });
    }

    float sArray[32] = {
        0.600000f,
        0.567372f,
        0.542301f,
        0.521003f,
        0.500231f,
        0.492002f,
        0.477320f,
        0.459731f,
        0.432101f,
        0.410786f, // 10
        0.390102f,
        0.370021f,
        0.359932f,
        0.342390f,
        0.320135f,
        0.300000f,
        0.289678f,
        0.276954f,
        0.259332f,
        0.239523f, // 20
        0.210323f,
        0.196584f,
        0.171020f,
        0.150498f,
        0.130293f,
        0.110492f,
        0.090192f,
        0.073824f,
        0.055423f,
        0.036342f, // 30
        0.012463f,
        0.003362f, // 32
    };

    float speed = 0.6f;
    float height = 0.4;
    int groundTimer = 0;

    // Hive
    float currSpeed = 0.4f;

    void onTick() {
        if (clientInst->getLocalPlayer() == nullptr) return;
        auto player = clientInst->getLocalPlayer();

        auto
            w = Netherite::keymap['W'],
            a = Netherite::keymap['A'],
            s = Netherite::keymap['S'],
            d = Netherite::keymap['D'];

        bool pressed = clientInst->mcGame->canUseMoveKeys() && (w || a || s || d);

        //if (pressed && )

        if (pressed && *player->onGround() && moduleSettings[0]->currentIndex != 4 && moduleSettings[0]->currentIndex != 1)
            player->jumpFromGround();
        else if (pressed && *player->onGround() && moduleSettings[0]->currentIndex != 1)
        {
            auto pos = *player->getPosition();
            pos.lower.y += 0.25f;
            pos.upper.y += 0.25f;
            *player->getPosition() = pos;

            if (moduleSettings[0]->currentIndex == 1)
                player->getVelocity()->y = 0.2f;
            else if (moduleSettings[0]->currentIndex == 2)
                player->getVelocity()->y = 0.13f;
            else player->getVelocity()->y = 0.3f;
        }
        switch (moduleSettings[0]->currentIndex) {
        case 2:
            if (*player->onGround() && groundTimer >= 2) {
                groundTimer = 0;
                player->getVelocity()->y = 0.23f;
            }
            if (*player->onGround())
                groundTimer++;
            break;
        case 1:
            if (*player->onGround()) {
                player->getVelocity()->y = 0.43f;
            }
            break;
        }
    }

    void onGameTick(GameMode* gm) override {
        if (clientInst->getLocalPlayer() == nullptr) return;
        auto player = clientInst->getLocalPlayer();

        auto
            w = Netherite::keymap['W'],
            a = Netherite::keymap['A'],
            s = Netherite::keymap['S'],
            d = Netherite::keymap['D'];

        bool pressed = clientInst->mcGame->canUseMoveKeys() && (w || a || s || d);
        auto calcYaw = player->getRotations()->y;

        if (w)
        {
            if (!a && !d)
                calcYaw += 90.f;
            else if (a)
                calcYaw += 45.f;
            else if (d)
                calcYaw += 135.f;
        }
        else if (s)
        {
            if (!a && !d)
                calcYaw -= 90.f;
            else if (a)
                calcYaw -= 45.f;
            else if (d)
                calcYaw -= 135.f;
        }
        else if (!w && !s)
        {
            if (!a && d)
                calcYaw += 180.f;
        }
        if (w && s) {
            calcYaw -= 90.f;
        }
        auto calcYawF = calcYaw * (3.1415927f / 180);
        if (pressed && moduleSettings[0]->currentIndex == 4) { //  && player->onGround()

            auto speed = 0.4f;

            if (moduleSettings[0]->currentIndex == 2)
                speed = 0.25f;
            else speed = 0.4f;

            player->getVelocity()->x = cos(calcYawF) * speed;
            player->getVelocity()->z = sin(calcYawF) * speed;

        }
        else if (pressed && moduleSettings[0]->currentIndex == 1) {
            if (player->getVelocity()->y >= 0.05f && check == 0) {
                check = 1;

                player->getVelocity()->x = cos(calcYawF) * 0.50f;
                player->getVelocity()->z = sin(calcYawF) * 0.50f;
            }

            if (player->getVelocity()->y < -0.05f && check == 1) {
                check = 0;

                player->getVelocity()->x = cos(calcYawF) * 0.50f;
                player->getVelocity()->z = sin(calcYawF) * 0.50f;
            }

            if (*player->onGround()) {
                player->getVelocity()->x = cos(calcYawF) * 0.50f;
                player->getVelocity()->z = sin(calcYawF) * 0.50f;
            }
        }
        else if (pressed && moduleSettings[0]->currentIndex == 5) { // i should use switches
            if (player->getVelocity()->y >= 0.05f && check == 0)
                check = 1;

            if (player->getVelocity()->y < -0.05f && check == 1) {
                check = 0;

                player->getVelocity()->x = cos(calcYawF) * 0.5f;
                player->getVelocity()->z = sin(calcYawF) * 0.5f;
            }

            if (*player->onGround()) {
                player->getVelocity()->x = cos(calcYawF) * 0.5f;
                player->getVelocity()->z = sin(calcYawF) * 0.5f;
            }
        }
        else if (pressed) {
            player->getVelocity()->x = cos(calcYawF) * speed;
            player->getVelocity()->z = sin(calcYawF) * speed;
        }
    }

    int check = 0;

    void onDisable() override {
        if (clientInst->getLocalPlayer() == nullptr) return;

        auto player = clientInst->getLocalPlayer();
        player->getVelocity()->x *= 0;
        player->getVelocity()->z *= 0;
    }
};