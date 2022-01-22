#pragma once

class Step : public Module {
public:
	Step() : Module("Step", "Movement", "Automatically Step", GameInput::KEY_NONE) {};

	void onCITick(ClientInstance* ci) override {
		if (ci->getLocalPlayer() == nullptr) return;

		*ci->getLocalPlayer()->getStepHeight() = 2.f;
	};

	void onDisable() override {
		if (clientInst->getLocalPlayer() == nullptr) return;

		*clientInst->getLocalPlayer()->getStepHeight() = 0.5625f;
	}
};