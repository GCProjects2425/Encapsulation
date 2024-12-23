#include "EntityBall.h"
#include "GameController.h"
#include <random>

EntityBall::EntityBall()
    : Entity(400, 300)
    , m_MaxSpeed(1)
{
    static std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(1, 5);

    m_vX = dist(rng);
    m_vY = dist(rng);
}

void EntityBall::Init(Window* window)
{
    m_WindowHeight = window->GetHeight();
    m_WindowWidth = window->GetWidth();
}

void EntityBall::Update(Window* window)
{
    if (!m_Sprite) return;

    if (m_WindowHeight != window->GetHeight()) {
        m_Y= window->GetHeight()* m_Y / m_WindowHeight;
        m_WindowHeight = window->GetHeight();
    }

    if (m_WindowWidth != window->GetWidth()) {
        m_X = window->GetWidth() * m_X / m_WindowWidth;
        m_WindowWidth = window->GetWidth();
    }

    if (m_X > m_WindowWidth || (m_X+m_Width) < 0)
    {
        if (m_currentTeam == EntityPaddle::ETeam_Left)
            GameController::GetInstance().GetLeftPaddle()->IncreaseScore();
        if (m_currentTeam == EntityPaddle::ETeam_Right)
            GameController::GetInstance().GetRightPaddle()->IncreaseScore();
        m_currentTeam = EntityPaddle::ETeam_None;
        m_MaxSpeed = 1;
        m_X = m_WindowWidth / 2;
        m_Y = m_WindowHeight / 2;
    }

    m_X += m_vX*m_MaxSpeed * m_WindowHeight/800;
    m_Y += m_vY*m_MaxSpeed * m_WindowHeight / 600;

    if (m_Y <= 0 || m_Y + m_Height >= window->GetHeight()) {
        m_vY = -m_vY;
        m_Sprite->RandomColor();
    }

    if (CheckCollision(*GameController::GetInstance().GetLeftPaddle()) || CheckCollision(*GameController::GetInstance().GetRightPaddle())) {
        m_vX = -m_vX;
        m_Sprite->RandomColor();
    }


    m_Sprite->SetPosition(m_X, m_Y);
}

bool EntityBall::CheckCollision(EntityPaddle& paddle)
{
    float ballRight = m_X + m_Width;
    float ballBottom = m_Y + m_Height;
    float paddleRight = paddle.GetX() + paddle.GetWidth();
    float paddleBottom = paddle.GetY() + paddle.GetHeight();

    if (ballRight > paddle.GetX() && m_X < paddleRight &&
        ballBottom > paddle.GetY() && m_Y < paddleBottom) {
        if (m_currentTeam == paddle.GetCurrentTeam()) return false;
        m_currentTeam = paddle.GetCurrentTeam();
        paddle.GetSprite()->RandomColor();
        m_MaxSpeed += 0.5;
        return true;
    }
    return false;
}
