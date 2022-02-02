#pragma once

class TimerCls {
public: // funcs
	auto getTimer() {
		return reinterpret_cast<float*>((uintptr_t)(this) + 0);
	};
};