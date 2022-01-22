#pragma once

struct UIColor {
	union {
		struct { float r, g, b, a; };
		float arr[4]{};
	};

	UIColor(const float r, const float g, const float b, const float a = 255) {
		this->r = r / 255.0f;
		this->g = g / 255.0f;
		this->b = b / 255.0f;
		this->a = a / 255.0f;
	};
};
