#pragma once

static constexpr float DEG_RAD = 180.0f / 3.1415927f;

struct Vector3 {
	union {
		struct {
			float x, y, z;
		};
		float arr[3];
	};

	Vector3(float x = 0, float y = 0, float z = 0) {
		this->x = x; this->y = y; this->z = z;
	};

	bool operator == (Vector3 v) { return v.x == x && v.y == y && v.z == z; };
	bool operator != (Vector3 v) { return v.x != x || v.y != y || v.z != z; };
	Vector3 operator *= (Vector3 v) { return Vector3(v.x * x, v.y * y, v.z * z); };
	Vector3 submissive(const Vector3& o) const { return Vector3(x - o.x, y - o.y, z - o.z); }
	float squaredlen() const { return x * x + y * y; }
	float magnitude() const { return sqrtf(squaredlen()); }
	float magnitudexy() const { return sqrtf(x * x + y * y); }
	float magnitudexz() const { return sqrtf(x * x + z * z); } // Totally not skidded

	Vector3 lerp(const Vector3& pos, float x1, float y1, float z1) {
		Vector3 This;
		This.x = x + x1 * (pos.x - x);
		This.y = y + y1 * (pos.y - y);
		This.z = z + z1 * (pos.z - z);
		return This;
	}

	float distance(Vector3 v) {
		float dX = x - v.x;
		float dY = y - v.y;
		float dZ = z - v.z;
		return std::sqrt(dX * dX + dY * dY + dZ * dZ);
	}

	const static Vector2 CalcAngle(Vector3 ths, Vector3 dst) {
		Vector3 diff = dst.submissive(ths);

		diff.y = diff.y / diff.magnitude();
		Vector2 angles;
		angles.x = asinf(diff.y) * -DEG_RAD;
		angles.y = (float)-atan2f(diff.x, diff.z) * DEG_RAD;

		return angles;
	}
};