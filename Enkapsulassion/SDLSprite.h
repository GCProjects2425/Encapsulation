#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Sprite.h"
class SDLSprite :
    public Sprite
{
public:
    SDLSprite(SDL_Renderer* renderer);
    ~SDLSprite();
    bool LoadImage(const char* fileName, int width, int height);
    void* GetData();
    void Render();

    void RandomColor();

private:
    SDL_Renderer* m_Renderer;
    SDL_Texture* m_Texture;
    SDL_Color m_Color;
};

