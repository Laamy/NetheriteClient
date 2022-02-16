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
private:
    virtual int getTextAlpha();
    virtual void setTextAlpha();
    virtual void drawDebugText();
public:
    virtual void drawText(BitmapFont&, Vector4 const&, TextHolder, UIColor const&, float, float alinM, TextMeasureData const&, CaretMeasureData const&);
    virtual void flushText(float);
private:
    virtual void drawImage();
    virtual void drawNineslice();
    virtual void flushImages();
    virtual void beginSharedMeshBatch();
    virtual void endSharedMeshBatch();
public:
    virtual void drawRectangle(Vector4 const& rect, UIColor const& colour, float alpha, int width);
    virtual void fillRectangle(Vector4 const& rect, UIColor const& colour, float alpha);
};