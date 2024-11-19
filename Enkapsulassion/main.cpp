#include <vector>
#include <memory>

#include "SDLWindow.h"
#include "SDLSprite.h"
#include "EntityBall.h"

int main(int argc, char* argv[])
{
	SDLWindow* window = new SDLWindow();
	window->Init();
	window->CreateWindow(800, 600);

	/*std::vector<std::unique_ptr<SDLSprite>> sBalls;
	std::vector<std::unique_ptr<EntityBall>> balls;

	for (size_t i = 0; i < 5; i++)
	{
		SDLSprite sdlSprite(window->GetRenderer());
		if (sdlSprite.LoadImage("resources\\logo-dvd.png", 100, 50)) {
			SDL_Log("Image loaded!");
		}

		//sBalls.push_back(std::move(sdlSprite));
	
		EntityBall entityBall;
		entityBall.SetSprite(&sdlSprite);

	}
	

	SDL_Delay(500);*/

	SDLSprite ball(window->GetRenderer());
	if (ball.LoadImage("resources\\logo-dvd.png", 100, 50)) {
		SDL_Log("Image loaded!");
	}

	EntityBall eball;
	eball.SetSprite(&ball);

	while (window->IsWindowOpen())
	{
		window->HandleEvent();

		//entityBall.Update(0, *window);
		eball.Update(0, *window);
		
		window->ClearWindow();

		//entityBall.Draw();
		eball.Draw();

		window->DrawWindow();
	}

	return 0;
}