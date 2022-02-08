#pragma once

class Nametags : public Module
{
public:
	Nametags() : Module("Nametags", "Visual", "Render a nametag above players heads", GameInput::KEY_NONE, false) {
		addBoolean("Limit"); // Limit esp distance to 64 blocks
		addBoolean("HitboxCheck", 0);
	};

	void onThirdFrameRender(DrawUtils* renderer) override {
		UIColor color = renderer->getRainbow(5, 1, 1); // RGB

		if (clientInst->mcGame->canUseMoveKeys()) {
			for (auto ent : Netherite::entitylist) {
				if (ent.second == nullptr) continue;

				float maxDis = 256;
				float minDis = 0.8f;

				if (moduleSettings[0]->currentIndex == 0) {
					maxDis = 64;
				}

				Actor* plr = clientInst->getLocalPlayer(); // get player
				AABB* plrPos = plr->getPosition();
				if (plr == nullptr) return;

				Actor* entity = ent.second; // get target entity

				DWORD oldProtc = MCM::unprotect((uintptr_t)entity, 1920);

				AABB* entPos = entity->getPosition();
				Vector2* entBox = entity->getHitbox();

				if (entPos == nullptr) continue;
				if (entBox == nullptr) continue;

				if (plrPos->lower.distance(entPos->lower) >= maxDis) continue; // distance check
				if (plrPos->lower.distance(entPos->lower) <= minDis) continue;

				if (moduleSettings[5]->currentIndex == 0) {
					if (entBox->x != 0.6f) continue; // antiHitbox
					if (entBox->y != 1.8f) continue;
				}

				Vector2 output = Vector2();

				Vector3 newEntPos = entPos->upper;

				newEntPos.x -= .3f;
				newEntPos.y += .5f;
				newEntPos.z -= .3f;

				bool w2s_1 = clientInst->WorldToScreen(newEntPos, output); // W2S upper point

				if (w2s_1) {
					if (output.x < 0 || output.y < 0) continue;

					TextHolder text;
					text.setText(entity->DONTUSETHISNAMETAG().c_str());

					float nameLength = renderer->MeasureText(text.getText(), 1);

					output.x -= nameLength / 2;

					renderer->drawText(output, color, text, 1);
				}

				MCM::protect((uintptr_t)entity, 1920, oldProtc);
			}
		}
	};
};