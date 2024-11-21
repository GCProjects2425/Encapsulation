#pragma once
#include "Entity.h"
class EntityPaddle : 
    public Entity 
{
public:
    EntityPaddle(int startX, int startY, const std::string& keyDown, const std::string& keyUp, ETeam team);

    void Init(Window* window);
    void Update(Window* window);

    int GetScore() { return m_Score; };
    void IncreaseScore() { m_Score++; }
private:
    std::string m_KeyDown, m_KeyUp;
    int m_Speed;
    int m_Score;
};