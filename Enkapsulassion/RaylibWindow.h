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
	{}

	~RaylibWindow();

	void Init();
	void CreateWindow(int windowWidth, int windowHeight);
	void ClearWindow();
	void Update();
	void DrawWindow();
	Sprite* CreateSprite();

	bool IsKeyPressed(const std::string& key) override;

	void HandleEvent();

	void DrawFPSCounter();
};

