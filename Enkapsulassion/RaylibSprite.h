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
    void Draw();
    void* GetData();
private:
    Texture2D texture;
};

