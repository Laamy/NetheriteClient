#pragma once

class DIDChanger : public Module {
public:
	DIDChanger() : Module("DIDChanger", "Exploit", "Change your games DeviceID to bypass DID bans (Nethergames)", GameInput::KEY_NONE) {};

	void onEnable() override {
		DeviceIDGenerator::ChangeDeviceID(renderer->getCurrentMs());
	}
};