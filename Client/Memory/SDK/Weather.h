#pragma once

class BlockSource;
class BlockActor;
class ActorBlockSyncMessage;
class MolangVariableMap;
class ParticleType;
class HashedString;
class TextureUVCoordinateSet;
class ChunkSource;
class LevelChunk;
class ActorDefinitionIdentifier;
class LevelEvent;
class LevelSoundEvent;
class ScreenshotOptions;

class Weather {
private:
	virtual void Constructor1();
private:
	virtual void onSourceCreated(BlockSource&);
	virtual void onSourceDestroyed(BlockSource&);
	virtual void onAreaChanged(BlockSource&, Vector3i const&, Vector3i const&);
	virtual void onBlockChanged(BlockSource&, Vector3i const&, uintptr_t, Block const&, Block const&, int, ActorBlockSyncMessage const*, class BlockChangedEventTarget);
	virtual void onBrightnessChanged(BlockSource&, Vector3i const&);
	virtual void onBlockEntityChanged(BlockSource&, BlockActor&);
	virtual void onBlockEntityAboutToBeRemoved(BlockSource&, std::shared_ptr<BlockActor>);
	virtual void onEntityChanged(BlockSource&, Actor&);
	virtual void onBlockEvent(BlockSource&, int, int, int, int, int);
	virtual void allChanged(void);
	virtual void addParticle(ParticleType, Vector3 const&, Vector3 const&, int, CompoundTag const*, bool);
	virtual void sendServerLegacyParticle(ParticleType, Vector3 const&, Vector3 const&, int);
	virtual void addParticleEffect(HashedString const&, Vector3 const&, MolangVariableMap const&);
	virtual void addParticleEffect(HashedString const&, Actor const&, HashedString const&, Vector3 const&, MolangVariableMap const&);
	virtual void addTerrainParticleEffect(Vector3i const&, Block const&, Vector3 const&, float, float, float);
	virtual void addTerrainSlideEffect(Vector3i const&, Block const&, Vector3 const&, float, float, float);
	virtual void addBreakingItemParticleEffect(Vector3 const&, ParticleType, TextureUVCoordinateSet const&, bool);
	virtual void playMusic(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, Vector3 const&, float, float);
	virtual void playStreamingMusic(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, int, int, int);
	virtual void onEntityAdded(Actor&);
	virtual void onEntityRemoved(Actor&);
	virtual void onChunkLoaded(ChunkSource&, LevelChunk&);
	virtual void onChunkReloaded(ChunkSource&, LevelChunk&);
	virtual void onSubChunkLoaded(ChunkSource&, LevelChunk&, short);
	virtual void onChunkUnloaded(LevelChunk&);
	virtual void onLevelDestruction(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void levelEvent(LevelEvent, Vector3 const&, int);
	virtual void levelEvent(LevelEvent, CompoundTag const&);
	virtual void levelSoundEvent(LevelSoundEvent, Vector3 const&, int, ActorDefinitionIdentifier const&, bool, bool);
	virtual void levelSoundEvent(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, Vector3 const&, float, float);
	virtual void stopSoundEvent(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void stopAllSounds(void);
	virtual void takePicture(uintptr_t, Actor*, Actor*, ScreenshotOptions&);
	virtual void playerListChanged(void);

public:// haven't changed in years
	float* getRainLevel() {
		return reinterpret_cast<float*>((uintptr_t)(this) + 0x34);
	};

	bool* isRaining() {
		return reinterpret_cast<bool*>((uintptr_t)(this) + 0x38);
	};

	bool* isLightning() {
		return reinterpret_cast<bool*>((uintptr_t)(this) + 0x44);
	};

	float* getLightningLevel() {
		return reinterpret_cast<float*>((uintptr_t)(this) + 0x48);
	};

	float* getFogLevel() {
		return reinterpret_cast<float*>((uintptr_t)(this) + 0x4C);
	};
}; 