#pragma once

class UserEntityIdentifierComponent;
class NetworkIdentifierWithSubId;
class NetworkIdentifier;

class LoopbackSender {
private:
	virtual void Destructor();
	virtual void sendToServer(Packet&);

public:
	auto getVTable() {
		return reinterpret_cast<uintptr_t**>(this);
	}

	auto getSendPacketAddr() {
		return getVTable()[1];
	}
};