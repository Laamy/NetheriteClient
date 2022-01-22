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
public:
    virtual float getLineLength(class BitmapFont* font, TextHolder* text, float textSize);
private:
    virtual float getTextAlpha();
    virtual void setTextAlpha(float alpha);
public:
    virtual void drawDebugText(const float* pos, TextHolder* text, float* color, float alpha, unsigned int textAlignment, const float* textMeasureData, const void* caretMeasureData);
    virtual void drawText(BitmapFont* font, Vector4* position, TextHolder* text, UIColor color, float alpha, unsigned int* textAlignment, const TextMeasureData textMeasureData, const CaretMeasureData* caretMeasureData);
    virtual void flushText(float timeSinceLastFlush);
    virtual void drawImage(class TexturePtr* const& texture, Vector4 _1, Vector4 _2, Vector4 _3, Vector4 _4);
private:
    virtual void drawNineslice(class TexturePtr* const& texturePtr, void* nineslice);
    virtual void flushImages(float timeSinceLastFlush);
    virtual void beginSharedMeshBatch(uintptr_t ComponentRenderBatch);
    virtual void endSharedMeshBatch(float timeSinceLastFlush);
public:
    virtual void drawRectangle(Vector4 position, UIColor color, float alpha, int lineWidth);
    virtual void fillRectangle(Vector4 position, UIColor color, float alpha);
private:
    virtual void increaseStencilRef();
    virtual void decreaseStencilRef();
    virtual void resetStencilRef();
    virtual void fillVector4angleStencil(Vector4 position);
    virtual void enableScissorTest(Vector4 position);
    virtual void disableScissorTest();
    virtual void setClippingVector4angle(Vector4 position);
    virtual void setFullClippingVector4angle();
    virtual void saveCurrentClippingVector4angle();
    virtual void restoreSavedClippingVector4angle();
    virtual int getFullClippingVector4angle();
    virtual void updateCustom(uintptr_t a1);
    virtual void renderCustom(uintptr_t a1, int a2, Vector4 position);
    virtual void cleanup();
    virtual void removePersistentMeshes();
public:
    virtual int getTexture(class TexturePtr* ResourceLocation, bool a2);
    virtual int getZippedTexture(class TexturePtr* Path, class TexturePtr* ResourceLocation, bool a3);
};