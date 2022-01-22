#pragma once

class FastPlace : public Module {
public:
	FastPlace() : Module("FastPlace", "Player", "Changes place delay", GameInput::KEY_NONE) {
	};

	void onGameTick(GameMode* gm) override {
		if (controllerInst == nullptr || !clientInst->mcGame->canUseMoveKeys()) return;

		controllerInst->rightClickDown = false; // can be replaced with buildBlock once its added
	};
};