#pragma once
#include <cstdint>

class Packet {
    uintptr_t** vTable;
	template <class T>
	bool instanceOf() {
		T packet;
		return (packet.VTable == this->vTable);
	}
};