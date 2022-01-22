#pragma once
#include <corecrt_math.h>

class Speed : public Module {
public:
    Speed() : Module("Speed", "Movement", "Sped", GameInput::KEY_G) {
        addSetting("Mode", {
            "Vanilla",
            "Hive",
            "Kow",
            "Experimental",
            "Nethergames"});
    };

    float speed = 0.6f;
    float height = 0.4;
    int groundTimer = 0;

    // Hive
    float currSpeed = 0.3f;

    void onTick() {
        if (clientInst->getLocalPlayer() == nullptr) return;
        auto player = clientInst->getLocalPlayer();

        auto
            w = keymap['W'],
            a = keymap['A'],
            s = keymap['S'],
            d = keymap['D'];

        bool pressed = clientInst->mcGame->canUseMoveKeys() && (w || a || s || d);
        if (pressed && *player->onGround()&& (float)*moduleSettings[0]->getEnumStack() != 4)
            player->jumpFromGround();
        else if (pressed && *player->onGround())
            player->getVelocity()->y = 0.3f;
        switch (moduleSettings[0]->currentIndex) {
        case 2:
            if (*player->onGround() && groundTimer >= 2) {
                groundTimer = 0;
                player->getVelocity()->y = -0.1f;
                player->getVelocity()->y = 0.23f;
            }
            if (*player->onGround())
                groundTimer++;
            break;
        }
    };

    void onGameTick(GameMode* gm) override {
        if (clientInst->getLocalPlayer() == nullptr) return;
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
        if (w && s) {
            calcYaw -= 90.f;
        }
        auto calcYawF = calcYaw * (3.1415927f / 180);
        if (pressed && (float)*moduleSettings[0]->getEnumStack() == 4 && player->onGround()) {
            player->getVelocity()->x = cos(calcYawF) * 0.32f;
            player->getVelocity()->z = sin(calcYawF) * 0.32f;
        }
        else if (pressed) {
            player->getVelocity()->x = cos(calcYawF) * speed;
            player->getVelocity()->z = sin(calcYawF) * speed;
        }
	};

    void onDisable() override {
        if (clientInst->getLocalPlayer() == nullptr) return;
        auto player = clientInst->getLocalPlayer();
        player->getVelocity()->x *= 0;
        player->getVelocity()->z *= 0;
    }
};