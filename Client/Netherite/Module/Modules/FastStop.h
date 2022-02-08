#pragma once
#include <corecrt_math.h>

class FastStop : public Module {
public:
    FastStop() : Module("FastStop", "Movement", "Stop fast wow", GameInput::KEY_NONE) {
    }

    void onGameTick(GameMode* gm) override {
        auto player = clientInst->getLocalPlayer();
        auto
            w = Netherite::keymap['W'],
            a = Netherite::keymap['A'],
            s = Netherite::keymap['S'],
            d = Netherite::keymap['D'];

        bool pressed = clientInst->mcGame->canUseMoveKeys() && (w || a || s || d);

        if (!pressed) {
            player->getVelocity()->x = 0;
            player->getVelocity()->z = 0;
        }

    }
};