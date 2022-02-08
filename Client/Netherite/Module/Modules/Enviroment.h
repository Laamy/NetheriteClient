#pragma once

class Enviroment : public Module
{
public:
	Enviroment() : Module("Environment", "Misc", "Environment changer", GameInput::KEY_NONE, false) {
		addBoolean("isRaining");
		addBoolean("isLightning");
	};

	void onTick() override {
		Actor* lp = clientInst->getLocalPlayer();
		Dimension* dimension = lp->getDimensionPtr();
		Weather* weather = Netherite::vhooks.getWeather(dimension);

		switch (moduleSettings[0]->currentIndex)
		{
		case 0:
			*weather->isRaining() = false;
			break;
		case 1:
			*weather->isRaining() = true;
			break;
		}

		switch (moduleSettings[1]->currentIndex)
		{
		case 0:
			*weather->isLightning() = false;
			break;
		case 1:
			*weather->isLightning() = true;
			break;
		}

	};
};