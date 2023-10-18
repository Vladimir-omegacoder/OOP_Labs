#pragma once
#include "Vector.h"





class Shape
{

	virtual ~Shape(){}

	virtual void draw() = 0;

	virtual void move(const Vector2f& offset) = 0;

	virtual void rotate(float angle) = 0;

	virtual void scale(const Vector2f& factor) = 0;

};

