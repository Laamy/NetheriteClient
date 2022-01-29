#pragma once
#include <corecrt_math.h>

class Speed : public Module {
public:
    Speed() : Module("Speed", "Movement", "Sped", GameInput::KEY_G) {
        addSetting("Mode", {
            "Vanilla",
            "Hive",
            "Kow",
            "Debug",
            "NG" });
        addSetting("Height", {
            "Vanilla",
            "Hive",
            "NG" });
        addSetting("Speed", {
            "Vanilla",
            "Hive",
            "NG" });
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
            w = keymap['W'],
            a = keymap['A'],
            s = keymap['S'],
            d = keymap['D'];

        bool pressed = clientInst->mcGame->canUseMoveKeys() && (w || a || s || d);

        //if (pressed && )

        if (pressed && *player->onGround() && moduleSettings[0]->currentIndex != 4 | 1)
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
            if (*player->onGround() && groundTimer >= 5) {
                groundTimer = 0;
                player->jumpFromGround();
            }
            if (*player->onGround())
                groundTimer++;
            if (!*player->onGround())
                groundTimer = 0;
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
        if (pressed && moduleSettings[0]->currentIndex == 4) { //  && player->onGround()

            auto speed = 0.4f;

            if (moduleSettings[0]->currentIndex == 2)
                speed = 0.3f;
            else speed = 0.4f;

            player->getVelocity()->x = cos(calcYawF) * speed;
            player->getVelocity()->z = sin(calcYawF) * speed;

        }
        else if (pressed && moduleSettings[0]->currentIndex == 1) {
            player->getVelocity()->x = cos(calcYawF) * currSpeed;
            player->getVelocity()->z = sin(calcYawF) * currSpeed;
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
