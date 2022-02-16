#pragma once

struct FontEntry {
public:
	class BitmapFont* font;
};

struct FontList {
public:
	FontEntry fontEntries[7];

};

struct FontRepos {
private:
	char pad_0x000[0x28];
public:
	FontList* fontList;
};

class MinecraftGame {
private:
	char pad_0x0000[0xF8]; //0x0000
public:
	FontRepos* fontRepos; //0x00F8
private:
	char pad_0x0100[0x20]; //0x0100
public:
	class BitmapFont* defaultGameFont; //0x0108

public: // funcs
	FontRepos* getFontRepos() {
		return *reinterpret_cast<FontRepos**>((uintptr_t)(this) + 0xF8);
	};

	BitmapFont* getMcFont() {
		return reinterpret_cast<BitmapFont*>((uintptr_t)(this) + 0x98);
	};

	bool canUseMoveKeys() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("C6 83 ? ? ? ? 00 48 8D 4C 24 20 E8") + 2);
		return *reinterpret_cast<bool*>((uintptr_t)(this) + offset);
	};

	BitmapFont* getTestFont() {
		return fontRepos->fontList->fontEntries[3].font; //8
	};
};