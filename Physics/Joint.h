#pragma once

class Joint
{
public:
	Joint(class Body* bodyA, class Body* bodyB, float stiffness, float restLength = 0);

	void Step(float dt);
	void Draw(class Graphics* graphics);

protected:
	float m_restLength{ 0 };
	float m_stiffness{ 0 };

	class Body* m_bodyA{ nullptr };
	class Body* m_bodyB{ nullptr };
};