#pragma once

class NoHurtCam : public Module {
public:
	NoHurtCam() : Module("NoHurtCam", "Visual", "what else do u think fucktard", GameInput::KEY_NONE, false) {
	};

	void onCITick(ClientInstance* ci) override {
		if (ci->getLocalPlayer() == nullptr) return;
		*ci->getLocalPlayer()->getHurtTime() = Vector3(0, 0, 0);
	};
};