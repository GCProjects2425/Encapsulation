#include "RaylibSprite.h"

RaylibSprite::~RaylibSprite()
{
}

bool RaylibSprite::LoadImage(const char* fileName)
{
	 RaylibSprite::texture = LoadTexture(fileName);
	 return true;
}

void* RaylibSprite::GetData()
{
	return &texture;
}

void RaylibSprite::Render()
{
	DrawTexture(RaylibSprite::texture, Sprite::m_X, Sprite::m_Y, WHITE);
}
