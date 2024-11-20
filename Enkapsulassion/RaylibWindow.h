#pragma once
#include "Window.h"
#include "raylib.h"
#include "Sprite.h"
#include "RaylibSprite.h"

class RaylibWindow :
    public Window
{
public:
	RaylibWindow()
		: m_Window(NULL)
		, m_Renderer(NULL)
		, m_Event()
		, Window()
	{}

	~RaylibWindow();

	void Init();
	void CreateWindow(int windowWidth, int windowHeight);
	void ClearWindow();
	void DrawWindow();
	Sprite* CreateSprite() ;

	void HandleEvent();

	SDL_Renderer* GetRenderer() { return m_Renderer; }

private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	SDL_Event m_Event;
};

