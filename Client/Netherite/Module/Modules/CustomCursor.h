#pragma once

class CustomCursor : public Module {
public:
	CustomCursor() : Module("CustomCursor", "Visual", "Displays a CustomCurser made for debugging", GameInput::KEY_NONE) {
	};

	void onThirdFrameRender(DrawUtils* renderer) override {
		if (clientInst->mcGame->canUseMoveKeys()) return;

		auto curCursor = CURSOR_STATE::CURSOR_PLUS;
		GameCursors::HandCursor(curCursor);
	};
};