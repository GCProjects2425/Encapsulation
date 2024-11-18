#include "SDLWindow.h"
#include "SDLSprite.h"

SDLWindow::~SDLWindow()
{
    if (m_Renderer) {
        SDL_DestroyRenderer(m_Renderer);
    }
    if (m_Window) {
        SDL_DestroyWindow(m_Window);
    }
    IMG_Quit();
    SDL_Quit();
}

void SDLWindow::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
    }

    if (IMG_Init(IMG_INIT_PNG) == 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_image Initialization Error: %s", IMG_GetError());
    }
}

void SDLWindow::CreateWindow()
{
    if (SDL_CreateWindowAndRenderer(320, 240, SDL_WINDOW_RESIZABLE, &m_Window, &m_Renderer) < 0) 
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
    }
}

bool SDLWindow::IsWindowOpen()
{
    return false;
}

void SDLWindow::ClearWindow()
{
    if (SDL_RenderClear(m_Renderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't clear renderer: %s", SDL_GetError());
    }
}

void SDLWindow::DrawWindow()
{
    SDLSprite sdlSprite(m_Renderer);
    if (sdlSprite.LoadImage("resources\\sprite.png")) {
        SDL_Log("Image loaded!");
        sdlSprite.SetPosition(100, 200);
        SDL_Rect dstRect = { 100, 200, 250, 250 }; // Rectangle de destination
        SDL_RenderCopy(m_Renderer, static_cast<SDL_Texture*>(sdlSprite.GetData()), nullptr, &dstRect);
    }
    SDL_RenderPresent(m_Renderer);
}
