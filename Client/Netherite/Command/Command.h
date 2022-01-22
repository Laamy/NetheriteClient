#pragma once

class Command {
public:
	Command(const char* name, const char* args, const char* tooltip) {
		this->name = name;
		this->tooltip = tooltip;
		this->args = args;
	}

	std::string name;
	std::string tooltip;
	std::string args;

	virtual void onExecute_Args(std::vector<std::string> args) {};
	virtual void onExecute() {};
};