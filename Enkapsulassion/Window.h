#pragma once
#include "SDL.h"
#include "raylib.h"
#include "Sprite.h"

class Window
{
public:
	Window() : m_WindowWidth(0), m_WindowHeight(0), m_IsOpen(false), m_IsFullScreen(false) {}
	virtual ~Window() {};

	virtual void Init() = 0;
	virtual void CreateWindow(int windowWidth, int windowHeight) = 0;
	virtual bool IsWindowOpen() { return m_IsOpen; };
	virtual void ClearWindow() = 0;
	virtual void DrawWindow() = 0;
	virtual Sprite* CreateSprite() = 0;

	virtual void HandleEvent() = 0;

	const int GetWidth() const { return m_WindowWidth;  }
	const int GetHeight() const { return m_WindowHeight; }

protected:
	int m_WindowWidth;
	int m_WindowHeight;

	bool m_IsOpen;
	bool m_IsFullScreen;
};

