#pragma once

class Reach : public Module {
public:
	Reach() : Module("Reach", "Combat", "Automatically reach", GameInput::KEY_NONE) {
		addSetting("Reach", std::vector<std::string> { "3", "4", "5", "6", "7", "8", "9", "10", "11", "12" }, 5);

		if (targetAddress == nullptr) {
			targetAddress = (void*)MCM::findSig(GameSigs::SIG_Reach);
		}
	}
	void* targetAddress;

	void onCITick(ClientInstance* a1) override {
		if (clientInst->getLocalPlayer() == nullptr) return;

		MCM::setFloat(targetAddress, (float)*moduleSettings[0]->getEnumStack() + 4);
	}

	void onDisable() override {
		if (clientInst->getLocalPlayer() == nullptr) return;

		MCM::setFloat(targetAddress, 3);
	}
};