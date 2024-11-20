#include "RaylibWindow.h"

RaylibWindow::~RaylibWindow()
{
}

void RaylibWindow::Init()
{
}

void RaylibWindow::CreateWindow(int windowWidth, int windowHeight)
{
	InitWindow(windowWidth, windowHeight, "LE DVD QUI REBONDI HAHA - raylib");
	SetWindowState(FLAG_WINDOW_RESIZABLE);
	m_WindowHeight = windowHeight;
	m_WindowWidth = windowWidth;
	m_IsOpen = true;
	SetTargetFPS(m_TargetFps);
}

void RaylibWindow::ClearWindow()
{
	BeginDrawing();
	ClearBackground(BLACK);
}

void RaylibWindow::Update()
{
	m_DeltaTime = GetFrameTime();
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
		m_WindowWidth = GetScreenWidth();
		m_WindowHeight = GetScreenHeight();
	}
}

void RaylibWindow::DrawFPSCounter()
{
	DrawFPS(10, 10);
}

