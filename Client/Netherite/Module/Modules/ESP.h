#pragma once

class ESP : public Module
{
public:
	ESP() : Module("ESP", "Visual", "ESP u fucking retard", GameInput::KEY_NONE, false) {};

	void onThirdFrameRender(DrawUtils* renderer) override {
		auto color = renderer->getRainbow(5, 1, 1); // RGB

		if (clientInst->getMcGame()->canUseMoveKeys()) {
			for (auto ent : clientInst->getEntityList()) {
				auto entity = ent.second;
				if (entity == nullptr || entity == clientInst->getLocalPlayer()) continue;

				//auto username = std::string(entity->getRawUsername()->getText());

				if (entity->getPosition()->upper.distance(clientInst->getLocalPlayer()->getPosition()->upper) >= 64) continue;

				Vector2 output = Vector2();
				Vector2 output2 = Vector2();

				if (clientInst->WorldToScreen(entity->getPosition()->upper, output) && clientInst->WorldToScreen(entity->getPosition()->lower, output2)) {
					Vector2 endPos = Vector2();

					if (output.x < 0 || output.y < 0 || output2.x < 0 || output2.y < 0) continue;

					if (output.x > output2.x)
						endPos.x = output.x - output2.x;
					else endPos.x = output2.x - output.x;

					if (output.y > output2.y)
						endPos.y = output.y - output2.y;
					else endPos.y = output2.y - output.y;
					//endPos.y = output.y - output2.y;

					renderer->drawRectangle(output, endPos, color, 1, 2);
				}
			}
		}
	};
};