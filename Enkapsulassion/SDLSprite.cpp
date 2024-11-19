#include "SDLSprite.h"
#include <iostream>

SDLSprite::SDLSprite(SDL_Renderer* renderer)
    : m_Renderer(renderer)
    , m_Texture(nullptr)
{
    m_Color.r = 255;
    m_Color.g = 255;
    m_Color.b = 255;
    m_Color.a = 255;
}

SDLSprite::~SDLSprite()
{
    if (m_Texture) {
        SDL_DestroyTexture(m_Texture);
    }
}

bool SDLSprite::LoadImage(const char* fileName, int width, int height)
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

    m_Width = width;
    m_Height = height;

    return true;
}

void* SDLSprite::GetData()
{
    return static_cast<void*>(m_Texture);
}

void SDLSprite::Render()
{
    if (!m_Texture) return;

    SDL_SetTextureColorMod(m_Texture, m_Color.r, m_Color.g, m_Color.b);
    SDL_Rect dstRect = { m_X, m_Y, 100, 50 };
    SDL_RenderCopy(m_Renderer, m_Texture, nullptr, &dstRect);
}

void SDLSprite::RandomColor()
{
    m_Color.r = rand() % 256;
    m_Color.g = rand() % 256;
    m_Color.b = rand() % 256;
}