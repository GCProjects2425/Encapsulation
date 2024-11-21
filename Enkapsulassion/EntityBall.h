#pragma once
#include "Entity.h"
#include "EntityPaddle.h"
#include <cstdlib>
#include <ctime>
class EntityBall :
    public Entity
{
public:
    EntityBall();

    void Init(Window* window);
    void Update(Window* window);

    bool CheckCollision(EntityPaddle& paddle);

private:
    float m_MaxSpeed;
    float m_vX, m_vY;
};

