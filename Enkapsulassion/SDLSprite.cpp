#include "SDLSprite.h"

SDLSprite::~SDLSprite()
{
    if (m_Texture) {
        SDL_DestroyTexture(m_Texture);
    }
}

void SDLSprite::LoadImage(const char* fileName)
{
    m_Texture = img8

    return true;
}