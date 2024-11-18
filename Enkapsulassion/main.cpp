#include "SDLWindow.h"

int main(int argc, char* argv[])
{
	SDLWindow* window = new SDLWindow();

	window->Init();
	window->CreateWindow();

	window->DrawWindow();

	return 0;
}