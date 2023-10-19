#pragma once
#include "Shape.h"





class Circle : public Shape
{

protected:

	Vector2f m_vertices[32];

	Vector2f m_pos;

	float m_radius;


public:

	Circle() : Circle(50, Vector2f(0, 0)) {}

	Circle(float radius, const Vector2f& pos);

	
	Vector2f get_pos() const;
	
	float get_radius() const;



	virtual void move(const Vector2f& offset) override {};

	virtual void rotate(float angle) override {};

	virtual void scale(const Vector2f& factor) override {};

	virtual void apply_transform(const Transform& transform) override {};

};