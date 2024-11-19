#pragma once
class Sprite
{
public:
	Sprite() : m_X(0), m_Y(0) {};
	virtual ~Sprite() {};

	virtual bool LoadImage(const char* fileName) = 0;
	virtual void Draw() = 0;
	virtual void* GetData() = 0;

	virtual void Render() = 0;

	void SetPosition(int x, int y);
protected:
	int m_X;
	int m_Y;
};

