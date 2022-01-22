#pragma once

enum CURSOR_STATE {
	CURSOR_NONE, // no cursor
	CURSOR_PLUS, // + cursor
	CURSOR_MOUSE // o mouse cursor
};

class GameCursors {
public:
	static const void HandRenderer(DrawUtils* rend) {
		renderer = rend;
	};

	static const auto getCursorPos() {
		Vector2 scaledPos = clientInst->getGuiData()->scaledMousePos();

		scaledPos.x -= 2;
		scaledPos.y -= 4.5;

		return scaledPos;
	};

	static const void HandCursor(CURSOR_STATE cursor) {
		Vector2 scaledPos = getCursorPos();

		switch (cursor)
		{
		case CURSOR_STATE::CURSOR_PLUS:
			renderer->drawText(scaledPos,
				UIColor(255, 255, 255, 200), TextHolder("+"), GameInput::UI_TEXT_DEFAULT);
			break;
		case CURSOR_STATE::CURSOR_MOUSE:
			renderer->drawText(scaledPos,
				UIColor(255, 255, 255, 200), TextHolder("+"), GameInput::UI_TEXT_DEFAULT);
			renderer->drawText(scaledPos,
				UIColor(255, 255, 255, 200), TextHolder("o"), GameInput::UI_TEXT_DEFAULT);
			break;
		}
	};
};