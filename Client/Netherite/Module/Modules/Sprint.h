#pragma once

class Sprint : public Module {
public:
	Sprint() : Module("Sprint", "Movement", "Automatically sprint", GameInput::KEY_NONE, true) {}

	void onCITick(ClientInstance* ci) override {
		if (ci->getLocalPlayer() == nullptr) return;
		auto
			w = keymap['W'],
			a = keymap['A'],
			s = keymap['S'],
			d = keymap['D'];

		bool pressed = clientInst->mcGame->canUseMoveKeys() && (w || a || s || d);
		if (pressed) {
			ci->getLocalPlayer()->setSprinting(true);
		}
	}
};