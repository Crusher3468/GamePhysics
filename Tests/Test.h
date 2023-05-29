#pragma once
#include "../Engine/Graphic.h"
#include "../Engine/Input.h"
#include "../Engine/Time.h"
#include "../Engine/Random.h"
#include "../Engine/World.h"

class Test
{
public:
	Test();
	~Test();

	virtual void Initialize();
	virtual void Run();

	virtual void Update();
	virtual void FixedUpdate() = 0;

	virtual void PreRender();
	virtual void Render() = 0;
	virtual void PostRender();

	bool IsQuit() { return m_quit; }

protected:
	void UpdateEvents();

protected:
	bool m_quit{ false };
	float m_fixedTime{ 1 };
	World* m_world{ nullptr };
	class Graphics* m_graphics{ nullptr };
	class Input* m_input{ nullptr };
	class Time* m_time{ nullptr };
};