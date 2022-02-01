#pragma once

struct GLMatrix {
public:
	float matrix[16]; // W2S
	float matrix_nest[4][4]; // BobView
};