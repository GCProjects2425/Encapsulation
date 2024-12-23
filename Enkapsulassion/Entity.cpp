#include "Entity.h"

Entity::Entity(int x, int y)
	: m_Sprite(0)
	, m_X(x)
	, m_Y(y)
	, m_Width(0)
	, m_Height(0)
	, m_WindowWidth(0)
	, m_WindowHeight(0)
	, m_currentTeam(ETeam_None)
{}

void Entity::SetSprite(Sprite * sprite)
{
	m_Sprite = sprite;
	m_Width = sprite->GetWidth();
	m_Height = sprite->GetHeight();
}
