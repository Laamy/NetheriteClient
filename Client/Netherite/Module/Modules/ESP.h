#pragma once

class ESP : public Module
{
public:
	ESP() : Module("ESP", "Visual", "ESP u fucking retard", GameInput::KEY_NONE, false) {
		addBoolean("Limit"); // Limit esp distance to 64 blocks

		addBoolean("ThickWidth", 1); // Render ESP with thick pen
		addBoolean("FullPen", 1); // Fill in ESP box

		addBoolean("Outline", 0); // Outline ESP box
		addBoolean("OThickWidth", 0); // Render Outlines with thick pen

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
				Vector2 output2 = Vector2();

				bool w2s_2 = clientInst->WorldToScreen(entPos->lower, output2); // W2S lower point
				bool w2s_1 = clientInst->WorldToScreen(entPos->upper, output); // W2S upper point

				if (w2s_1 && w2s_2) { // if both positions successfully W2S
					Vector2 endPos = Vector2();

					if (output.x < 0 || output.y < 0 || output2.x < 0 || output2.y < 0) continue;

					if (output.x > output2.x)
						endPos.x = output.x - output2.x;
					else endPos.x = output2.x - output.x;

					if (output.y > output2.y)
						endPos.y = output.y - output2.y;
					else endPos.y = output2.y - output.y;

					if (output.x > output2.x) // make sure it doesnt render next to the player
						output.x -= endPos.x;

					if (output.y > output2.y) // make sure it doesnt render above the player
						output.y -= endPos.y;

					float width = 2;

					if (moduleSettings[1]->currentIndex == 0) {
						width = 1;
					}

					if (moduleSettings[2]->currentIndex == 0) {
						renderer->fillRectangle(output, endPos, color, 1);
					}
					else {
						renderer->drawRectangle(output, endPos, color, 1, width);
					}

					width = 2;

					if (moduleSettings[4]->currentIndex == 0) {
						if (moduleSettings[3]->currentIndex == 0) {
							width = 1;
						}

						UIColor newColor = UIColor(color.r, color.g, color.b, color.a);

						newColor.r -= 20; // tf
						if (newColor.r < 0)
							newColor.r = 0;

						newColor.g -= 20;
						if (newColor.g < 0)
							newColor.g = 0;

						newColor.b -= 20;
						if (newColor.b < 0)
							newColor.b = 0;

						renderer->drawRectangle(output, endPos, newColor, 1, width);
					}
				}

				MCM::protect((uintptr_t)entity, 1920, oldProtc);
			}
		}
	};
};