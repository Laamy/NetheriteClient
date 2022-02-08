#pragma once

class FontEntry {
public:
	BitmapFont* font;
};

class FontList {
public:
	FontEntry fontEntries[12];
};

class FontRepos {
public:
	FontList getFontList() {
		return *reinterpret_cast<FontList*>((uintptr_t)(this) + 0x28);
	};
};

class MinecraftGame {
public: // funcs
	FontRepos getFontRepos() {
		return *reinterpret_cast<FontRepos*>((uintptr_t)(this) + 0x120);
	};

	BitmapFont* getMcFont() {
		return reinterpret_cast<BitmapFont*>((uintptr_t)(this) + 0x108 - 0x18);
	};

	bool canUseMoveKeys() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("C6 83 ? ? ? ? 00 48 8D 4C 24 20 E8") + 2);
		return *reinterpret_cast<bool*>((uintptr_t)(this) + offset);
	};

	BitmapFont* getTestFont() {
		return getFontRepos().getFontList().fontEntries[3].font; //8
	};
};