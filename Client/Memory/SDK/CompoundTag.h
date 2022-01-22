#pragma once

class CompoundTag {
public:
	void writeNBTString(TextHolder target, TextHolder value) {
		typedef void(__thiscall* putString)(CompoundTag*, TextHolder, TextHolder);
		static putString putFunc;

		uintptr_t sig = MCM::findSig("");
		putFunc = reinterpret_cast<putString>(sig + (*(int*)sig + 1) + 5);

		return putFunc(this, target, value);
	}

	void writeNBTFloat(TextHolder target, float value) {
		typedef void(__thiscall* putFloat)(CompoundTag*, TextHolder, float);
		static putFloat putFunc;

		uintptr_t sig = MCM::findSig("");
		putFunc = reinterpret_cast<putFloat>(sig + (*(int*)sig + 1) + 5);

		return putFunc(this, target, value);
	}

	void writeNBTByte(TextHolder target, byte value) {
		typedef void(__thiscall* putByte)(CompoundTag*, TextHolder, byte);
		static putByte putFunc;

		uintptr_t sig = MCM::findSig("");
		putFunc = reinterpret_cast<putByte>(sig + (*(int*)sig + 1) + 5);

		return putFunc(this, target, value);
	}

	void writeNBTShort(TextHolder target, short value) {
		typedef void(__thiscall* putShort)(CompoundTag*, TextHolder, short);
		static putShort putFunc;

		uintptr_t sig = MCM::findSig("");
		putFunc = reinterpret_cast<putShort>(sig + (*(int*)sig + 1) + 5);

		return putFunc(this, target, value);
	}

	void writeNBTInt(TextHolder target, int value) {
		typedef void(__thiscall* putInt)(CompoundTag*, TextHolder, int);
		static putInt putFunc;

		uintptr_t sig = MCM::findSig("");
		putFunc = reinterpret_cast<putInt>(sig + (*(int*)sig + 1) + 5);

		return putFunc(this, target, value);
	}
};