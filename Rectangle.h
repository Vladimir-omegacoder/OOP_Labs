#pragma once
#include "Shape.h"
#include <iostream>





class Rectangle : public Shape
{

protected:

	Vector2f m_vertices[4];

	Vector2f m_size;


public:

	Rectangle() : Rectangle(Vector2f(0, 0), Vector2f(0, 0)) {}

	Rectangle(const Vector2f& size, const Vector2f& pos);



	Vector2f get_pos() const;

	Vector2f get_size() const;

	void set_size(const Vector2f& size);



	virtual void move(const Vector2f& offset) override;

	virtual void rotate(float angle) override;

	virtual void scale(const Vector2f& factor) override;

	virtual void apply_transform(const Transform& transform) override;



	friend std::ostream& operator<<(std::ostream& out, const Rectangle& rect);

	friend std::istream& operator>>(std::istream& in, Rectangle& rect);

};

