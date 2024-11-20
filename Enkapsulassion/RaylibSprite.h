#pragma once
#include "Sprite.h"
#include "raylib.h"
class RaylibSprite :
    public Sprite
{
public:
    RaylibSprite()
        : texture()
        , m_Color(WHITE)
    {}
    ~RaylibSprite();
    bool LoadImage(const char* fileName,int width, int height);
    void* GetData();
    void Render();
    void RandomColor();
private:
    Texture2D texture;
    Color m_Color;
};

