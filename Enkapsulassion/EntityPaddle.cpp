#include "EntityPaddle.h"

EntityPaddle::EntityPaddle(int startX, int startY, const std::string& keyDown, const std::string& keyUp, ETeam team)
    : Entity(startX, startY), m_Speed(16)
{
    m_KeyDown = keyDown;
    m_KeyUp = keyUp;
    m_currentTeam = team;
}

void EntityPaddle::Update(Window* window)
{
    if (window->IsKeyPressed(m_KeyUp) && m_Y > 0) {
        m_Y -= m_Speed * window->GetWidth()/1920;
    }
    if (window->IsKeyPressed(m_KeyDown) && m_Y + m_Height < window->GetHeight()) {
        m_Y += m_Speed * window->GetWidth() / 1920;
    }
    m_Sprite->SetPosition(m_X, m_Y);
}
