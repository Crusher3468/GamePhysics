#pragma once
#include "Shape.h"

class CircleShape : public Shape
{
public:
	CircleShape(float radius, const glm::vec4& color) :
		radius{ radius },
		Shape{ color }
	{}

	void Draw(Graphics* graphics, const glm::vec2& position);

public:
	float radius{ 1 };
};