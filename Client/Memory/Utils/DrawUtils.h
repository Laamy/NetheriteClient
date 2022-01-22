#pragma once

class DrawUtils
{
public:
	MinecraftUIRenderContext* ctx;
	GuiData* guiData;
	BitmapFont* font;
	float* colorHolder;

	bool hasShadow = false;

	void Init(MinecraftUIRenderContext* ctx, GuiData* guiData, BitmapFont* font) {
		this->ctx = ctx;
		this->guiData = guiData;
		this->font = font;

	};

	auto MeasureText(const char* text, float scale) {

		auto stdTrans = std::string(text);
		auto textHolder = TextHolder(stdTrans);

		auto measureData = ctx->getLineLength(font, &textHolder, scale);

		return measureData;
	};

	void drawBackground(UIColor color) {
		auto position = Vector2(0, 0);
		auto size = guiData->scaledResolution;
		auto rectangle = Vector4(position, size);

		ctx->fillRectangle(rectangle, color, color.a);
	};

	void ClearSides(UIColor color, float width = 16.f) { // didnt finish this btw
		auto position = Vector2(0, 0);
		auto size = guiData->scaledResolution;
		auto rectangle = Vector4(position, size);

		ctx->drawRectangle(rectangle, color, color.a, width);
	};

	auto getShadow() {
		return hasShadow;
	};

	auto setShadow(bool shadow) {
		hasShadow = shadow;
	};

	bool isMouseInRect(Vector4 pos, Vector2 mousePos)
	{
		if (pos.x < mousePos.x && pos.y < mousePos.y && pos.z > mousePos.x && pos.w > mousePos.y)
			return true;
		return false;
	}

	std::map<uintptr_t, bool> DrawButtonText(Vector2 position, Vector2 size, UIColor textColor, UIColor hovercolor, UIColor heldcolor, Vector2 curMousePos, bool held, bool rightHeld, TextHolder text, float scale, bool enabled = false) {
		std::map<uintptr_t, bool> toReturn;
		toReturn[0] = false;
		toReturn[1] = false;

		auto rect = Vector4(position.x, position.x + size.x, position.y, position.y + size.y);
		if (curMousePos.x < rect.x && curMousePos.x > rect.w && curMousePos.y < rect.z && curMousePos.y > rect.y) {
			if (!held)
				ctx->fillRectangle(rect, hovercolor, hovercolor.a);
			else {
				ctx->fillRectangle(rect, heldcolor, heldcolor.a);
				toReturn[0] = true;
			}

			if (rightHeld)
				toReturn[1] = true;

			auto dimedTextClr = textColor;
			dimedTextClr.r -= 11;
			dimedTextClr.g -= 11;
			dimedTextClr.b -= 11;

			drawText(Vector2(position.x, position.y), dimedTextClr, text, scale);
		}
		else {
			if (enabled) {
				ctx->fillRectangle(rect, heldcolor, heldcolor.a);
				drawText(Vector2(position.x, position.y), textColor, text, scale);
			}
			else
			{
				ctx->fillRectangle(rect, hovercolor, heldcolor.a);
				drawText(Vector2(position.x, position.y), textColor, text, scale);
			}
		}

		return toReturn;
	}

	void fillRectangle(Vector2 position, Vector2 size, UIColor color, float alpha) {
		auto rectangle = Vector4(position, size);

		ctx->fillRectangle(rectangle, color, alpha);
	};

	float getTextWidth(std::string* textStr, float textSize) {

		TextHolder text(*textStr);

		float ret = ctx->getLineLength(font, &text, textSize);

		return ret;
	};

	void setColor(float r, float g, float b, float a) {
		colorHolder[0] = r;
		colorHolder[1] = g;
		colorHolder[2] = b;
		colorHolder[3] = a;
		*reinterpret_cast<uint8_t*>(colorHolder + 4) = 1;
	}


	void drawText(Vector2 position, UIColor color, TextHolder text, float measureCalc) {

		auto size = Vector2(1000, 1000); // apply textbox size
		auto rectangle = Vector4(position, size); // calculate rectangle area
		auto caretData = CaretMeasureData(); // empty caret data

		ctx->drawText(font, &rectangle, &text, color, color.a, nullptr, TextMeasureData(&measureCalc, hasShadow), &caretData);
		ctx->flushText(0);
	};

	// from imgui
	static inline float ImFmod(float x, float y) { return fmodf(x, y); }
	static inline void hsvToRGB(float h, float s, float v, float& out_r, float& out_g, float& out_b) {
		if (s == 0.0f) {
			out_r = out_g = out_b = v;
			return;
		}
		h = ImFmod(h, 1.0f) / (60.0f / 360.0f);
		int i = (int)h;
		float f = h - (float)i;
		float p = v * (1.0f - s);
		float q = v * (1.0f - s * f);
		float t = v * (1.0f - s * (1.0f - f));
		switch (i) {
		case 0:
			out_r = v;
			out_g = t;
			out_b = p;
			break;
		case 1:
			out_r = q;
			out_g = v;
			out_b = p;
			break;
		case 2:
			out_r = p;
			out_g = v;
			out_b = t;
			break;
		case 3:
			out_r = p;
			out_g = q;
			out_b = v;
			break;
		case 4:
			out_r = t;
			out_g = p;
			out_b = v;
			break;
		case 5:
		default:
			out_r = v;
			out_g = p;
			out_b = q;
			break;
		}
	}

	// Returns the current millisecond ( from stack overflow )
	__int64 getCurrentMs() {
		FILETIME f;
		GetSystemTimeAsFileTime(&f);
		(long long)f.dwHighDateTime;
		__int64 nano = ((__int64)f.dwHighDateTime << 32LL) + (__int64)f.dwLowDateTime;
		return (nano - 116444736000000000LL) / 10000;
	}

	// Gets HSV color by current MS
	UIColor getRainbow(float speedInSeconds, float s, float v)
	{
		float hue = ((getCurrentMs()) % (int)(((int)speedInSeconds) * 700)) / (float)(((int)speedInSeconds) * 700);
		float r, g, b = 0;
		hsvToRGB(hue, s, v, r, g, b);
		return UIColor(r * 255, g * 255, b * 255, 255);
	}
	UIColor getRainbow(float speedInSeconds, float s, float v, long index)
	{
		float hue = ((getCurrentMs() + index) % (int)(((int)speedInSeconds) * 1000)) / (float)(((int)speedInSeconds) * 1000);
		float r, g, b = 0;
		hsvToRGB(hue, s, v, r, g, b);
		return UIColor(r * 255, g * 255, b * 255, 255);
	}
};