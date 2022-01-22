#pragma once

class HIDController {
private:
	char pad_0x0000[0x50];  //0x0000
public:
	// 0x4B, // inMenu
	bool leftClickDown;   //0x0050
	bool rightClickDown;  //0x0051
	bool wheelDown;       //0x0052
	// 0x13E, // eKeymap
};