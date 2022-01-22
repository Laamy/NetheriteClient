#pragma once

struct Vector2 {
	union {
		struct {
			float x, y;
		};
		float arr[2];
	};

	Vector2(float x = 0, float y = 0) {
		this->x = x; this->y = y;
	};

	bool operator == (Vector2 v) { return v.x == x && v.y == y; };
	bool operator != (Vector2 v) { return v.x != x || v.y != y; };
	Vector2 operator *= (Vector2 v) { return Vector2(v.x * x, v.y * y); };
};