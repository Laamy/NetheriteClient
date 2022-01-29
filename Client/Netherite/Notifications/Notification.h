#pragma once

class Notification {
public:
	Notification(const char* text, float timer = 5) {
		this->text = text;
		this->timer = timer;
	};

	const char* text;
	float timer;
	int fade = 0;
};