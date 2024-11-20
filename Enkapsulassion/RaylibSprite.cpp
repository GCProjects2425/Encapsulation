#include "RaylibSprite.h"
#include <stdlib.h>

RaylibSprite::~RaylibSprite()
{
}

bool RaylibSprite::LoadImage(const char* fileName,int width, int height)
{
	 RaylibSprite::texture = LoadTexture(fileName);
	 texture.width = width;
	 texture.height = height;
	 m_Width = width;
	 m_Height = height;
	 return true;
}

void* RaylibSprite::GetData()
{
	return &texture;
}

void RaylibSprite::Render()
{
	DrawTexture(RaylibSprite::texture, Sprite::m_X, Sprite::m_Y, m_Color);
}

void RaylibSprite::RandomColor()
{
	m_Color.r = rand() % 256;
	m_Color.g = rand() % 256;
	m_Color.b = rand() % 256;
}
