#pragma once
class Sprite
{
public:
	Sprite() {}
	virtual ~Sprite() {};

	virtual void LoadImage(const char* fileName) = 0;
	virtual int GetData() = 0;
private:
	float m_Position[2];
};

