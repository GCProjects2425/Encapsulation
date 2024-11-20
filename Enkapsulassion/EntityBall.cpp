#include "EntityBall.h"
#include <random>

EntityBall::EntityBall()
    : Entity(400, 300)
    , m_WindowWidth(0)
    , m_WindowHeight(0)
{
    static std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(1, 5);

    m_vX = dist(rng);
    m_vY = dist(rng);
}

void EntityBall::Update(Window* window)
{
    if (!m_Sprite) return;

    m_WindowWidth = window->GetWidth();
    m_WindowHeight = window->GetHeight();

    if (m_X > m_WindowWidth || m_Y > m_WindowHeight)
    {
        m_X = m_WindowWidth/2;
        m_Y = m_WindowHeight/2;
    }

    m_X += m_vX;
    m_Y += m_vY;

    if (m_Y <= 0 || m_Y + m_Height >= window->GetHeight()) {
        m_vY = -m_vY;
    }

    /*if (CheckCollision(*window->Paddle1) || CheckCollision(*window->Paddle2)) {
        m_vX = -m_vX;
    }*/


    m_Sprite->SetPosition(m_X, m_Y);
}

bool EntityBall::CheckCollision(const EntityPaddle& paddle)
{
    if (m_X + m_Width > paddle.GetX() && m_X < paddle.GetX() + paddle.GetWidth() &&
        m_Y + m_Height > paddle.GetY() && m_Y < paddle.GetY() + paddle.GetHeight()) {
        return true;
    }
    return false;
}
