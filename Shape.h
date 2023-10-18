#pragma once
#include "Vector.h"
#include "Transform.h"
#include "SFML/Graphics.hpp"





struct Color
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};



class Shape : sf::Drawable
{

public:

	virtual ~Shape(){}

	virtual void set_color(Color color) = 0;

	virtual Color get_color() = 0;

	virtual void move(const Vector2f& offset) = 0;

	virtual void rotate(float angle) = 0;

	virtual void scale(const Vector2f& factor) = 0;

	virtual void apply_transform(const Transform& transform) = 0;

	virtual void apply_transform(const Vector2f& offset, float angle, const Vector2f& factor) = 0;

};

