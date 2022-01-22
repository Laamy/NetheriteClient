#pragma once

class ClickGUI : public Module {
public:
	ClickGUI() : Module("ClickGUI", "Visual", "The menu ur literally in retard", GameInput::KEY_INSERT) {
		renderInArraylist = false;
	};

	std::map<std::string, bool> modulesLastState;

	std::map<int, bool> indexedState;
	std::map<int, bool> indexedBState;

	std::map<int, bool> FIndexedState;

	void onThirdFrameRender(DrawUtils* renderer) override {
		if (controllerInst != nullptr && clientInst != nullptr && clientInst->getLocalPlayer() != nullptr && _modules != nullptr) {

			renderer->drawBackground(UIColor(0, 0, 0, 0.3f * 255));

			renderer->setShadow(true);

			clientInst->grabMouse();
			for (auto category : *_categories) {

				auto txt = TextHolder(category.first);

				auto barPos = category.second;
				//barPos.y -= 1;
				barPos.y += (GameInput::UI_TEXTMEASURE_HEIGHT_ARRAYLIST / 1.6) - 1;

				auto titlePos = category.second;
				titlePos.x -= 1;
				titlePos.y -= 2; // UI_TEXT_DEFAULT

				auto categoryTitleState = renderer->DrawButtonText(titlePos, Vector2(66, (GameInput::UI_TEXTMEASURE_HEIGHT_ARRAYLIST / 1.6) + 1),
					UIColor(255, 255, 255, 178), UIColor(0, 0, 0, 178), UIColor(0, 0, 0, 178),
					clientInst->getGuiData()->scaledMousePos(), controllerInst->leftClickDown, controllerInst->rightClickDown,
					txt, GameInput::UI_TEXT_DEFAULT, false);

				renderer->fillRectangle(barPos, Vector2(64, 1), UIColor(255, 255, 255), 255);

				int index = 1;
				for (auto mod : *_modules) {
					if (mod->category != category.first) continue;

					auto txt2 = TextHolder(mod->renderName);

					auto newPos = category.second;
					newPos.y += (GameInput::UI_TEXTMEASURE_HEIGHT_ARRAYLIST / 1.6) * index;

					//renderer->drawText(newPos, UIColor(255, 255, 255), txt2, GameInput::UI_TEXT_DEFAULT); // draw last
					auto buttonStates = renderer->DrawButtonText(newPos, Vector2(64, (GameInput::UI_TEXTMEASURE_HEIGHT_ARRAYLIST / 1.6)),
						UIColor(255, 255, 255, 255), UIColor(0, 0, 0, 178), UIColor(32, 32, 32, 178),
						clientInst->getGuiData()->scaledMousePos(), controllerInst->leftClickDown, controllerInst->rightClickDown,
						txt2, GameInput::UI_TEXT_DEFAULT, mod->enabled);
					index++;

					if (buttonStates[0] && !modulesLastState[mod->name]) {
						mod->enabled = !mod->enabled;
						if (mod->enabled)
							mod->onEnable();
						else mod->onDisable();
					}

					modulesLastState[mod->name] = buttonStates[0];

					for (auto setting : mod->moduleSettings) {
						auto txt2 = TextHolder(setting->name + ": " + setting->enums[setting->currentIndex]);

						auto newPos2 = category.second;
						newPos2.y += (GameInput::UI_TEXTMEASURE_HEIGHT_ARRAYLIST / 1.6) * index;

						auto optionStates = renderer->DrawButtonText(newPos2, Vector2(64, (GameInput::UI_TEXTMEASURE_HEIGHT_ARRAYLIST / 1.6)),
							UIColor(255, 255, 255, 255), UIColor(0, 0, 0, 178), UIColor(0, 0, 0, 178),
							clientInst->getGuiData()->scaledMousePos(), controllerInst->leftClickDown, controllerInst->rightClickDown,
							txt2, GameInput::UI_TEXT_DEFAULT, false);

						auto SID = reinterpret_cast<uintptr_t>(setting);

						if (optionStates[0] && !indexedState[SID])
							setting->NextEnum();
						if (optionStates[1] && !indexedBState[SID])
							setting->PreviousEnum();

						indexedState[SID] = optionStates[0];
						indexedBState[SID] = optionStates[1];

						index++;
					}
				}
			}

			renderer->setShadow(false);
		}
	};

	void onDisable() override {
		clientInst->releaseMouse();
	}
};