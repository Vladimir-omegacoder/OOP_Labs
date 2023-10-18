#pragma once
#include "Shape.h"





class Rectangle : public Shape
{

protected:

	Vector2f vertices[4];


public:

	Rectangle(const Vector2f& size, const Vector2f& pos);

	Rectangle(float width, float height, float x, float y);


};

