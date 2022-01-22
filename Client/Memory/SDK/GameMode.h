#pragma once

class ItemStack;
class InputMode;
class Actor;

class GameMode {
private:
	virtual void Construtor1();
	virtual void Construtor();
public:
	virtual void startDestroyBlock(Vector3i const&, byte, bool&);
	virtual void destroyBlock(Vector3i const&, byte);
	virtual void continueDestroyBlock(Vector3i const&, byte, Vector3 const&, bool&);
	virtual void stopDestroyBlock(Vector3i const&);
	virtual void startBuildBlock(Vector3i const&, byte);
	virtual void buildBlock(Vector3i const&, byte); // remove useless boolean
	virtual void continueBuildBlock(Vector3i const&, byte);
	virtual void stopBuildBlock(void);
	virtual void tick(void);
	virtual int getPickRange(InputMode const&, bool);
	virtual void useItem(ItemStack&);
	virtual void useItemOn(ItemStack&, Vector3i const&, byte, Vector3 const&, Block const*);
	virtual void interact(Actor&, Vector3 const&);
	virtual void attack(Actor&);
	virtual void releaseUsingItem(void);
	virtual void setTrialMode(bool);
	virtual bool isInTrialMode(void);
	//virtual void registerUpsellScreenCallback(std::function<void()(bool)>);
};