#pragma once

struct CaretMeasureData {
	int a;
	bool b;

	CaretMeasureData() {
		CaretMeasureData(0xFFFFFFFF, true);
	};
	CaretMeasureData(int a1, bool a2) {
		this->a = a1;
		this->b = a2;
	};
};