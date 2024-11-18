#pragma once
#include "Sprite.h"
class SDLSprite :
    public Sprite
{
    void LoadImage(const char* fileName);
    int GetData();
};

