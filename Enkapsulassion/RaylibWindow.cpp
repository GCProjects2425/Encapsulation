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

bool RaylibWindow::IsKeyPressed(const std::string& key)
{
	if (key == "Z") return RAYLIB_H::IsKeyDown(KEY_W);
	if (key == "S") return RAYLIB_H::IsKeyDown(KEY_S);
	if (key == "UP") return RAYLIB_H::IsKeyDown(KEY_UP);
	if (key == "DOWN") return RAYLIB_H::IsKeyDown(KEY_DOWN);
	return false;
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

