#pragma once
#include "SDL.h"
#include "raylib.h"

class Window
{
public:
	Window() {}
	virtual ~Window() {};

	virtual void Init() = 0;
	virtual void CreateWindow() = 0;
	virtual bool IsWindowOpen() = 0;
	virtual void ClearWindow() = 0;
	virtual void DrawWindow() = 0;
};

