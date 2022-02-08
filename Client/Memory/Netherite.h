#pragma once

class VHooks {
public:
	float* getHealth(Actor* _this) {
		using GetHealth = float* (__thiscall*)(Actor*);
		static GetHealth _GetHealth = reinterpret_cast<GetHealth>(MCM::findSig("E8 ? ? ? ? 2B C6"));
		return _GetHealth(_this);
	}

	TextHolder* getFormattedNameTag(Actor* _this) {
		using GetNameTag = TextHolder * (__thiscall*)(Actor*);
		static GetNameTag _GetNameTag = reinterpret_cast<GetNameTag>(MCM::findSig("E8 ? ? ? ? 90 48 83 7D ? ? 75 71"));
		return _GetNameTag(_this);
	}

	Weather* getWeather(Dimension* _this) {
		using GetWeather = Weather * (__thiscall*)(Dimension*);
		static GetWeather _GetWeather = reinterpret_cast<GetWeather>(MCM::findSig("E8 ? ? ? ? 8B 4E 10 48 8B 56 08"));
		return _GetWeather(_this);
	}
};

static class Netherite {
public:
	static std::map<uint64_t, Actor*> entitylist;

	static std::map<uint64_t, bool> keymap;
	static std::map<uint64_t, bool> prevKeymap;

	static VHooks vhooks;
};

std::map<uint64_t, Actor*> Netherite::entitylist = std::map<uint64_t, Actor*>();

std::map<uint64_t, bool> Netherite::keymap = std::map<uint64_t, bool>();
std::map<uint64_t, bool> Netherite::prevKeymap = std::map<uint64_t, bool>();

VHooks Netherite::vhooks = VHooks();