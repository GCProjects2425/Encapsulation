#include "SDLWindow.h"
#include "SDLSprite.h"
#include <string>
#include <memory>

SDLWindow::SDLWindow()
    : m_Window(NULL)
    , m_Renderer(NULL)
    , m_Font(NULL)
    , m_Event()
    , m_LastTime(SDL_GetPerformanceCounter())
    , m_FrameStart(0)
    , m_FrameTime(0.0f)
{
}

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

    if (TTF_Init() == 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_ttf Initialization Error: %s", TTF_GetError());
    }
}

void SDLWindow::CreateWindow(int windowWidth, int windowHeight)
{
    if (SDL_CreateWindowAndRenderer(windowWidth, windowHeight, SDL_WINDOW_RESIZABLE | SDL_WINDOW_SHOWN, &m_Window, &m_Renderer) < 0)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
    }
    SDL_SetWindowTitle(m_Window, "LE DVD QUI REBONDI HAHA - SDL");
    m_WindowWidth = windowWidth;
    m_WindowHeight = windowHeight;
    m_IsOpen = true;

    m_Font = TTF_OpenFont("resources\\basic_font.ttf", 10);
    if (!m_Font) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to load font:  %s", TTF_GetError());
    }
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

void SDLWindow::Update()
{
    Uint64 currentTime = SDL_GetPerformanceCounter();
    m_DeltaTime = static_cast<float>(currentTime - m_LastTime) / SDL_GetPerformanceFrequency();
    m_LastTime = currentTime;
}

void SDLWindow::HandleEvent()
{
    while (SDL_PollEvent(&m_Event)) {
        switch (m_Event.type)
        {
        case SDL_QUIT:
            m_IsOpen = false;
            break;
        case SDL_WINDOWEVENT:
        {
            switch (m_Event.window.event)
            {
            case SDL_WINDOWEVENT_RESIZED:
            {
                m_WindowWidth  = m_Event.window.data1;
                m_WindowHeight = m_Event.window.data2;
                break;
            }
            default:
                break;
            }
            break;
        }
        case SDL_KEYDOWN: 
        {
            switch (m_Event.key.keysym.sym)
            {
            default:
                break;
            }
        }
        default:
            break;
        }
    }
}

void SDLWindow::DrawFPSCounter()
{
    std::string fpsText = "FPS: " + std::to_string(1.f/m_DeltaTime);
    SDL_Color color = { 0, 255, 0, 255 };

    SDL_Surface* surface = TTF_RenderText_Solid(m_Font, fpsText.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(m_Renderer, surface);

    SDL_Rect rect = { 10, 10, surface->w, surface->h };
    SDL_RenderCopy(m_Renderer, texture, nullptr, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

Sprite* SDLWindow::CreateSprite()
{
    SDLSprite* ball = new SDLSprite(m_Renderer);
    return ball;
}

bool SDLWindow::IsKeyPressed(const std::string& key)
{
    const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
    if (key == "Z") return currentKeyStates[SDL_SCANCODE_W];
    if (key == "S") return currentKeyStates[SDL_SCANCODE_S];
    if (key == "UP") return currentKeyStates[SDL_SCANCODE_UP];
    if (key == "DOWN") return currentKeyStates[SDL_SCANCODE_DOWN];
    return false;
}

void SDLWindow::StartFrame()
{
    m_FrameStart = SDL_GetTicks();
}

void SDLWindow::EndFrame()
{
    m_FrameTime = SDL_GetTicks() - m_FrameStart;

    if (m_FrameTime < m_FrameDelay) {
        SDL_Delay(static_cast<Uint32>((m_FrameDelay)-m_FrameTime));
    }
}
