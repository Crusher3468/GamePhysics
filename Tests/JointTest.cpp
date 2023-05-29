#include "JointTest.h"
#include "../Engine/CircleShape.h"
#include "../Engine/Body.h"
#include "../Engine/World.h"
#include "../Physics/Joint.h"

#define SPRING_STIFFNESS 100
#define SPRING_LENGTH 2
#define BODY_DAMPING 10
#define CHAIN_SIZE 3
#define CHAIN

void JointTest::Initialize()
{
	Test::Initialize();

	m_anchor = new Body(new CircleShape(0.5f, { 1, 0, 0, 1 }), { 0, 0 }, { 0, 0 }, 0, Body::KINEMATIC);
	m_world->AddBody(m_anchor);

#if defined(CHAIN)
	auto prevBody = m_anchor;

	//chains
	for (int i = 0; i < CHAIN_SIZE; i++)
	{
		auto body = new Body(new CircleShape(0.5f, { 1, 1, 1, 1 }), { -1, i }, { 0, 0 }, 1, Body::DYNAMIC);
		//body->gravityScale = 150;
		body->damping = BODY_DAMPING;
		m_world->AddBody(body);

		auto joint = new Joint(prevBody, body, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint);

		prevBody = body;
	}
#else
		
	auto prevBodyA = m_anchor;
	auto prevBodyB = m_anchor;

	for (int i = 0; i < CHAIN_SIZE; i++)
	{
		if (i == 0)
		{
			auto bodyA = new Body(new CircleShape(0.5f, { 0, 0, 1, 1 }), { -1, i }, { 0, 0 }, 1, Body::DYNAMIC);
			bodyA->damping = BODY_DAMPING;
			m_world->AddBody(bodyA);

			auto joint = new Joint(prevBodyA, bodyA, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint);

			prevBodyA = bodyA;

			auto bodyB = new Body(new CircleShape(0.5f, { 0, 0, 1, 1 }), { 1, i }, { 0, 0 }, 1, Body::DYNAMIC);
			bodyB->damping = BODY_DAMPING;
			m_world->AddBody(bodyB);

			joint = new Joint(prevBodyB, bodyB, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint);

			joint = new Joint(prevBodyA, bodyB, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint);

			prevBodyB = bodyB;
		}
		else
		{
			auto bodyA = new Body(new CircleShape(0.5f, { 0, 0, 1, 1 }), { -1, i }, { 0, 0 }, 1, Body::DYNAMIC);
			bodyA->damping = BODY_DAMPING;
			m_world->AddBody(bodyA);

			auto joint = new Joint(prevBodyA, bodyA, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint);

			joint = new Joint(prevBodyB, bodyA, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint);		

			auto bodyB = new Body(new CircleShape(0.5f, { 0, 0, 1, 1 }), { 1, i }, { 0, 0 }, 1, Body::DYNAMIC);
			bodyB->damping = BODY_DAMPING;
			m_world->AddBody(bodyB);

			joint = new Joint(prevBodyB, bodyB, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint);

			joint = new Joint(prevBodyA, bodyB, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint);

			joint = new Joint(bodyA, bodyB, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint);

			prevBodyA = bodyA;
			prevBodyB = bodyB;
		}
		
	}
#endif
}

void JointTest::Update()
{
	Test::Update();
	 m_anchor->position = m_graphics->ScreenToWorld(m_input->GetMousePosition());
}

void JointTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void JointTest::Render()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 10, { randomf(), randomf(), randomf(), 1 });
}