#pragma once

class BlockSourceListener;
class ActorType;
class Bounds;

class BlockSource {
public:
	virtual void addListener(BlockSourceListener&);
	virtual void removeListener(BlockSourceListener&);
	virtual void fetchEntities(ActorType, AABB const&, Actor const*);
	virtual void hasChunksAt(Bounds const&);
	virtual void hasChunksAt(Vector3i const&, int);
	virtual void hasChunksAt(AABB const&);
	virtual Block* getBlock(int, int, int);
	virtual Block* getBlock(Vector3i const&);
	virtual Material* getMaterial(Vector3i const&);
	virtual Material* getMaterial(int, int, int);
	virtual void containsAnyLiquid(AABB const&);
	virtual void containsMaterial(AABB const&, class MaterialType);
	virtual int getMinHeight(void);
	virtual int getDimension(void);
	virtual int getDimension2(void);
	virtual int getDimensionId(void);
	virtual void fetchAABBs(AABB const&, bool);
	virtual void fetchCollisionShapes(AABB const&, float*, bool, class IActorMovementProxy*);
	virtual int getChunkSource(void);

public: // temp fixes
	auto getBlock(Vector3i pos) {
		uintptr_t ptr = MCM::findSig("");

		using GetBlock = Block*(__thiscall*)(BlockSource*, Vector3i*);
		static GetBlock _GetBlock = reinterpret_cast<GetBlock>(ptr);
		return _GetBlock(this, &pos);
	}
};