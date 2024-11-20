#include <vector>
#include <memory>

#include "SDLWindow.h"
#include "RaylibWindow.h"
#include "EntityBall.h"

int main(int argc, char* argv[])
{
	Window* window = new SDLWindow();
	window->Init();
	window->CreateWindow(800, 600);

	std::vector<Sprite*> sBalls;
	std::vector<EntityBall*> balls;

	for (size_t i = 0; i < 100; i++)
	{
		Sprite* ball = window->CreateSprite();
		//sBalls.push_back(std::move(sdlSprite));
		ball->LoadImage("resources\\logo-dvd.png", 100, 50);
	
		EntityBall* entityBall = new EntityBall();
		entityBall->SetSprite(ball);

		sBalls.push_back(std::move(ball));
		balls.push_back(std::move(entityBall));

	}
	

	/*SDL_Delay(500);
	Sprite* ball = window->CreateSprite();

	EntityBall eball;
	eball.SetSprite(ball);*/

	while (window->IsWindowOpen())
	{
		window->HandleEvent();

		for (const auto& entity : balls) {
			entity->Update(0, *window);
		}

		window->ClearWindow();
		//entityBall.Update(0, *window);
		//eball.Update(0, *window);

		for (const auto& sprite : sBalls) {
			sprite->Render();
		}

		//entityBall.Draw();
		//eball.Draw();

		SDL_Delay(16);

		window->DrawWindow();
	}

	return 0;
}