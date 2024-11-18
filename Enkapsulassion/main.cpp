#include "SDLWindow.h"

int main(int argc, char* argv[])
{
	SDLWindow* window = new SDLWindow();

	window->Init();
	window->CreateWindow();

	while (true)
	{

	}

	return 0;
}