#pragma once
#include "Window.h"
#include "raylib.h"
#include "Sprite.h"

class RaylibWindow :
    public Window
{
public:
	RaylibWindow()
		: m_Window(NULL)
		, m_Renderer(NULL)
	{}

	~RaylibWindow();

	void Init();
	void CreateWindow();
	bool IsWindowOpen();
	void ClearWindow();
	void DrawWindow();

private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;
};

