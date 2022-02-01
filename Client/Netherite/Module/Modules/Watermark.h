#pragma once

class Watermark : public Module 
{
public:
	Watermark() : Module("Watermark", "Visual", "Displays watermark", GameInput::KEY_NONE, true) {
		addSetting("Mode", std::vector<std::string> {
			"CS:GO", "Text"
		});
		renderInArraylist = false;
	}

	std::string name = "N";
	std::string name2 = "etherite - v1.5";

	TextHolder aids = TextHolder(TextInput::Merge("%s%s%s%s%s", TextInput::Bold, name, TextInput::Reset, TextInput::White, name2, name2.c_str()));

	void onThirdFrameRender(DrawUtils* renderer) override {
		int index = 0;

		auto textStr = TextHolder(aids);
		auto color = renderer->getRainbow(5, 1, 1);

		switch (moduleSettings[0]->currentIndex) 
		{
		case 0: // Normal
			renderer->fillRectangle(Vector2(2, 4), Vector2(89, 16), UIColor(0, 0, 0), 0.6f);
			renderer->fillRectangle(Vector2(1.5, 2), Vector2(90, 2), color, 1.f);
			renderer->setShadow(true);
			renderer->drawText(Vector2(6, 7.5), color, textStr, 1.f);
			renderer->setShadow(false);
			break;
		case 1: // New
			renderer->setShadow(true);
			renderer->drawText(Vector2(6, 7.5), color, textStr, 1.5f);
			renderer->setShadow(false);
			break;
		
		}
		index++;
	}
};