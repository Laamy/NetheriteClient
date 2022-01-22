#pragma once

class ModuleSetting : public ModuleOption {
public:
	ModuleSetting(std::string name, std::vector<std::string> enums, bool allowedToRender = true, int currentIndex = 0) : ModuleOption(name, allowedToRender)  {
		this->enums = enums;
		this->currentIndex = currentIndex;
	}

	std::vector<std::string> enums;
	int currentIndex;

	int* getEnumStack() {
		int stack = enums.size() - 1;
		return &stack;
	}

	void NextEnum() {
		if (currentIndex == *getEnumStack())
			currentIndex = 0;
		else currentIndex++;
	}

	void PreviousEnum() {
		if (currentIndex == 0)
			currentIndex = *getEnumStack();
		else currentIndex--;
	}
};