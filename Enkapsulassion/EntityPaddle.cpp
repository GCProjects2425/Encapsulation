#include "EntityPaddle.h"

EntityPaddle::EntityPaddle(int startX, int startY, const std::string& keyDown, const std::string& keyUp, ETeam team)
    : Entity(startX, startY), m_Speed(16)
{
    m_KeyDown = keyDown;
    m_KeyUp = keyUp;
    m_currentTeam = team;
}

void EntityPaddle::Init(Window* window)
{
    m_WindowHeight = window->GetHeight();
    m_WindowWidth = window->GetWidth();
}

void EntityPaddle::Update(Window* window)
{
    if (m_WindowHeight != window->GetHeight()) {
        m_Y = window->GetHeight() * m_Y / m_WindowHeight;
        m_WindowHeight = window->GetHeight();
    }

    if (m_WindowWidth != window->GetWidth()) {
        m_X = window->GetWidth() * m_X / m_WindowWidth;
        m_WindowWidth = window->GetWidth();
    }
    if (window->IsKeyPressed(m_KeyUp) && m_Y > 0) {
        m_Y -= m_Speed * window->GetWidth()/1920;
    }
    if (window->IsKeyPressed(m_KeyDown) && m_Y + m_Height < window->GetHeight()) {
        m_Y += m_Speed * window->GetWidth() / 1920;
    }
    m_Sprite->SetPosition(m_X, m_Y);
}
