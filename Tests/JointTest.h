#pragma once
#include "Test.h"

class JointTest : public Test
{
public:
	void Initialize() override;

	void Update() override;
	virtual void FixedUpdate() override;
	virtual void Render() override;

private:
	class Body* m_anchor{ nullptr };
	class Body* m_user{ nullptr };
};