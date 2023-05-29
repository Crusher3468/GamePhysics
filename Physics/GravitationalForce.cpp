#include "GravitationalForce.h"
#include "../Engine/Body.h"

void GravitationalForce::Apply(std::vector<class Body*> bodies)
{
	for (size_t i = 0; i < bodies.size() - 1; i++)
	{
		for (size_t j = i + 1; j < bodies.size(); j++)
		{
			Body* bodyA = bodies[i];
			Body* bodyB = bodies[j];
			glm::vec2 direction = bodyB->position - bodyA->position;
			float distance = glm::length(direction);
			if (distance == 0) continue;
			distance = glm::max(1.0f, distance);
			float force = m_strength * ((bodyA->mass * bodyB->mass) / distance);
			glm::vec2 ndirection = glm::normalize(direction);
			bodyA->ApplyForce(ndirection * force);
			bodyB->ApplyForce(-ndirection * force);
		}
	}


	for (auto body : bodies)
	{
		body->ApplyForce({ 0, -m_strength });
	}
}