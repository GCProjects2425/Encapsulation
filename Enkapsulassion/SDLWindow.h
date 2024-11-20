#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include "Window.h"
class SDLWindow :
    public Window
{
public:
	SDLWindow();

	~SDLWindow();

    void Init();
    void CreateWindow(int windowWidth, int windowHeight);
	void ClearWindow();
	void DrawWindow();

	void Update();
		
	void HandleEvent();

	void DrawFPSCounter();

	Sprite* CreateSprite();

	void StartFrame() override;
	void EndFrame() override;

private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	SDL_Event m_Event;
	TTF_Font* m_Font;

	Uint64 m_LastTime;
	Uint32 m_FrameStart;
	float m_FrameTime;
};


