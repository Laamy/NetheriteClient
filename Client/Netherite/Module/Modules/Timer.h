#pragma once

class Timer : public Module {
public:
	Timer() : Module("Timer", "Misc", "Change the internal game timer", GameInput::KEY_NONE) {}

	void onEnable() override {
		if (clientInst->getTimerCls() == nullptr) return;

		*clientInst->getTimerCls()->getTimer() = 40;
	}

	void onDisable() override {
		if (clientInst->getTimerCls() == nullptr) return;

		*clientInst->getTimerCls()->getTimer() = 20;
	}
};