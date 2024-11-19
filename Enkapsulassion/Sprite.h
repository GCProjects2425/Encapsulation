#pragma once
class Sprite
{
public:
	Sprite() : m_X(0), m_Y(0), m_Width(0), m_Height(0) {};
	virtual ~Sprite() {};

	virtual bool LoadImage(const char* fileName, int width, int height) = 0;
	virtual void* GetData() = 0;

	virtual void Render() = 0;

	virtual void RandomColor() = 0;

	void SetPosition(int x, int y);

	const int GetWidth() const { return m_Width; }
	const int GetHeight() const { return m_Height; }
protected:
	int m_X;
	int m_Y;
	int m_Width;
	int m_Height;
};

