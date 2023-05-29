#pragma once
#include "ForceGenerator.h"

class GravitationalGenerator : public ForceGenerator
{
public:
	GravitationalGenerator(float strength) : m_strength{ strength } {}

	void Apply(std::vector<class Body*> bodies) override;
private:
	float m_strength{ 0 };

};