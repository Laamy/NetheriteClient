#pragma once

#include "../Command.h" // temp includes
#include <vector>
#include <string>

class TestCommand : public Command {
public:
	TestCommand() : Command("tp", "<float = 0, float = 0, float = 0>", "Teleport to given coords") {};

	void onExecute_Args(std::vector<std::string> args) override {
		clientInst->Print("Invalid arguments");
	};

	void onExecute() override {
		clientInst->Print("Invalid arguments");
	};
};