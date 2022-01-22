#pragma once

class ModuleOption {
public:
	ModuleOption(std::string name, bool allowedToRender) {
		this->name = name;
		this->allowedToRender = allowedToRender;
	}

	std::string name;

	bool allowedToRender;
};