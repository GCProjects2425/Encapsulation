#include "GameController.h"

void GameController::Init(Window* window)
{
    m_Window = window;

	// Init ball
	Sprite* ballSprite = window->CreateSprite();
	ballSprite->LoadImage("resources\\logo-dvd.png", 100, 50);
    m_Ball = new EntityBall();
	m_Ball->SetSprite(ballSprite);
	m_EntityVector.push_back(m_Ball);

	// Init paddle 1
	Sprite* paddle1Sprite = window->CreateSprite();
	paddle1Sprite->LoadImage("resources\\paddle.png", 10, 150);
    m_LeftPaddle = new EntityPaddle(20, (window->GetHeight()-paddle1Sprite->GetHeight())/2, "S", "Z");
	m_LeftPaddle->SetSprite(paddle1Sprite);
	m_EntityVector.push_back(m_LeftPaddle);

	// Init paddle 2
	Sprite* paddle2Sprite = window->CreateSprite();
	paddle2Sprite->LoadImage("resources\\paddle.png", 10, 150);
	m_RightPaddle = new EntityPaddle(m_Window->GetWidth() - (paddle2Sprite->GetWidth()+10), (window->GetHeight() - paddle1Sprite->GetHeight()) / 2, "DOWN", "UP");
	m_RightPaddle->SetSprite(paddle2Sprite);
	m_EntityVector.push_back(m_RightPaddle);
}

void GameController::Run() {
	while (m_IsRunning && m_Window->IsWindowOpen())
	{
		m_Window->StartFrame();

		// Update
		m_Window->Update();
		m_Window->HandleEvent();
		for (const auto& entity : m_EntityVector) {
			entity->Update(m_Window);
		}

		// Draw
		m_Window->ClearWindow();
		for (const auto& entity : m_EntityVector) {
			entity->Draw();
		}
		m_Window->DrawFPSCounter();
		m_Window->DrawWindow();

		m_Window->EndFrame();
	}
}