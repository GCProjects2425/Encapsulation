#pragma once
#include "Entity.h"
class EntityPaddle : public Entity {
public:
    EntityPaddle(int startX, int startY)
        : Entity(startX, startY), m_Speed(300) {
        m_Sprite->SetPosition(startX, startY);
    }

    void Update(float deltaTime, bool moveUp, bool moveDown, const Window& window) {
        if (moveUp && m_Y > 0) {
            m_Y -= m_Speed * deltaTime;
        }
        if (moveDown && m_Y + m_Height < window.GetHeight()) {
            m_Y += m_Speed * deltaTime;
        }
        m_Sprite->SetPosition(m_X, m_Y);
    }

private:
    int m_Speed;
};