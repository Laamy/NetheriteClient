#pragma once
#include <cstdint>

class Packet {
    uintptr_t** vTable;  //0x0000
	template <class T>
	bool instanceOf() {
		T packet;
		return (packet.VTable == this->VTable);
	}
};