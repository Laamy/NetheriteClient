#pragma once7

class Derp : public Module {
public:
	Derp() : Module("Derp", "Misc", "makes u look retarded", GameInput::KEY_NONE) {
	}

	void onGameTick(GameMode* gm) override {
		if (clientInst->getLocalPlayer() == nullptr) return;
		auto player = clientInst->getLocalPlayer();

		
		player->getRotations()->x = -180;
	}
};