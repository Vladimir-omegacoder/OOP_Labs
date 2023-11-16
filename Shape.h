#pragma once
#include <iostream>
#include "Vector.h"
#include "Transform.h"
//#include "Convex_reshape.h"




class Shape 
{

public:

	virtual ~Shape(){}

	virtual void move(const Vector2f& offset) = 0;

	virtual void rotate(float angle) = 0;

	virtual void scale(const Vector2f& factor) = 0;

	virtual void apply_transform(const Transform& transform) = 0;

};

