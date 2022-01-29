#pragma once

class Module {
public:
	Module(std::string name, std::string category, std::string tooltip, uintptr_t keybind = GameInput::KEY_NONE, bool enabled = false) {
		this->name = name;
		this->category = category;
		this->tooltip = tooltip;
		this->keybind = keybind;
		this->enabled = enabled;

		this->renderInArraylist = true;
		this->renderName = name;
		this->renderCategory = category;
	}

	std::string name;
	std::string category;
	std::string tooltip;
	uintptr_t keybind;
	bool enabled = false;

	bool keybindTogglable = true; // if the keybind can be used to toggle this module
	bool renderInArraylist = true; // if it shows in arraylist or not
	bool renderSettings = false; // render settings underneath the module
	bool renderSliders = false; // render sliders underneath the module
	std::string renderName; // custom render name just like in java clients
	std::string renderCategory; // Allow moving what category a module is in or even make new categories for them

	float length = 0;

	std::vector<ModuleSetting*> moduleSettings;
	std::vector<ModuleSlider*> moduleSliders;

	void addSetting(const char* name, std::vector<std::string> myEnums, int index = 0) {
		moduleSettings.push_back(new ModuleSetting(std::string(name), myEnums, true, index));
	}

	void addSlider(const char* name, float minIndex, float maxIndex, int index = 0) {
		moduleSliders.push_back(new ModuleSlider(std::string(name), { {0, minIndex}, {1, maxIndex} }, true, index));
	}

	void setEnabled(bool value) {
		if (value == true) {
			enabled = true;
			onEnable();
		}
		else
		{
			enabled = false;
			onDisable();
		}
	}

	virtual void onEnable() {}
	virtual void onDisable() {}

	virtual void onCITick(ClientInstance* instanceCaller) {} // ClientInstance Tick
	virtual void onActorTick(Actor* entityCaller) {} // Entitylist Actor Tick
	virtual void onGameTick(GameMode* gm) {} // Argumentless onActorTick made for debuggin
	virtual void onTick() {}

	virtual void onFrameRender(DrawUtils* utils) {} // runs 3 time(s) a frame
	virtual void onThirdFrameRender(DrawUtils* utils) {} // runs 1 time(s) a frame
};