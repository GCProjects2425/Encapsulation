#pragma once
#include "Window.h"
class SDLWindow :
    public Window
{
public:
	SDLWindow()
		: m_Window(NULL)
		, m_Renderer(NULL)
	{}

	~SDLWindow();

    void Init();
    void CreateWindow();
	bool IsWindowOpen();
	void ClearWindow();
	void DrawWindow();

private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
};


