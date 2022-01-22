#pragma once

class TargetHUD : public Module 
{
public:
	void* funcPtr;
	void* ptr;
	TargetHUD() : Module("TargetHUD", "Visual", "sex", GameInput::KEY_NONE) 
	{
		addSetting("Mode", 
			{
			"Default", "Old", "Simple"
			});
	};

	void onEnable() override 
	{

	};

	void onFrameRender(DrawUtils* utils) 
	{
		Vector2 windowSize = clientInst->getGuiData()->scaledResolution;
		float margin = windowSize.x / 4;
		constexpr float borderPadding = 1;
		constexpr float heightX = 10;
		constexpr float heightY = 10;
		float posY = windowSize.y - margin;
		static const float rectHeight = (heightX, heightY) * 2;
		float posX = 0 + windowSize.x / 1.7;
		Vector2 rectPos2 = Vector2(posX, posY);
		std::string name1 = "Packet Client      ";

		auto nameLength = renderer->getTextWidth(&name1, 1);
		renderer->fillRectangle(rectPos2, Vector2(nameLength, 50), UIColor(0, 0, 0), 0.6f);
	};

	void onDisable() override
	{

	};
};