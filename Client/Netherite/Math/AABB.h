#pragma once

struct AABB {
	union {
		struct { Vector3 lower, upper; };
		Vector3 arr[2]{};
	};

	AABB(Vector3 position, Vector3 size) {
		this->upper.x = position.x;
		this->lower.x = position.x + size.x;
		this->upper.y = position.y;
		this->lower.y = position.y + size.y;
		this->upper.z = position.z;
		this->lower.z = position.z + size.z;
	};
};