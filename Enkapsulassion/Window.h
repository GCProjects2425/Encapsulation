#pragma once
#include "Sprite.h"
#include <string>

class Window
{
public:
	Window() : m_WindowWidth(0), m_WindowHeight(0), m_IsOpen(false), m_IsFullScreen(false), m_DeltaTime(0.0f) 
	{
		m_TargetFps = 60.f;
		m_FrameDelay = 1000.f / m_TargetFps;
	}
	virtual ~Window() {};

	virtual void Init() = 0;
	virtual void CreateWindow(int windowWidth, int windowHeight) = 0;
	virtual bool IsWindowOpen() { return m_IsOpen; };
	virtual void ClearWindow() = 0;
	virtual void DrawWindow() = 0;
	virtual void Update() = 0;
	virtual Sprite* CreateSprite() = 0;

	virtual bool IsKeyPressed(const std::string& key) = 0;

	virtual void HandleEvent() = 0;

	const int GetWidth() const { return m_WindowWidth;  }
	const int GetHeight() const { return m_WindowHeight; }

	virtual void StartFrame() {};
	virtual void EndFrame() {};
	virtual void DrawFPSCounter() = 0;

	const float GetDeltaTime() const { return m_DeltaTime;  }

protected:
	float m_DeltaTime;
	float m_TargetFps;
	float m_FrameDelay;

	int m_WindowWidth;
	int m_WindowHeight;

	bool m_IsOpen;
	bool m_IsFullScreen;
};

