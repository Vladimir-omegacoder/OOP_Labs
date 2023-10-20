#pragma once
#include "Shape.h"





class Convex : public Shape
{

protected:

	Vector2f* m_vertices;

	size_t m_vertex_count;


public:

	Convex(size_t vertex_count);

	Convex(const Convex& other);

	Convex& operator=(const Convex& other);

	~Convex() { delete[] m_vertices; }







	virtual void move(const Vector2f& offset) {};

	virtual void rotate(float angle) {};

	virtual void scale(const Vector2f& factor) {};

	virtual void apply_transform(const Transform& transform) {};

};

