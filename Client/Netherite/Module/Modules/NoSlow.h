#pragma once

class NoSlow : public Module {
public:
	NoSlow() : Module("NoSlow", "Player", "stops powdered show, webs, ect from slowing you down", GameInput::KEY_NONE, false) {
	}

	void onCITick(ClientInstance* ci) override {
		if (ci->getLocalPlayer() == nullptr) return;
		*ci->getLocalPlayer()->getSlowDown() = Vector3(0, 0, 0);
	}
};