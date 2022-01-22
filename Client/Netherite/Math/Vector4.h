#pragma once

struct Vector4 {
	union {
		struct {
			float w, x, y, z;
		};
		float arr[3];
	};

	Vector4(float w = 0, float x = 0, float y = 0, float z = 0) {
		this->w = w;
		this->x = x;
		this->y = y;
		this->z = z;
	};

	Vector4(Vector2 position, Vector2 size) {
		this->w = position.x;
		this->x = position.x + size.x;
		this->y = position.y;
		this->z = position.y + size.y;
	};

	bool operator == (Vector4 v) { return v.w == w && v.x == x && v.y == y && v.z == z; };
	bool operator != (Vector4 v) { return v.w != w || v.x != x || v.y != y || v.z != z; };
};