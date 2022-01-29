#pragma once

class Scaffold : public Module {
public:
	Scaffold() : Module("Scaffold", "Player", "fat cock", GameInput::KEY_B) {
		addSetting("Rotations", std::vector<std::string> {
			"Normal",
			"Down",
			"Up", // hive ig even tho normal will bypass so u dont need this
			"Silent", // normal mode but only server sided
			"None"
		});
	};
	
	bool packetspenisIsHard = false;

	void onTick() {
		if (clientInst->getLocalPlayer() == nullptr) return;
		auto player = clientInst->getLocalPlayer();
	};

	void onGameTick(GameMode* gm) override {
		if (clientInst->getLocalPlayer() == nullptr) return;
		auto player = clientInst->getLocalPlayer();

		auto c = player->getPosition()->lower;
		Vector3i blockBelow = Vector3i(c.x, c.y, c.z);
		//blockBelow.x += 0.3f;
		blockBelow.y -= 0.2f;
		//blockBelow.z += 0.3f;

		_gm->buildBlock(blockBelow, 4);
		_gm->stopBuildBlock();
	};

};