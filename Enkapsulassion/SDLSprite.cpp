#include "SDLSprite.h"
#include <iostream>

SDLSprite::~SDLSprite()
{
    if (m_Texture) {
        SDL_DestroyTexture(m_Texture);
    }
}

bool SDLSprite::LoadImage(const char* fileName)
{
    SDL_Surface* surface = IMG_Load(fileName);
    if (!surface) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load IMAGE: %s", IMG_GetError());
        return false;
    }

    m_Texture = SDL_CreateTextureFromSurface(m_Renderer, surface);
    SDL_FreeSurface(surface);

    if (!m_Texture) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to create texture: %s", IMG_GetError());
        return false;
    }

    return true;
}

void* SDLSprite::GetData()
{
    return static_cast<void*>(m_Texture);
}
