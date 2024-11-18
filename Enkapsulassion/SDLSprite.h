#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Sprite.h"
class SDLSprite :
    public Sprite
{
public:
    SDLSprite(SDL_Renderer* renderer) : m_Renderer(renderer), m_Texture(nullptr) {}
    ~SDLSprite();
    bool LoadImage(const char* fileName);
    void* GetData();

private:
    SDL_Renderer* m_Renderer;
    SDL_Texture* m_Texture;
};

