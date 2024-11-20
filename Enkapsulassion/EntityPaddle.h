#pragma once
#include "Entity.h"
class EntityPaddle : 
    public Entity 
{
public:
    EntityPaddle(int startX, int startY, const std::string& keyDown, const std::string& keyUp);

    void Update(Window* window);

private:
    std::string m_KeyDown, m_KeyUp;
    int m_Speed;
};