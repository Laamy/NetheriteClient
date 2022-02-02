#pragma once

class UserEntityIdentifierComponent;
class NetworkIdentifierWithSubId;
class NetworkIdentifier;

class MemoryBytes {
public:
	char bytes[1980];
};

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

	auto getPacketSenderAddr() {
		static unsigned int offset1 = 0;
		static unsigned int offset2 = 8;
		static unsigned int offset3 = 0;

		return *reinterpret_cast<MemoryBytes**>(*reinterpret_cast<LoopbackSender**>(*reinterpret_cast<LoopbackSender**>((uintptr_t)(this) + offset3) + offset1) + offset2);
	};
};