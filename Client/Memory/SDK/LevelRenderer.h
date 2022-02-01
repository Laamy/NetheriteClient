#pragma once

class LevelRenderer {
public:
	auto getOrigin() { //0x878
		//static unsigned int offset = *reinterpret_cast<int*>(MCM::findSig("") + 3);
		return *reinterpret_cast<Vector3*>((uintptr_t)(this) + 0x878);
	};
};