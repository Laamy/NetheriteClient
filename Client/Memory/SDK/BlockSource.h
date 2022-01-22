#pragma once

class BlockSource {
public:
	virtual void addListener(class BlockSourceListener&);
	virtual void removeListener(class BlockSourceListener&);
	virtual void fetchEntities(class ActorType, AABB const&, Actor const*);
	virtual void hasChunksAt(class Bounds const&);
	virtual void hasChunksAt(Vector3i const&, int);
	virtual void hasChunksAt(AABB const&);
	virtual Block getBlock(int, int, int);
	virtual Block getBlock(Vector3i const&);
	virtual Material getMaterial(Vector3i const&);
	virtual Material getMaterial(int, int, int);
	virtual void containsAnyLiquid(AABB const&);
	virtual void containsMaterial(AABB const&, class MaterialType);
	virtual int getMinHeight(void);
	virtual int getDimension(void);
	virtual int getDimension2(void);
	virtual int getDimensionId(void);
	virtual void fetchAABBs(AABB const&, bool);
	virtual void fetchCollisionShapes(AABB const&, float*, bool, class IActorMovementProxy*);
	virtual int getChunkSource(void);
};