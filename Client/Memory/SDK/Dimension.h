#pragma once

class Dimension {
private:
	virtual void Constructor1();
	virtual void Constructor2();
public:
	virtual void onSourceCreated(class BlockSource&);
	virtual void onSourceDestroyed(BlockSource&);
	virtual void onAreaChanged(BlockSource&, Vector3i const&, Vector3i const&);
	virtual void onBlockChanged(BlockSource&, Vector3i const&, uintptr_t, Block const&, Block const&, int, class ActorBlockSyncMessage const*, class BlockChangedEventTarget);
	virtual void onBrightnessChanged(BlockSource&, Vector3i const&);
	virtual void onBlockEntityChanged(BlockSource&, class BlockActor&);
	virtual void onBlockEntityAboutToBeRemoved(BlockSource&, std::shared_ptr<class BlockActor>);
	virtual void onEntityChanged(BlockSource&, Actor&);
	virtual void onBlockEvent(BlockSource&, int, int, int, int, int);
	virtual void allChanged(void);
	virtual void addParticle(class ParticleType, Vector3 const&, Vector3 const&, int, CompoundTag const*, bool);
	virtual void sendServerLegacyParticle(class ParticleType, Vector3 const&, Vector3 const&, int);
	virtual void addParticleEffect(class HashedString const&, Vector3 const&, class MolangVariableMap const&);
	virtual void addParticleEffect(class HashedString const&, Actor const&, HashedString const&, Vector3 const&, class MolangVariableMap const&);
	virtual void addTerrainParticleEffect(Vector3i const&, class Block const&, Vector3 const&, float, float, float);
	virtual void addTerrainSlideEffect(Vector3i const&, class Block const&, Vector3 const&, float, float, float);
	virtual void addBreakingItemParticleEffect(Vector3 const&, ParticleType, class TextureUVCoordinateSet const&, bool);
	virtual void playMusic(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, Vector3 const&, float, float);
	virtual void playStreamingMusic(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, int, int, int);
	virtual void onEntityAdded(Actor&);
	virtual void onEntityRemoved(Actor&);
	virtual void onChunkLoaded(class ChunkSource&, class LevelChunk&);
	virtual void onChunkReloaded(class ChunkSource&, class LevelChunk&);
	virtual void onSubChunkLoaded(class ChunkSource&, class LevelChunk&, short);
	virtual void onChunkUnloaded(class LevelChunk&);
	virtual void onLevelDestruction(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void levelEvent(class LevelEvent, Vector3 const&, int);
	virtual void levelEvent(class LevelEvent, CompoundTag const&);
	virtual void levelSoundEvent(class LevelSoundEvent, Vector3 const&, int, class ActorDefinitionIdentifier const&, bool, bool);
	virtual void levelSoundEvent(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, Vector3 const&, float, float);
	virtual void stopSoundEvent(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void stopAllSounds(void);
	virtual void takePicture(uintptr_t, Actor*, Actor*, class ScreenshotOptions&);
	virtual void playerListChanged(void);
	virtual void init(void);
	virtual void tick(void);
	virtual void tickRedstone(void);
private:
	virtual void TryroFunc39();
	virtual void TryroFunc40();
	virtual void TryroFunc41();
public:
	virtual bool isNaturalDimension(void);
	virtual bool isValidSpawn(int, int);
	virtual float getBrightnessDependentFogColor(UIColor const&, float);
	virtual bool isFoggyAt(int, int);
	virtual int getCloudHeight(void);
	virtual int getDefaultBiome(void);
	virtual void mayRespawnViaBed(void);
	virtual void hasGround(void);
	virtual Vector3 getSpawnPos(void);
	virtual int getSpawnYPosition(void);
	virtual void hasBedrockFog(void);
	virtual int getClearColorScale(void);
	virtual void showSky(void);
	virtual bool isDay(void);
	virtual float getSunIntensity(float, Vector3 const&, float);
	virtual void forceCheckAllNeighChunkSavedStat(void);
private:
	virtual void TryroFunc58();
public:
	virtual void deserialize(CompoundTag const&);
	virtual void serialize(CompoundTag&);
	virtual void sendBroadcast(class Packet const&, Actor*);
	virtual bool is2DPositionRelevantForPlayer(Vector3i const&, Actor&);
	virtual bool isActorRelevantForPlayer(Actor&, Actor const&);
	virtual int getLightTextureImageBuilder(void);
	virtual int getBrightnessRamp(void);
	virtual void startLeaveGame(void);
	virtual float getTimeOfDay(int, float);
	virtual void _createChunkBuildOrderPolicy(void);
};