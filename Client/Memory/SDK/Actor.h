#include <cstdint>

class Actor {
public: // vtable shit
	auto getVTable() {
		return reinterpret_cast<uintptr_t**>(this); // lick my toes
	}

	/*
	
	VTable offsets
	outOfWorld - 7
	setPos - 19 (NoLagBack)

	getPos - 22
	getOldPos - 23
	getExtrapolatedPos - 24
	getAttachPos - 25
	getFiringPos - 26

	setRot - 27

	isFireImmune - 40 (NoFire)

	lerpMotion - 46 (NoKnockBack)

	canShowNametag - 60

	isInWater - 71 (NoWater)

	canSeePos - 83
	canSeeEntity - 84

	isImmobile - 91 (AntiImmobile)

	isOnFire - 102 (NoFire)

	isEnchanted - 129 (NoGlit)

	heal - 209 (Regen)
	
	isSprinting- 277 (AutoSprint)

	*/

public:
	virtual __int64 getLastHurtByMob(void);
	virtual void setLastHurtByMob(class Mob*);
	virtual __int64 getLastHurtByPlayer(void);
	virtual void setLastHurtByPlayer(Actor*);
	virtual __int64 getLastHurtMob(void);
	virtual void setLastHurtMob(Actor*);
	virtual bool outOfWorld(void);
	virtual void reloadHardcoded(); // removed
	virtual void reloadHardcodedClient(); // removed
	virtual void initializeComponents(); // removed
	virtual void reloadComponents(); // removed
	virtual void _serverInitItemStackIds(void);
	virtual void _doInitialMove(void);
	virtual bool hasComponent(class HashedString const&);
private:
	virtual void __PlayerConstructor();
public:
	virtual void reset(void);
	virtual int getOnDeathExperience(void);
	virtual int getOwnerEntityType(void);
	virtual void remove(void);
	virtual void setPos(Vector3 const&);
	virtual bool isRuntimePredictedMovementEnabled(void);
	virtual Vector3* getPredictedMovementValues(void);
	virtual Vector3* getPos(void);
	virtual Vector3* getPosOld(void);
	virtual float getPosExtrapolated(float);
	virtual float getAttachPos(class ActorLocation, float);
	virtual Vector3* getItemFiringPos(void);
	virtual void setRot(Vector2 const&);
	virtual void move(Vector3 const&);
	virtual void move(class IActorMovementProxy&, Vector3 const&);
	virtual float getInterpolatedRidingPosition(float);
	virtual float getInterpolatedBodyRot(float);
	virtual float getInterpolatedHeadRot(float);
	virtual float getInterpolatedBodyYaw(float);
	virtual float getYawSpeedInDegreesPerSecond(void);
	virtual float getInterpolatedWalkAnimSpeed(float);
	virtual float getInterpolatedRidingOffset(float);
	virtual void checkBlockCollisions(); // removed
	virtual void updateEntityInside(AABB const&);
	virtual void updateEntityInside(void);
	virtual bool isFireImmune(void);
	virtual void breaksFallingBlocks(void);
	virtual void blockedByShield(class ActorDamageSource const&, Actor&);
	virtual void teleportTo(Vector3 const&, bool, int, int);
	virtual void tryTeleportTo(Vector3 const&, bool, bool, int, int);
	virtual void chorusFruitTeleport(Vector3 const&);
	virtual void lerpMotion(Vector3 const&);
	virtual void tryCreateAddActorPacket(void);
	virtual void normalTick(void);
	virtual void baseTick(void);
	virtual void vehicleTick(void);
	virtual void positionPassenger(Actor&, float);
	virtual float getRidingHeight(void);
	virtual void startRiding(Actor&);
	virtual void addPassenger(Actor&);
	virtual void flagPassengerToRemove(Actor&);
	virtual TextHolder getExitTip(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, class InputMode);
	virtual void intersects(Vector3 const&, Vector3 const&);
	virtual bool isInWall(void);
	virtual bool isInvisible(void);
	virtual void canShowNameTag(void);
	virtual void canExistInPeaceful(void);
	virtual void setNameTagVisible(bool);
private:
	virtual void TryroFunc67();
public:
	virtual __int64 getNameTagAsHash(void);
	virtual std::string getFormattedNameTag(void);
	virtual void filterFormattedNameTag(class UIProfanityContext const&);
	virtual void setNameTag(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual bool getAlwaysShowNameTag(void);
	virtual void setScoreTag(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
private:
	virtual void TryroFunc74();
public:
	virtual bool isInWater(void);
	virtual void hasEnteredWater(void);
	virtual bool isInLava(void);
	virtual bool isUnderLiquid(class MaterialType);
	virtual bool isOverWater(void);
	virtual void setBlockMovementSlowdownMultiplier(Vector3 const&);
	virtual void resetBlockMovementSlowdownMultiplier(void);
	virtual int getCameraOffset(void);
	virtual int getShadowHeightOffs(void);
	virtual int getShadowRadius(void);
	virtual float getHeadLookVector(float);
	virtual void canSeeInvisible(void);
	virtual void canSee(Actor const&);
	virtual void canSee(Vector3 const&);
	virtual bool isSkyLit(float);
	virtual float getBrightnessAtBlock(float);
	virtual void interactPreventDefault(void);
	virtual void playerTouch(Actor&);
	virtual void onAboveBubbleColumn(bool);
	virtual void onInsideBubbleColumn(bool);
	virtual bool isImmobile(void);
	virtual bool isSilent(void);
	virtual bool isPickable(void);
	virtual bool isFishable(void);
	virtual bool isSleeping(void);
	virtual void setSleeping(bool);
	virtual bool isShootable(void);
	virtual void setSneaking(bool);
	virtual bool isBlocking(void);
	virtual bool isDamageBlocked(ActorDamageSource const&);
	virtual bool isAlive(void);
	virtual bool isOnFire(void);
	virtual bool isOnHotBlock(void);
	virtual bool isCreativeModeAllowed(void);
	virtual bool isSurfaceMob(void);
	virtual bool isTargetable(void);
	virtual bool isLocalPlayer(void);
	virtual bool isPlayer(void);
	virtual bool isAffectedByWaterBottle(void);
	virtual void canAttack(Actor*, bool);
	virtual void setTarget(Actor*);
	virtual void findAttackTarget(void);
	virtual bool isValidTarget(Actor*);
	virtual void attack(Actor&, class ActorDamageCause const&);
	virtual void performRangedAttack(Actor&, float);
	virtual void adjustDamageAmount(int&);
	virtual int getEquipmentCount(void);
	virtual void setOwner(uint64_t);
	virtual void setSitting(bool);
	virtual void onTame(void);
	virtual void onFailedTame(void);
	virtual __int64 getInventorySize(void);
	virtual __int64 getEquipSlots(void);
	virtual __int64 getChestSlots(void);
	virtual void setStanding(bool);
	virtual void canPowerJump(void);
	virtual void setCanPowerJump(bool);
	virtual bool isJumping(void);
	virtual bool isEnchanted(void);
	virtual void vehicleLanded(Vector3 const&, Vector3 const&);
	virtual void shouldRender(void);
	virtual void playAmbientSound(void);
	virtual int getAmbientSound(void);
	virtual bool isInvulnerableTo(ActorDamageSource const&);
	virtual __int64 getBlockDamageCause(class Block const&);
	virtual void actuallyHurt(int, ActorDamageSource const&, bool);
	virtual void animateHurt(void);
	virtual void doFireHurt(int);
	virtual void onLightningHit(void);
	virtual void onBounceStarted(class BlockPos const&, Block const&);
	virtual void feed(int);
	virtual void handleEntityEvent(class ActorEvent, int);
	virtual float getPickRadius(void);
	virtual int getActorRendererId(void);
	virtual void spawnAtLocation(int, int);
	virtual void spawnAtLocation(int, int, float);
	virtual void spawnAtLocation(Block const&, int);
	virtual void spawnAtLocation(Block const&, int, float);
	virtual void spawnAtLocation(class ItemStack const&, float);
	virtual void despawn(void);
	virtual void killed(Actor&);
	virtual void awardKillScore(Actor&, int);
	virtual void setArmor(class ArmorSlot, ItemStack const&);
	virtual __int64 getArmor(ArmorSlot);
	virtual __int64 getAllArmor(void);
	virtual __int64 getArmorMaterialTypeInSlot(ArmorSlot);
	virtual __int64 getArmorMaterialTextureTypeInSlot(ArmorSlot);
	virtual __int64 getArmorColorInSlot(ArmorSlot, int);
	virtual __int64 getEquippedSlot(class EquipmentSlot);
	virtual void setEquippedSlot(EquipmentSlot, ItemStack const&);
	virtual __int64 getCarriedItem(void);
	virtual void setCarriedItem(ItemStack const&);
	virtual void setOffhandSlot(ItemStack const&);
	virtual __int64 getEquippedTotem(void);
	virtual void consumeTotem(void);
	virtual void save(class CompoundTag&);
	virtual void saveWithoutId(CompoundTag&);
	virtual void load(CompoundTag const&, class DataLoadHelper&);
	virtual void loadLinks(CompoundTag const&, std::vector<class ActorLink, std::allocator<ActorLink>>&, DataLoadHelper&);
	virtual int getEntityTypeId(void);
	virtual void queryEntityRenderer(void);
	virtual int getSourceUniqueID(void);
	virtual void thawFreezeEffect(void);
	virtual bool canFreeze(void);
	virtual bool isWearingLeatherArmor(void);
	virtual AABB getLiquidAABB(MaterialType);
	virtual void handleInsidePortal(BlockPos const&);
	virtual int getPortalCooldown(void);
	virtual int getPortalWaitTime(void);
	virtual int getDimensionId(void);
	virtual void canChangeDimensions(void);
	virtual void changeDimension(); // removed
	virtual void changeDimension(class ChangeDimensionPacket const&);
	virtual class Actor* getControllingPlayer(void);
	virtual void checkFallDamage(float, bool);
	virtual void causeFallDamage(float, float, ActorDamageSource);
	virtual void handleFallDistanceOnServer(float, float, bool);
	virtual void playSynchronizedSound(class LevelSoundEvent, Vector3 const&, Block const&, bool);
	virtual void playSynchronizedSound(LevelSoundEvent, Vector3 const&, int, bool);
	virtual void onSynchedFlagUpdate(int, long, long);
	virtual void onSynchedDataUpdate(int);
	virtual void canAddPassenger(Actor&);
	virtual void canPickupItem(ItemStack const&);
	virtual void canBePulledIntoVehicle(void);
	virtual void inCaravan(void);
	virtual bool isLeashableType(void);
	virtual void tickLeash(void);
	virtual void sendMotionPacketIfNeeded(void);
	virtual void canSynchronizeNewEntity(void);
	virtual void stopRiding(bool, bool, bool);
	virtual void startSwimming(void);
	virtual void stopSwimming(void);
	virtual void buildDebugInfo(std::basic_string<char, std::char_traits<char>, std::allocator<char>>&);
	virtual int getCommandPermissionLevel(void);
	virtual bool isClientSide(void);
	virtual __int64 getMutableAttribute(class Attribute const&);
	virtual __int64 getAttribute(class Attribute const&);
	virtual int getDeathTime(void);
	virtual void heal(int);
	virtual bool isInvertedHealAndHarm(void);
	virtual void canBeAffected(int);
	virtual void canBeAffected(class MobEffectInstance const&);
	virtual void canBeAffectedByArrow(MobEffectInstance const&);
	virtual void onEffectAdded(MobEffectInstance&);
	virtual void onEffectUpdated(MobEffectInstance&);
	virtual void onEffectRemoved(MobEffectInstance&);
	virtual __int64 getAnimationComponent(void);
	virtual void openContainerComponent(Actor&);
	virtual void swing(void);
	virtual void useItem(class ItemStackBase&, class ItemUseMethod, bool);
	virtual void hasOutputSignal(class uchar);
	virtual __int64 getOutputSignal(void);
	virtual __int64 getDebugText(std::vector<std::basic_string<char, std::char_traits<char>, std::allocator<char>>, std::allocator<std::basic_string<char, std::char_traits<char>, std::allocator<char>>>>&);
	virtual float getMapDecorationRotation(void);
	virtual float getPassengerYRotation(Actor const&);
	virtual float getYHeadRot(void);
	virtual bool isWorldBuilder(void);
	virtual bool isCreative(void);
	virtual bool isAdventure(void);
	virtual void add(ItemStack&);
	virtual void drop(ItemStack const&, bool);
	virtual __int64 getInteraction(Actor&, class ActorInteraction&, Vector3 const&);
	virtual void canDestroyBlock(Block const&);
	virtual void setAuxValue(int);
	virtual void setSize(float, float);
	virtual void onOrphan(void);
	virtual void wobble(void);
	virtual void wasHurt(void);
	virtual void startSpinAttack(void);
	virtual void stopSpinAttack(void);
	virtual void setDamageNearbyMobs(bool);
	virtual void renderDebugServerState(class Options const&);
	virtual void reloadLootTable(void);
	virtual void reloadLootTable(class EquipmentTableDefinition const&);
	virtual int getDeletionDelayTimeSeconds(void);
	virtual void kill(void);
	virtual void die(ActorDamageSource const&);
	virtual void shouldDropDeathLoot(void);
	virtual void shouldTick(void);
	virtual void extractSnapshot(class PlayerSnapshotComponent&);
	virtual void applySnapshot(PlayerSnapshotComponent const&, PlayerSnapshotComponent const&);
	virtual float getNextStep(float);
	virtual __int64 getLootTable(void);
	virtual void interpolatorTick(void);
	virtual void updateEntitySpecificMolangVariables(class RenderParams&);
	virtual void shouldTryMakeStepSound(void);
	virtual void canMakeStepSound(void);
	virtual void _hurt(ActorDamageSource const&, int, bool, bool);
	virtual void markHurt(void);
	virtual void _getAnimationComponent(); // removed
	virtual void readAdditionalSaveData(CompoundTag const&, DataLoadHelper&);
	virtual void addAdditionalSaveData(CompoundTag&);
	virtual void _playStepSound(BlockPos const&, Block const&);
	virtual void _playFlySound(BlockPos const&, Block const&);
	virtual void _makeFlySound(void);
	virtual void checkInsideBlocks(float);
	virtual void pushOutOfBlocks(Vector3 const&);
	virtual void updateWaterState(void);
	virtual void doWaterSplashEffect(void);
	virtual void spawnTrailBubbles(void);
	virtual void updateInsideBlock(void);
	virtual void _removePassenger(uint64_t const&, bool, bool, bool);
	virtual void _onSizeUpdated(void);
	virtual void _doAutoAttackOnTouch(Actor&);
	virtual void knockback(Actor*, int, float, float, float, float, float);
	virtual void spawnAnim(void);
	virtual void setSprinting(bool);
	virtual int getHurtSound(void);
	virtual int getDeathSound(void);
	virtual __int64 getItemInHandIcon(ItemStack const&, int);
	virtual float getSpeed(void);
	virtual void setSpeed(float);
	virtual float getJumpPower(void);
	virtual void hurtEffects(ActorDamageSource const&, int, bool, bool);
	virtual float getMeleeWeaponDamageBonus(Actor);
	virtual float getMeleeKnockbackBonus(void);
	virtual void travel(float, float, float);
	virtual void travel(class IMobMovementProxy&, float, float, float);
	virtual void applyFinalFriction(float, bool);
	virtual void updateWalkAnim(void);
	virtual void aiStep(void);
	virtual void aiStep(IMobMovementProxy&);
	virtual void pushActors(void);
	virtual void lookAt(Actor*, float, float);
	virtual bool isLookingAtAnEntity(void);
	virtual void checkSpawnRules(bool);
	virtual void checkSpawnObstruction(void);
	virtual float getAttackAnim(float);
	virtual int getItemUseDuration(void);
	virtual int getItemUseStartupProgress(void);
	virtual int getItemUseIntervalProgress(void);
	virtual int getItemUseIntervalAxis(void);
	virtual int getTimeAlongSwing(void);
	virtual void ate(void);
	virtual int getMaxHeadXRot(void);
	virtual bool isAlliedTo(Actor);
	virtual void doHurtTarget(Actor*, ActorDamageCause const&);
	virtual void canBeControlledByPassenger(void);
	virtual void leaveCaravan(void);
	virtual void joinCaravan(Actor);
	virtual void hasCaravanTail(void);
	virtual __int64 getCaravanHead(void);
	virtual float getArmorValue(void);
	virtual float getArmorCoverPercentage(void);
	virtual void hurtArmorSlots(); // removed
	virtual void setDamagedArmor(ArmorSlot, ItemStack const&);
	virtual void sendArmorDamage(); // removed
	virtual void sendArmor(); // removed
	virtual void containerChanged(int);
	virtual void updateEquipment(void);
	virtual void clearEquipment(void);
	virtual __int64 getAllArmorID(void);
	virtual __int64 getAllHand(void);
	virtual __int64 getAllEquipment(void);
	virtual __int64 getArmorTypeHash(void);
	virtual void dropEquipmentOnDeath(ActorDamageSource const&, int);
	virtual void dropEquipmentOnDeath(void);
	virtual void clearVanishEnchantedItemsOnDeath(void);
	virtual void sendInventory(bool);
	virtual float getDamageAfterMagicAbsorb(ActorDamageSource const&, int);
	virtual void createAIGoals(void);
	virtual void onBorn(Actor&, Actor&);
	virtual void setItemSlot(EquipmentSlot, ItemStack const&);
	virtual void setTransitioningSitting(bool);
	virtual void attackAnimation(Actor*, float);
	virtual int getAttackTime(void);
	virtual void _getWalkTargetValue(BlockPos const&);
	virtual void canExistWhenDisallowMob(void);
	virtual void useNewAi(void);
	virtual void ascendLadder(void);
	virtual void ascendBlockByJumping(void);
	virtual void descendBlockByCrouching(void);
	virtual void dropContainer(void);
	virtual void initBodyControl(void);
	virtual void jumpFromGround(void);
	virtual void jumpFromGround(IMobMovementProxy&);
	virtual void updateAi(void);
	virtual void newServerAiStep(void);
	virtual void _serverAiMobStep(void);
	virtual float getDamageAfterEnchantReduction(ActorDamageSource const&, int);
	virtual float getDamageAfterArmorAbsorb(ActorDamageSource const&, int);
	virtual void dropBags(void);
	virtual void tickDeath(void);
	virtual void updateGliding(void);
	virtual void _allowAscendingScaffolding(void);
	virtual void _getAdjustedAABBForSpawnCheck(AABB const&, Vector3 const&);
	virtual void prepareRegion(); // removed
	virtual void destroyRegion(void);
	virtual void suspendRegion(void);
	virtual void resendAllChunks(void);
	virtual void _fireWillChangeDimension(void);
	virtual void _fireDimensionChanged(void);
	virtual void changeDimensionWithCredits(); // removed
	virtual void tickWorld(); // removed
private:
	virtual void TryroFunc369();
public:
	virtual int getTickingOffsets(void);
	virtual void moveView(void);
	virtual void setName(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void checkMovementStats(Vector3 const&);
	virtual __int64 getCurrentStructureFeature(void);
	virtual bool isAutoJumpEnabled(void);
	virtual void respawn(void);
	virtual void resetRot(void);
	virtual void resetPos(bool);
	virtual bool isInTrialMode(void);
	virtual void hasResource(int);
	virtual void completeUsingItem(void);
	virtual void setPermissions(class CommandPermissionLevel);
	virtual void startDestroying(void);
	virtual void stopDestroying(void);
	virtual void openPortfolio(void);
	virtual void openBook(int, bool, int, class BlockActor*);
	virtual void openTrading(uint64_t const&, bool);
	virtual bool canOpenContainerScreen(void);
	virtual void openChalkboard(class ChalkboardBlockActor&, bool);
	virtual void openNpcInteractScreen(); // removed
	virtual void openInventory(void);
	virtual void displayChatMessage(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void displayClientMessage(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void displayTextObjectMessage(class TextObjectRoot const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void displayTextObjectWhisperMessage(class ResolvedTextObject const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void displayWhisperMessage(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual void startSleepInBed(BlockPos const&);
	virtual void stopSleepInBed(bool, bool);
	virtual void canStartSleepInBed(void);
	virtual int getSleepTimer(void);
	virtual int getPreviousTickSleepTimer(void);
	virtual void openSign(BlockPos const&);
	virtual void playEmote(std::basic_string<char, std::char_traits<char>, std::allocator<char>> const&);
	virtual bool isHostingPlayer(void);
	virtual bool isLoading(void);
	virtual bool isPlayerInitialized(void);
	virtual void stopLoading(void);
	virtual void registerTrackedBoss(uint64_t);
	virtual void unRegisterTrackedBoss(uint64_t);
	virtual void setPlayerGameType(class GameType);
	virtual void initHUDContainerManager(void);
	virtual void _crit(Actor&);
	virtual __int64 getEventing(void);
	virtual int getUserId(void);
	virtual void sendEventPacket(class EventPacket&);
	virtual void addExperience(int);
	virtual void addLevels(int);
	// lp funcs
private:
	virtual void TryroFunc416();
	virtual void TryroFunc417();
public:
	virtual void inventoryChanged(uintptr_t Container, int, ItemStack const&, ItemStack const&, bool);
private:
	virtual void TryroFunc419();
public:
	virtual void deleteContainerManager(void);
	virtual void setFieldOfViewModifier(float);
	virtual bool is2DPositionRelevant();
	virtual bool isEntityRelevant(Actor const&);
private:
	virtual void TryroFunc424();
public:
	virtual void onSuspension(void);
	virtual void onLinkedSlotsChanged(void);
	virtual void startCooldown(__int64 const* Item);
	virtual int getItemCooldownLeft(void* hashedstring);
	virtual int getItemCooldownLeft(ULONG);
	virtual int getMaxItemCooldownLeft(void);
	virtual bool isItemInCooldown(void* hashedstring);
private:
	virtual void TryroFunc432();
	virtual void TryroFunc433();
public:
	virtual void sendNetworkPacket(void* Packet);
private:
	virtual void TryroFunc435();
	virtual void TryroFunc436();
	virtual void TryroFunc437();
	virtual void TryroFunc438();
public:
	virtual void reportMovementTelemetry(void* MovementEventType);
	virtual bool isSimulated(void);
	virtual TextHolder getXUID(void);
	virtual __int64 getMovementSettings(void);
	virtual void onMovePlayerPacketNormal(class Vector3 const&, class Vector2 const&, float);
	virtual void _createChunkSource(void* ChunkSource);

public:
	auto getRotations() { //
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("F2 ? ? 80 ? ? ? ? 48 8B C2 F2 ? ? 02 C3 CC CC CC CC CC CC CC CC CC CC CC CC 40 53 48 83 EC 20") + 4);
		return reinterpret_cast<Vector2*>((uintptr_t)(this) + offset);
	};

	auto getRotations2() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("F2 ? ? 80 ? ? ? ? 48 8B C2 F2 ? ? 02 C3 CC CC CC CC CC CC CC CC CC CC CC CC 40 53 48 83 EC 20") + 4);
		return reinterpret_cast<Vector2*>((uintptr_t)(this) + offset + 0x8);
	};

	auto getFallDistance() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("C7 83 ? ? ? ? ? ? ? ? 48 8B 4C 24 48") + 2);
		return reinterpret_cast<float*>((uintptr_t)(this) + offset);
	};

	auto onGround() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("C7 83 ? ? ? ? ? ? ? ? 48 8B 4C 24 48") + 2);
		return reinterpret_cast<bool*>((uintptr_t)(this) + offset + 0x4);
	};

	auto onGround2() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("C7 83 ? ? ? ? ? ? ? ? 48 8B 4C 24 48") + 2);
		return reinterpret_cast<bool*>((uintptr_t)(this) + offset + 0x5);
	};

	auto getSlowDown() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("41 89 80 ? ? ? ? 8B 42 04 41 89 80 ? ? ? ? 8B 42 08 41 89 80 ? ? ? ? C3 CC CC CC CC CC CC CC CC CC CC CC CC CC CC 48 8B 41 ? 48 05") + 3);
		return reinterpret_cast<Vector3*>((uintptr_t)(this) + offset);
	};

	auto getHurtTime() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("66 ? ? 80 ? ? ? ? ? ? C0 F3 ? ? 81") + 4);
		return reinterpret_cast<Vector3*>((uintptr_t)(this) + offset);
	};

	auto getBlocksTraveled() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("41 89 80 ? ? ? ? 8B 42 04 41 89 80 ? ? ? ? 8B 42 08 41 89 80 ? ? ? ? C3 CC CC CC CC CC CC CC CC CC CC CC CC CC CC 48 8B 41 ? 48 05") + 3);
		return reinterpret_cast<float*>((uintptr_t)(this) + offset + sizeof(Vector3));
	};

	auto getPosition() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("F3 ? ? 81 ? ? ? ? 41 ? ? 00") + 4);
		return reinterpret_cast<AABB*>((uintptr_t)(this) + offset);
	};

	auto getHitbox() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("F3 ? ? 81 ? ? ? ? 41 ? ? 00") + 4);
		return reinterpret_cast<Vector2*>((uintptr_t)(this) + offset + sizeof(AABB));
	};

	auto getCameraInformation() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("F3 ? ? 81 ? ? ? ? 41 ? ? 00") + 4);
		return reinterpret_cast<AABB*>((uintptr_t)(this) + offset + sizeof(AABB) + sizeof(Vector2));
	};

	auto getVelocity() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("F3 ? ? 81 ? ? ? ? 41 ? ? 00") + 4);
		return reinterpret_cast<Vector3*>((uintptr_t)(this) + offset + sizeof(AABB) + sizeof(Vector2) + sizeof(AABB));
	};

	auto getNormalVelocity() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("F3 ? ? 81 ? ? ? ? 41 ? ? 00") + 4);
		return reinterpret_cast<Vector3*>((uintptr_t)(this) + offset + sizeof(AABB) + sizeof(Vector2) + sizeof(AABB) + sizeof(Vector3));
	};

	auto bodyYaw() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("F3 ? ? 89 ? ? ? ? E9 ? ? ? ? CC CC CC CC CC CC CC CC F3") + 4);
		return reinterpret_cast<Vector2*>((uintptr_t)(this) + offset);
	};

	auto yawUnused1() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("F3 ? ? 89 ? ? ? ? E9 ? ? ? ? CC CC CC CC CC CC CC CC F3") + 4);
		return reinterpret_cast<Vector2*>((uintptr_t)(this) + offset + 0x8);
	};

	auto getSwingState() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("80 BB ? ? ? ? 00 74 1A FF 83") + 2);
		return reinterpret_cast<float*>((uintptr_t)(this) + offset);
	};

	auto getStepHeight() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("F3 ? ? 80 ? ? ? ? C3 CC CC CC 48 8B 41 10 88 90 ? ? ? ? C3 CC CC CC CC CC 48 8B 41 10 ? ? 80 ? ? ? ? C3 CC CC CC CC 48 8B 41 10") + 4);
		return reinterpret_cast<float*>((uintptr_t)(this) + offset);
	};

	auto getFieldOfView() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("F3 ? ? B3 ? ? ? ? ? ? C6 ? ? 74 24 40 48 83 C4 ? 5B") + 4);
		return reinterpret_cast<float*>((uintptr_t)(this) + offset);
	};

	auto getRawUsername() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("F3 ? ? 88 ? ? ? ? C3 CC CC CC 48 8B 41 10 F3 ? ? 80 ? ? ? ? C3 CC CC CC 48 8B 41 ? F3 ? ? 88 ? ? ? ? C3 CC CC CC 48 83") + 4);
		return reinterpret_cast<TextHolder*>((uintptr_t)(this) + offset + 0xC);
	};

	auto getStepInformation() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("F3 ? ? 80 ? ? ? ? C3 CC CC CC 48 8B 41 10 88 90 ? ? ? ? C3 CC CC CC CC CC 48 8B 41 10 ? ? 80 ? ? ? ? C3 CC CC CC CC 48 8B 41 10") + 4);
		return reinterpret_cast<Vector2*>((uintptr_t)(this) + offset);
	};

	auto eyePos0() {
		static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("89 81 ? ? ? ? 8B 81 ? ? ? ? 89 81 ? ? ? ? 8B 81 ? ? ? ? 89 81 ? ? ? ? 48 8B 89 ? ? ? ? 48 8B 01 FF 90 ? ? ? ? 48 8D 0D") + 2);
		return reinterpret_cast<Vector3*>((uintptr_t)(this) + offset);
	};

	//auto getHeight() {
	//	return reinterpret_cast<float*>((uintptr_t)(this) + 0x4D8);
	//};

	auto getHeight() {
		return getPosition()->upper.y;
	};

	auto damageTime() { // dont know where this is and im not opening reclass 2 find out
		return reinterpret_cast<int32_t*>((uintptr_t)(this) + 0x758);
	}

	//class BlockSource* region; //0x0360

public: // MainClasses
	auto getBlockSourcePtr() {
		return *reinterpret_cast<int*>(MCM::findSig("48 8B 86 ? ? ? ? 48 8B 48 20 48 8B 01 FF 90 ? ? ? ? 48 8D 98 ? ? ? ? 80 7B 70 00") + 3);
	};
	auto getDimensionPtr() {
		return getBlockSourcePtr() + 0x8;
	};
	auto getLevelPtr() {
		return getDimensionPtr() + 0x8;
	};

public: // other
	Vector3 getDirectionalVector(float x, float y) {
		Vector3 tempVec;

		tempVec.x = cos(x) * cos(y);
		tempVec.y = sin(y);
		tempVec.z = sin(x) * cos(y);

		return tempVec;
	} 

	Vector3 getLookingVector() {
		Vector3 tempVec;

		auto PI = 3.14159265359f;

		auto cYaw = (getRotations()->y + 89.9f) * PI / 178.f;
		auto cPitch = getRotations()->x * PI / 178.f;

		tempVec = getDirectionalVector(cYaw, cPitch);

		return tempVec;
	};
};