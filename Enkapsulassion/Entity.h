#pragma once
#include "Sprite.h"
#include "Window.h"
class Entity
{
public: 
	Entity(int x, int y);

	virtual ~Entity() {}

	enum ETeam
	{
		ETeam_None = 0,
		ETeam_Left,
		ETeam_Right
	};

	void SetSprite(Sprite* sprite);

	virtual void Init(Window* window) = 0;
	virtual void Update(Window* window) = 0;
	virtual void Draw() { m_Sprite->Render(); }

	const int GetX() const { return m_X; }
	const int GetY() const { return m_Y; }

	const int GetWidth() const { return m_Width; }
	const int GetHeight() const { return m_Height; }

	Sprite* GetSprite() { return m_Sprite; }
	const ETeam& GetCurrentTeam() const { return m_currentTeam; }
protected:
	Sprite* m_Sprite;
	ETeam m_currentTeam;
	int m_X, m_Y;
	int m_Width, m_Height;
	int m_WindowWidth;
	int m_WindowHeight;
};

