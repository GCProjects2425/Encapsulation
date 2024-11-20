#include <vector>
#include <memory>

#include "SDLWindow.h"
#include "RaylibWindow.h"
#include "EntityBall.h"
#include "EntityPaddle.h"

int main(int argc, char* argv[])
{
	Window* window = new SDLWindow();
	//Window* window = new RaylibWindow();

	window->Init();
	window->CreateWindow(800, 600);

	std::vector<Sprite*> sBalls;
	std::vector<Entity*> balls;

	for (size_t i = 0; i < 1; i++)
	{
		Sprite* ball = window->CreateSprite();
		//sBalls.push_back(std::move(sdlSprite));
		ball->LoadImage("resources\\logo-dvd.png", 100, 50);
	
		EntityBall* entityBall = new EntityBall();
		entityBall->SetSprite(ball);

		sBalls.push_back(std::move(ball));
		balls.push_back(std::move(entityBall));
	}


	Sprite* paddle1sprite = window->CreateSprite();
	paddle1sprite->LoadImage("resources\\paddle.png", 10, 150);

	EntityPaddle* entityPaddle1 = new EntityPaddle(10, (window->GetHeight() - 150) / 2, "S", "Z");
	entityPaddle1->SetSprite(paddle1sprite);

	sBalls.push_back(std::move(paddle1sprite));
	balls.push_back(std::move(entityPaddle1));

	while (window->IsWindowOpen())
	{
		window->StartFrame();

		window->Update();
		window->HandleEvent();

		for (const auto& entity : balls) {
			entity->Update(window);
		}

		window->ClearWindow();
		//entityBall.Update(0, *window);
		//eball.Update(0, *window);

		for (const auto& sprite : sBalls) {
			sprite->Render();
		}

		window->DrawFPSCounter();

		window->DrawWindow();

		window->EndFrame();
	}

	return 0;
}