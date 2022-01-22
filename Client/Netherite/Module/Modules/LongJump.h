#pragma once

class LongJump : public Module {
public:
    LongJump() : Module("LongJump", "Movement", "Long Jump wow", GameInput::KEY_F) {
        addSetting("Mode", std::vector<std::string> {
            "Vanilla", "Hive"
        });
    }

    float height = 0.4f;
    float speed = 1.2f;

    // Hive
    float currSpeed = 0.57f;
    float currHeight = 0.47;
    int tick = 0;

    void onEnable() override {
        if (clientInst->getLocalPlayer() == nullptr) return;
        auto player = clientInst->getLocalPlayer();
        *player->getVelocity() = Vector3(0, 0, 0);
        player->animateHurt();
        currSpeed = 0.50f;
    };

    void onGameTick(GameMode* gm) override {
        auto player = clientInst->getLocalPlayer();

        auto
            w = keymap['W'],
            a = keymap['A'],
            s = keymap['S'],
            d = keymap['D'];

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

        auto calcYawF = calcYaw * (3.1415927f / 180); // 0.01745329251

        if (!*player->onGround())
            tick++;

        switch (moduleSettings[0]->currentIndex) {
        case 0: // Vanilla
            if (pressed) {
                player->getVelocity()->x = cos(calcYawF) * speed;
                player->getVelocity()->z = sin(calcYawF) * speed;
                if (*player->onGround()) player->getVelocity()->y = height;
            }
            break;
        case 1: // Hive
            if (pressed) {
                player->getVelocity()->x = cos(calcYawF) * currSpeed;
                player->getVelocity()->z = sin(calcYawF) * currSpeed;
                if (*player->onGround()) player->getVelocity()->y = currHeight;
            }
            if (pressed && tick >= 100) {
                currSpeed = 0.3;
                player->getVelocity()->x = cos(calcYawF) * currSpeed;
                player->getVelocity()->z = sin(calcYawF) * currSpeed;
                //if (currSpeed <= 0.74f) currSpeed++;
            }
            if (tick >= 150 && tick <= 165) {
                if (!*player->onGround()) player->getVelocity()->y += 0.004;
                //if (currSpeed >= 0.f) currSpeed--;
            }
            break;
        }

        if (tick >= 30 && *player->onGround()) {
            *player->getVelocity() = Vector3(0, 0, 0);
            currSpeed = 0.54f;
            tick = 0;
            setEnabled(false);
        }
    }

    void onTick() override {
    };

    void onDisable() override {
        if (clientInst->getLocalPlayer() == nullptr) return;
        tick = 0;
    };
};