#include <vector>
#include <memory>

#include "SDLWindow.h"
#include "SDLSprite.h"
#include "EntityBall.h"

int main(int argc, char* argv[])
{
	Window* window = new SDLWindow();
	window->Init();
	window->CreateWindow(800, 600);

	std::vector<std::unique_ptr<Sprite>> sBalls;
	std::vector<std::unique_ptr<EntityBall>> balls;

	for (size_t i = 0; i < 5; i++)
	{
		Sprite* ball = window->CreateSprite();
		//sBalls.push_back(std::move(sdlSprite));
	
		EntityBall* entityBall = new EntityBall();
		entityBall->SetSprite(ball);

		sBalls.push_back(std::move(ball));
	}
	

	SDL_Delay(500);*/
	Sprite* ball = window->CreateSprite();

	EntityBall eball;
	eball.SetSprite(ball);

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