#pragma once
#include "Shape.h"





class Rectangle : public Shape
{

protected:

	Vector2f m_vertices[4];


public:

	Rectangle(const Vector2f& size, const Vector2f& pos);

	Rectangle(float width, float height, float x, float y);



	//Getters and setters



	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	virtual void move(const Vector2f& offset) override;

	virtual void rotate(float angle) override;

	virtual void scale(const Vector2f& factor) override;

	virtual void apply_transform(const Transform& transform) override;

	virtual void apply_transform(const Vector2f& offset, float angle, const Vector2f& factor) override;

};

