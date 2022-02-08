#pragma once

class ServerXP : public Module {
public:
    ServerXP() : Module("ServerXP", "Exploit", "Cheat in ExperiencePoints (EP)", GameInput::KEY_NONE) {};

    void onGameTick(GameMode* gm) override {
        if (clientInst->getLocalPlayer() == nullptr) return;
        auto player = clientInst->getLocalPlayer();

        player->addLevels(100);
    }
};