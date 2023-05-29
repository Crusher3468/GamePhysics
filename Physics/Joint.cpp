#include "Joint.h"
#include "../Engine/Body.h"
#include "../Engine/Graphic.h"

Joint::Joint(Body* bodyA, Body* bodyB, float stiffness, float restLength) :
	m_bodyA {bodyA},
	m_bodyB {bodyB},
	m_stiffness {stiffness},
	m_restLength { restLength }
{
	if (m_restLength == 0) m_restLength = glm::distance(bodyA->position, bodyB->position);
}

void Joint::Step(float dt)
{
	glm::vec2 direction = m_bodyA->position - m_bodyB->position;
	float length = glm::length(direction);

	float x = length - m_restLength;
	//if (x < 0) return;
	float f = -m_stiffness * x;

	glm::vec2 ndirection = glm::normalize(direction);
	m_bodyA->ApplyForce(ndirection * f);
	m_bodyB->ApplyForce(-ndirection * f);
}

void Joint::Draw(Graphics* graphics)
{
	graphics->DrawLine(graphics->WorldToScreen(m_bodyA->position), graphics->WorldToScreen(m_bodyB->position), glm::vec4{ 1 });
}
