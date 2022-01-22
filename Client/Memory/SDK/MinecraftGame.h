#pragma once

class MinecraftGame {
private:
	char pad_0x0000[0x108]; //0x0000
public:
	BitmapFont* mcFont; //0x0108

public: // funcs
	auto canUseMoveKeys() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("C6 83 ? ? ? ? 00 48 8D 4C 24 20 E8") + 2);
		return *reinterpret_cast<bool*>((uintptr_t)(this) + offset);
	};
};