#pragma once

struct Vector3i {
	union {
		struct {
			int x, y, z;
		};
		int arr[3];
	};

	Vector3i(int x = 0, int y = 0, int z = 0) {
		this->x = x; this->y = y; this->z = z;
	};

	bool operator == (Vector3i v) { return v.x == x && v.y == y && v.z == z; };
	bool operator != (Vector3i v) { return v.x != x || v.y != y || v.z != z; };

	Vector3 floor() {
		return Vector3(floorf(x), floorf(y), floorf(z));
	};
};
