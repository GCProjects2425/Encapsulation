#pragma once
#include "Sprite.h"
#include "raylib.h"
class RaylibSprite :
    public Sprite
{
public:
    RaylibSprite() {}
    ~RaylibSprite();
    bool LoadImage(const char* fileName);
    void* GetData();
    void Render();
private:
    Texture2D texture;
};

