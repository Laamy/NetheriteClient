#pragma once

class ModuleSlider : public ModuleOption { // { { 0, 1 }, { 1, 3 } }
public:
	ModuleSlider(std::string name, std::map<uintptr_t, float> enumRange, bool allowedToRender = true, int currentIndex = 0) : ModuleOption(name, allowedToRender) {
		this->enumRange = enumRange;
		this->currentIndex = currentIndex;

		//enumRange = { { 0, 1 }, { 1, 3 } };
	}

	std::map<uintptr_t, float> enumRange;
	float currentIndex;
};