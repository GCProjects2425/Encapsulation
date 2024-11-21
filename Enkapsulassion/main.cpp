#include <vector>
#include <memory>
#include <iostream>

#include "SDLWindow.h"
#include "RaylibWindow.h"
#include "GameController.h"

int main(int argc, char* argv[])
{
    Window* window;
    if (argc > 1) {
        std::string arg = argv[1];
        if (arg == "--raylib") {
            window = new RaylibWindow();
        }
        else if (arg == "--sdl") {
            window = new SDLWindow();
        }
        else {
            std::cerr << "Not valid argument. Using default lib." << std::endl;
#ifdef USE_SDL
            window = new SDLWindow();
#elif defined(USE_RAYLIB)
            window = new RaylibWindow();
#else
            std::cerr << "Not default lib specified. Using SDL." << std::endl;
            window = new SDLWindow();
#endif
        }
    }
    else {
#ifdef USE_SDL
        window = new SDLWindow();
#elif defined(USE_RAYLIB)
        window = new RaylibWindow();
#else
        std::cerr << "Not default lib specified. Using SDL." << std::endl;
        window = new SDLWindow();
#endif
    }

	window->Init();
	window->CreateWindow(800, 600);

	GameController::GetInstance().Init(window);
	GameController::GetInstance().Run();

	return 0;
}