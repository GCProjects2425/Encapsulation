#include "SDLWindow.h"

SDLWindow::~SDLWindow()
{
    if (m_Renderer) {
        SDL_DestroyRenderer(m_Renderer);
    }
    if (m_Window) {
        SDL_DestroyWindow(m_Window);
    }
    SDL_Quit();
}

void SDLWindow::Init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
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
    SDL_RenderPresent(m_Renderer);
}
