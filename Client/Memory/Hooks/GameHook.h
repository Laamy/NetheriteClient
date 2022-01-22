/*#pragma once

class GameHook {
public:
	std::vector<VirtualHook*> hooks;

public:

	VirtualHook* getHook(const char* hookName) {
		for (auto hook : hooks) {
			if (hook->hookName == hookName)
				return hook;
		}
	}

	VirtualHook* createHook(const char* hookName, uintptr_t ptr, void* function) {
		hooks.push_back(new VirtualHook(std::string(hookName), ptr, function));
		return getHook(hookName);
	}
};

const GameHook g_Hook;*/