#pragma once

class NoSwing : public Module {
public:
    NoSwing() : Module("NoSwing", "Player", "no swing . . .", GameInput::KEY_NONE) {
        addSetting("Mode", std::vector<std::string> {
            "Server",
            "Client"
        });
    };

    void onGameTick(GameMode* gm) override {
        if (clientInst->getLocalPlayer() == nullptr || !clientInst->mcGame->canUseMoveKeys()) return;

        // they do the same rn lol
        switch (moduleSettings[0]->currentIndex) {
        case 0:
            *clientInst->getLocalPlayer()->getSwingState() = 0;
            break;
        case 1:
            *clientInst->getLocalPlayer()->getSwingState() = 0;
            break;
        }
    };
};