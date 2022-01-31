#pragma once

class AutoClicker : public Module {
public:
	AutoClicker() : Module("AutoClicker", "Combat", "Automatically click wow", GameInput::KEY_NONE) {
	}

	void onTick() override {
		if (controllerInst == nullptr || !clientInst->mcGame->canUseMoveKeys()) return;
		controllerInst->leftClickDown = false; // shittiest way of doing it lol
	}

	void onGameTick(GameMode* gm) override {
	}
};