#pragma once
#include "Sprite.h"
#include "Window.h"
class Entity
{
public: 
	Entity(int x, int y);

	virtual ~Entity() {}

	void SetSprite(Sprite* sprite);

	virtual void Update(float deltaTime, const Window& window) = 0;
	virtual void Draw() { m_Sprite->Render(); }
protected:
	Sprite* m_Sprite;
	int m_X, m_Y;
	int m_Width, m_Height;
};
