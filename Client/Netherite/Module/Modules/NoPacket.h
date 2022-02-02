#pragma once

class NoPacket : public Module {
public:
	NoPacket() : Module("NoPacket", "Exploit", "Debugging example", GameInput::KEY_NONE) {}

	void onEnable() override {
		//clientInst->stopSendingPackets();
	}

	void onDisable() override {
		//clientInst->startSendingPackets();
	}
};