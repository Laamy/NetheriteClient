#pragma once

#include <cstdint>

struct TextMeasureData {
public:
    TextMeasureData(float* size, bool showShadow) {
        this->textSize = *size; // Okay not useless ;-;
        this->showShadow = showShadow;
        this->idfkwhatthisiscalled = 0;
        this->idfkWhatThisIs = false;
    };

public:
    float textSize;
    int idfkwhatthisiscalled;
    bool showShadow;
    bool idfkWhatThisIs;
};

class MinecraftUIRenderContext {
private:
    virtual auto Constructor() -> void {};
    virtual auto unknown1() -> void {};
public:
    virtual float getLineLength(class BitmapFont* font, TextHolder* text, float textSize);
    virtual float getTextAlpha();
    virtual void setTextAlpha(float alpha);
    virtual void drawDebugText(const float* pos, TextHolder* text, float* color, float alpha, unsigned int textAlignment, const float* textMeasureData, const void* caretMeasureData);
    virtual void drawText(BitmapFont* font, Vector4* position, TextHolder* text, UIColor color, float alpha, unsigned int* textAlignment, const TextMeasureData textMeasureData, const CaretMeasureData* caretMeasureData);
    virtual void drawImage(class TexturePtr* const& texture, Vector4 _1, Vector4 _2, Vector4 _3, Vector4 _4);
    virtual void drawNineslice(class TexturePtr* const& texturePtr, void* nineslice);
    virtual void flushImages(float timeSinceLastFlush);
    virtual void beginSharedMeshBatch(uintptr_t ComponentRenderBatch);
    virtual void endSharedMeshBatch(float timeSinceLastFlush);
    virtual void drawRectangle(Vector4 position, UIColor color, float alpha, int lineWidth);
    virtual void fillRectangle(Vector4 position, UIColor color, float alpha);
    virtual void flushText(float timeSinceLastFlush);
};