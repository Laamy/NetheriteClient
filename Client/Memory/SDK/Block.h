#pragma once

class Material {
public:
	int type; // 5 for water, 6 for lava
	bool isFlammable;
	bool isNeverBuildable;
	bool isAlwaysDestroyable;
	bool isReplaceable;
	bool isLiquid;
private:
	bool isSmallCock;
	bool isSmallerCock;
	bool IsEvenSmallerCock;
public:
	float translucency;
	bool isBlockingMotion;
	bool isBlockingPrecipitation;
	bool isSolid;
	bool isSuperHot;
	UIColor color;
};

class BlockLegacy {
private:
	char pad[0x4];
public:
	class TextHolder tileName;
private:
	char pad2[8];
public:
	class TextHolder name;
private:
	char pad3[136];
public:
	class Material* material;
private:
	char pad4[108];
public:
	short blockId;

public:
	auto getVTable() {
		return reinterpret_cast<uintptr_t**>(this);
	}
};

class Block {
private:
	char padding_0x0[0xB];
public:
	BlockLegacy* blocklegacy;
};