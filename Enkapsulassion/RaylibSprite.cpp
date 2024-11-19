#include "RaylibSprite.h"

RaylibSprite::~RaylibSprite()
{
}

bool RaylibSprite::LoadImage(const char* fileName)
{
	 RaylibSprite::texture = LoadTexture(fileName);
}

void RaylibSprite::Draw()
{
}

void* RaylibSprite::GetData()
{
	return &texture;
}
