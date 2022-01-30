#pragma once

class Zoom : public Module {
public:
	Zoom() : Module("Zoom", "Visual", "Zoom in", GameInput::KEY_NONE) {}

	void onTick() override {
		if (clientInst->getLocalPlayer() == nullptr) return;

		*clientInst->getLocalPlayer()->getFieldOfView() = 0.25f;
	};

	void onDisable() override {
		if (clientInst->getLocalPlayer() == nullptr) return;

		*clientInst->getLocalPlayer()->getFieldOfView() = 1.f;
	}
};