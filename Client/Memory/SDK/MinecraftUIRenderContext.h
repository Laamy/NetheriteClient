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

class ComponentRenderBatch;
class NinesliceInfo;
class HashedString;

class MinecraftUIRenderContext {
private:
    virtual void Destructor();
public:
    virtual float getLineLength(BitmapFont&, TextHolder const& txt, float measureCalc, bool a4);
    virtual int getTextAlpha(void);
    virtual void setTextAlpha(float);
    virtual void drawDebugText();
    virtual void drawText(BitmapFont&, Vector4 const&, TextHolder, UIColor const&, float, float alinM, TextMeasureData const&, CaretMeasureData const&);
    virtual void flushText(float);
    virtual void drawImage(uintptr_t const&, glm::tvec2<float, (glm::precision)0> const&, glm::tvec2<float, (glm::precision)0> const&, glm::tvec2<float, (glm::precision)0> const&, glm::tvec2<float, (glm::precision)0> const&);
    virtual void drawNineslice(uintptr_t const& a1, NinesliceInfo const& a2);
    virtual void flushImages(UIColor const& a1, float a2, HashedString const& a3);
    virtual void beginSharedMeshBatch(ComponentRenderBatch& a1);
    virtual void endSharedMeshBatch(ComponentRenderBatch& a1);
    virtual void drawRectangle(Vector4 const& rect, UIColor const& colour, float alpha, int width);
    virtual void fillRectangle(Vector4 const& rect, UIColor const& colour, float alpha);
};