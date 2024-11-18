#pragma once
#include "SDL.h"
#include "Sprite.h"
class SDLSprite :
    public Sprite
{
public:
    SDLSprite(SDL_Renderer* renderer) : m_Renderer(renderer), m_Texture(nullptr) {}
    ~SDLSprite();
    void LoadImage(const char* fileName);
    void* GetData();

private:
    SDL_Renderer* m_Renderer;
    SDL_Texture* m_Texture;
};

