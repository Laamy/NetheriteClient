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

		auto eyepos = *player->eyePos0();
		Vector3i blockBelow = Vector3i(eyepos.x, eyepos.y, eyepos.z);
		blockBelow.y += player->getHeight();
		blockBelow.y += 0.5f;

		int i = 0;
		_gm->buildBlock(blockBelow, i);

		// Rotations
		//float pitchF = (int)(rand() / ((89 - 88) + 88)); idk how to use rand

		switch (moduleSettings[0]->currentIndex) {
		case 0: /*Normal -- get the ID of the block in ur hand, then set the pitch/yaw to the pos of the closest block with that id,
			    BUT only execute if ur placing a block to make sure it doesnt look at blocks ur not placing*/
			// debug for now
			player->getRotations()->x = 80;
			break;
		case 1: // Down
			player->getRotations()->x = 89;
			break;
		case 3: // Up
			player->getRotations()->x = -89;
			break;
		}
	};

};