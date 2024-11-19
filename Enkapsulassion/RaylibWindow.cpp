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
	SetTargetFPS(60);
}

bool RaylibWindow::IsWindowOpen()
{
	return false;
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

