#include <vector>
#include <memory>

#include "SDLWindow.h"
#include "RaylibWindow.h"
#include "GameController.h"

int main(int argc, char* argv[])
{
	Window* window = new SDLWindow();
	//Window* window = new RaylibWindow();

	window->Init();
	window->CreateWindow(800, 600);

	GameController::GetInstance().Init(window);
	GameController::GetInstance().Run();

	return 0;
}