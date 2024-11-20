#pragma once
#include "Window.h"
class SDLWindow :
    public Window
{
public:
	SDLWindow()
		: m_Window(NULL)
		, m_Renderer(NULL)
		, m_Event()
	{}

	~SDLWindow();

    void Init();
    void CreateWindow(int windowWidth, int windowHeight);
	void ClearWindow();
	void DrawWindow();

	void HandleEvent();

	Sprite* CreateSprite();

	SDL_Renderer* GetRenderer() { return m_Renderer; }

private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	SDL_Event m_Event;
};


