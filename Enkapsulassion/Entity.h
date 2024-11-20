#pragma once
#include "Sprite.h"
#include "Window.h"
class Entity
{
public: 
	Entity(int x, int y);

	virtual ~Entity() {}

	void SetSprite(Sprite* sprite);

	virtual void Update(Window* window) = 0;
	virtual void Draw() { m_Sprite->Render(); }

	const int GetX() const { return m_X; }
	const int GetY() const { return m_Y; }

	const int GetWidth() const { return m_Width; }
	const int GetHeight() const { return m_Height; }
protected:
	Sprite* m_Sprite;
	int m_X, m_Y;
	int m_Width, m_Height;
};

