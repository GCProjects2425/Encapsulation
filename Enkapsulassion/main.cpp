#include "SDLWindow.h"
#include "RaylibWindow.h"
#include "RaylibSprite.h"

int main(int argc, char* argv[])
{
	RaylibWindow* window = new RaylibWindow();
	RaylibSprite* sprite = new RaylibSprite();
	window->Init();
	window->CreateWindow();

	window->DrawWindow();

	return 0;
}