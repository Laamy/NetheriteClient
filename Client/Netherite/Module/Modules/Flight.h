#pragma once

class Flight : public Module {
public:
	Flight() : Module("Flight", "Movement", "Allows you to fly wow!!", GameInput::KEY_NONE) {
		addSetting("Mode", {
		"Vanilla",
		"Airwalk",
		"Hive",
		"Bounce" }, 0);
	};

	float effectiveValue = 0;
	float speed = 1.f;
	float value = 0.f;

	void onTick() override {
		if (clientInst->getLocalPlayer() == nullptr) return;
		auto player = clientInst->getLocalPlayer();

		// math
		auto
			w = keymap['W'],
			a = keymap['A'],
			s = keymap['S'],
			d = keymap['D'];

		bool pressed = clientInst->mcGame->canUseMoveKeys() && (w || a || s || d);
		auto calcYaw = player->getRotations()->y;

		if (w)
		{
			if (!a && !d)
				calcYaw += 90.f;
			else if (a)
				calcYaw += 45.f;
			else if (d)
				calcYaw += 135.f;
		}
		else if (s)
		{
			if (!a && !d)
				calcYaw -= 90.f;
			else if (a)
				calcYaw -= 45.f;
			else if (d)
				calcYaw -= 135.f;
		}
		else if (!w && !s)
		{
			if (!a && d)
				calcYaw += 180.f;
		}
		auto calcYawF = calcYaw * (3.1415927f / 180); // 0.01745329251
		auto fallDistance = *player->getFallDistance();

		switch (moduleSettings[0]->currentIndex) {
		case 0: // Vanilla
			effectiveValue = value;
			player->getVelocity()->y = effectiveValue;
			if (pressed) {
				player->getVelocity()->x = cos(calcYawF) * speed;
				player->getVelocity()->z = sin(calcYawF) * speed;
				//if (boost && *player->onGround()) player->jumpFromGround();
			}
			else {
				player->getVelocity()->x *= 0;
				player->getVelocity()->z *= 0;
			}

			if (clientInst->mcGame->canUseMoveKeys()) {
				/*if (up) {
					ci->Print(TextInput::Merge("up"));
					effectiveValue += speed;
				}
				if (down) {
					ci->Print(TextInput::Merge("down"));
					effectiveValue -= speed;
				}*/
			}
			break;
		case 1: // Airwalk
			//if (speedMod->isEnabled() || GameData::isKeyDown(*input->spaceBarKey)) {
				//*player->onGround() = false;
			//} else {
				*player->onGround() = true;
			//}
			player->getVelocity()->y = effectiveValue;
			effectiveValue = value;
			break;
		case 2: // Hive
			if (fallDistance >= 9) {

				auto pos = *player->getPosition();
				pos.lower.y += fallDistance;
				pos.upper.y += fallDistance;
				*player->getPosition() = pos;

				*player->getFallDistance() = 0;

				player->getVelocity()->y = 0;

				player->getVelocity()->x *= 2.5f;
				player->getVelocity()->z *= 2.5f;
			}
			break;
		case 3: // Bounce
			if (player->getVelocity()->y <= -.5f) {
				player->getVelocity()->y = .03f;

				player->getPosition()->lower.y += *player->getFallDistance();
				player->getPosition()->upper.y += *player->getFallDistance();

				player->getVelocity()->x *= 2.5f;
				player->getVelocity()->z *= 2.5f;
			}
			break;
		}
	};

	void onDisable() override {
		if (clientInst->getLocalPlayer() == nullptr) return;
		auto player = clientInst->getLocalPlayer();
		/*switch (moduleSettings[0]->currentIndex) {
		case 0: // Vanilla
			break;
		}*/
		player->getVelocity()->x *= 0;
		player->getVelocity()->z *= 0;
	}
};