#include "RaylibWindow.h"

RaylibWindow::~RaylibWindow()
{
}

void RaylibWindow::Init()
{
}

void RaylibWindow::CreateWindow(int windowWidth, int windowHeight)
{
	InitWindow(windowWidth, windowHeight, "raylib [core] example - basic window");
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	m_WindowHeight = windowHeight;
	m_WindowWidth = windowWidth;
	m_IsOpen = true;
	SetTargetFPS(60);
}

void RaylibWindow::ClearWindow()
{
	BeginDrawing();
	ClearBackground(BLACK);
}

void RaylibWindow::DrawWindow()
{
	EndDrawing();
}

Sprite* RaylibWindow::CreateSprite()
{
	Sprite* sprite = new RaylibSprite();
	return sprite;
}

void RaylibWindow::HandleEvent()
{
	if (WindowShouldClose())
		m_IsOpen = false;
	if (IsWindowResized()) {
		int newWidth = GetScreenWidth();
		int newHeight = GetScreenHeight();
	}
}

