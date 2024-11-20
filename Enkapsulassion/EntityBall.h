#pragma once
#include "Entity.h"
#include <cstdlib>
#include <ctime>
class EntityBall :
    public Entity
{
public:
    EntityBall();

    void Update(Window* window);

private:
    int m_WindowWidth;
    int m_WindowHeight;
    int m_vX, m_vY;
};

