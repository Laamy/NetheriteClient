#pragma once

#include "Commands/TestCommand.h"

class CommandManager {
public:
	std::vector<Command*> commands;

	void Initialize() {

		commands.push_back(new TestCommand());
	}
};