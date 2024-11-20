#include "SDLWindow.h"
#include "SDLSprite.h"
#include <memory>

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

void SDLWindow::CreateWindow(int windowWidth, int windowHeight)
{
    if (SDL_CreateWindowAndRenderer(windowWidth, windowHeight, SDL_WINDOW_RESIZABLE, &m_Window, &m_Renderer) < 0) 
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
    }
    m_WindowWidth = windowWidth;
    m_WindowHeight = windowHeight;
    m_IsOpen = true;
}

void SDLWindow::ClearWindow()
{
    SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
    if (SDL_RenderClear(m_Renderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't clear renderer: %s", SDL_GetError());
    }
}

void SDLWindow::DrawWindow()
{
    SDL_RenderPresent(m_Renderer);
    //SDL_Delay(16);
}

void SDLWindow::HandleEvent()
{
    while (SDL_PollEvent(&m_Event)) {
        if (m_Event.type == SDL_QUIT) 
        {
            m_IsOpen = false;
        }
        if (m_Event.type == SDL_WINDOWEVENT && m_Event.window.event == SDL_WINDOWEVENT_RESIZED)
        {
            m_WindowWidth  = m_Event.window.data1;
            m_WindowHeight = m_Event.window.data2;
        }
    }
}

Sprite* SDLWindow::CreateSprite()
{
    SDLSprite* ball = new SDLSprite(m_Renderer);
    if (ball->LoadImage("resources\\logo-dvd.png", 100, 50)) {
        SDL_Log("Image loaded!");
    }
    return std::move(ball);
}
