#pragma once

class TestModule : public Module {
public:
	void* funcPtr;
	void* ptr;

	TestModule() : Module("TestModule", "Misc", "For debugging", GameInput::KEY_NONE) {
		addSetting("Mode", {
			"BPS",
			"Rotation",
			"other"
		});

		addSlider("Mode", 1, 3, 2);
	};

	bool ded = false;
	bool found = true;

	void onEnable() override {
	};

	float speed = 0.f;

	void onGameTick(GameMode* gm) override {
		if (clientInst->getLocalPlayer() == nullptr) return;
		auto player = clientInst->getLocalPlayer();

		Vector3 vel = *player->getVelocity();

		switch (moduleSettings[0]->currentIndex) {
		case 0:
			if (vel.x < 0.f)
				vel.x *= -1.f;
			if (vel.y < 0.f)
				vel.y *= -1.f;
			if (vel.z < 0.f)
				vel.z *= -1.f;

			speed = sqrtf((vel.x * vel.x) + (vel.z * vel.z));
			speed *= 36.6f;
		  //speed *= MinecraftGame->timerSpeed; / just an example

			if (!*player->onGround())
				speed /= 1.5f;
			break;
		case 1:
			clientInst->Print(TextInput::Merge("CameraRotations %s, %s",
				std::to_string(player->getRotations()->x),
				std::to_string(player->getRotations()->y)));
			break;
		case 2:

			auto calcAngle = Vector3::CalcAngle(player->getPosition()->lower, Vector3(0, 0, 0));
			
			//player->getRotations()->x = calcAngle.x;
			player->getRotations()->y = calcAngle.y;

			break;
		}
	};

	void onTick() override {
		if (clientInst->getLocalPlayer() == nullptr) return;
		auto player = clientInst->getLocalPlayer();

		//if (targetList->isAlive() && targetList->damageTime >= 1) found = true;
		//if (found && !player->isAlive() && player->getDeathTime() >= 0) ded = true;

		//auto textStr = TextHolder("u died");
		//if (ded) renderer->drawText(Vector2(6, 7.5), UIColor(255, 255, 255), textStr, 1.f);
	};

	void onThirdFrameRender(DrawUtils* renderer) override {
		if (clientInst->getLocalPlayer() == nullptr) return;
		auto player = clientInst->getLocalPlayer();

		if (player->isAlive() && *player->damageTime() > 1) found = true;
		if (found && !player->isAlive() && player->getDeathTime() >= 0) ded = true;

		if (ded) {
			std::string textStr2 = "u died L";
			renderer->drawText(Vector2(0, 70.5), UIColor(255, 255, 255), textStr2, 1.f);
			//ded = false;
		}
		if (found) {
			std::string textStr2 = "found u L";
			renderer->drawText(Vector2(0, 80.5), UIColor(255, 255, 255), textStr2, 1.f);
			//found = false;
		}

		std::string textStr = "BPS: " + std::string(std::to_string((int)speed));
		renderer->setShadow(true);
		renderer->drawText(Vector2(6, 100), UIColor(255, 255, 255), textStr, 1.f);
		renderer->setShadow(false);
	}

	void onDisable() override {
		//MH_DisableHook(ptr);
	};

	static float cameraOffset() { return 0x0; }
};