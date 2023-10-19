#pragma once
#include "Shape.h"





class Rectangle : public Shape
{

protected:

	Vector2f m_vertices[4];


public:

	Rectangle() : Rectangle(Vector2f(0, 0), Vector2f(0, 0)) {}

	Rectangle(const Vector2f& size, const Vector2f& pos);



	Vector2f get_pos() const;

	void set_pos(const Vector2f& pos);

	Vector2f get_size() const;

	void set_size(const Vector2f& size);



	virtual void move(const Vector2f& offset) override;

	virtual void rotate(float angle) override;

	virtual void scale(const Vector2f& factor) override;

	virtual void apply_transform(const Transform& transform) override;

};

