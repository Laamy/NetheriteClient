#pragma once

class ArrayList : public Module {
public:
	ArrayList() : Module("ArrayList", "Visual", "Displays enabled modules (duh)", GameInput::KEY_NONE, true) {
		addSetting("Mode", std::vector<std::string> {
			"Bar", "Split", "Outline", "None"
		});
		renderInArraylist = false; // lmao
	}

	static const struct ArraylistSortingArgs {
		bool operator()(Module* mod1, Module* mod2)
		{
			return mod1->length > mod2->length;
		}
	};

	void onThirdFrameRender(DrawUtils* renderer) override { // yea my mother told me a story about a singer who removed his ribs so he could suck his cock on the stage
		int index = 0;

		int lastmeasure = 600;

		//std::sqrt(1.3); // sqrt std's 1.3m

		renderer->setShadow(true);
		std::sort((*_modules).begin(), (*_modules).end(), ArraylistSortingArgs());
		for (auto mod : *_modules) {
			auto c2 = std::string(" ");
			auto c = std::string("");
			if (mod->moduleSettings.size() >= 1)
				c = mod->moduleSettings[0]->enums[mod->moduleSettings[0]->currentIndex];
			else c2 = "";

			TextHolder actualStr = TextHolder(TextInput::Merge("%s%s%s%s", mod->name,TextInput::Gray, c2, c.c_str()));
			TextHolder textStr = TextHolder(TextInput::Merge("%s%s%s", mod->name, c2, c.c_str()));
			

			float measureData = renderer->MeasureText(textStr.getText(), GameInput::UI_TEXT_DEFAULT);
			mod->length = measureData;

			if (lastmeasure == 600)
				lastmeasure = mod->length;

			if (!mod->enabled || !mod->renderInArraylist) continue;

			int curIndex = -index * 75;

			UIColor color = renderer->getRainbow(5, 1, 1, curIndex * 2); // transition RGB
			float lastTextLength = 0.f;
			float fancyAssMath1 = -0 + clientInst->getGuiData()->scaledResolution.x - measureData;
			float aids = -0 + clientInst->getGuiData()->scaledResolution.x;
			float fancyAssMath2 = 0 + (index * (GameInput::UI_TEXTMEASURE_HEIGHT_ARRAYLIST / 1.6));
			Vector4 underline;
			Vector2 windowSize = clientInst->getGuiData()->scaledResolution;

			Vector2 rectPos2 = Vector2(fancyAssMath1 - 6, fancyAssMath2);
			Vector2 textPos2 = Vector2(fancyAssMath1 - 4, fancyAssMath2);
			Vector2 splitPos = Vector2(fancyAssMath1 - 5, fancyAssMath2);
			Vector2 outlinePos = Vector2(fancyAssMath1 - 5, fancyAssMath2 + (GameInput::UI_TEXTMEASURE_HEIGHT_ARRAYLIST / 2 + 2));
			Vector2 underlinePos = Vector2(fancyAssMath1 - 5 + 19, fancyAssMath2);
			Vector2 textPos = Vector2(fancyAssMath1 - 2, fancyAssMath2);
			Vector2 rectPos = Vector2(fancyAssMath1 - 4, fancyAssMath2);
			Vector2 barPos = Vector2(aids - 2, fancyAssMath2);
			std::string wtf = "ahsiuhauysayustiauytysauhdasioduasduaspdiposadiasidyasuydtsatydrasidytasduyghasdsaupdoiasudoisaud";
			auto textWidth = renderer->getTextWidth(&wtf, 1);
			
			
			underline = Vector4(windowSize.x - (lastTextLength + 2.f + (0.6 * 2.f)));
			lastTextLength = textWidth;

			switch (moduleSettings[0]->currentIndex) {
			case 0: // Bar
				renderer->fillRectangle(rectPos2, Vector2(textWidth, 10), UIColor(0, 0, 0), 0.6f);
				renderer->drawText(textPos2, color, actualStr, 1.f);
				renderer->fillRectangle(barPos, Vector2(clientInst->getGuiData()->scaledResolution.x, 10), color, 10);
				break;
			case 1: // Split
				renderer->fillRectangle(rectPos, Vector2(textWidth, 10), UIColor(0, 0, 0), 0.6f);
				renderer->drawText(textPos, color, actualStr, 1.f);
				renderer->fillRectangle(splitPos, Vector2(1, 10), color, 10);
				break;
			case 2: // Outline
				renderer->fillRectangle(rectPos, Vector2(textWidth, 10), UIColor(0, 0, 0), 0.6f);
				renderer->drawText(textPos, color, actualStr, 1.f);
				renderer->fillRectangle(splitPos, Vector2(1, 10), color, 10);
				renderer->fillRectangle(1, Vector2(100, 1), color, 10);
				break;
			case 3: // None
				renderer->fillRectangle(rectPos, Vector2(textWidth, 10), UIColor(0, 0, 0), 0.6f);
				renderer->drawText(textPos, color, actualStr, 1.f);
				break;
			}

			lastmeasure = mod->length;
			
			index++;
		}
		renderer->setShadow(false);
	}
};