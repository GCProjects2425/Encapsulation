#include "RaylibWindow.h"

RaylibWindow::~RaylibWindow()
{
}

void RaylibWindow::Init()
{
}

void RaylibWindow::CreateWindow()
{
	InitWindow(800, 600, "raylib [core] example - basic window");
	SetTargetFPS(60);
}

bool RaylibWindow::IsWindowOpen()
{
	return false;
}

void RaylibWindow::ClearWindow()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
}

void RaylibWindow::DrawWindow()
{
	DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

	EndDrawing();
}

