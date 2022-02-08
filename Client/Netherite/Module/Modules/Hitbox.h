#pragma once

class Hitbox : public Module {
public:
    Hitbox() : Module("Hitbox", "Player", "Increase entityhitboxes", GameInput::KEY_NONE) {}

    void onGameTick(GameMode* gm) override {
        for (auto ent : Netherite::entitylist) {
            auto entity = ent.second;
            entity->getHitbox()->x = 7;
            entity->getHitbox()->y = 7;
        }
    }
};