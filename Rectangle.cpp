#include "Rectangle.h"





Rectangle::Rectangle(const Vector2f& size, const Vector2f& pos)
{
	m_vertices[0] = Vector2f(pos.x, pos.y);
	m_vertices[1] = Vector2f(pos.x + size.x, pos.y);
	m_vertices[2] = Vector2f(pos.x + size.x, pos.y + size.y);
	m_vertices[3] = Vector2f(pos.x, pos.y + size.y);
}

Rectangle::Rectangle(float width, float height, float x, float y)
{
	m_vertices[0] = Vector2f(x, y);
	m_vertices[1] = Vector2f(x + width, y);
	m_vertices[2] = Vector2f(x + width, y + height);
	m_vertices[3] = Vector2f(x, y + height);
}





void Rectangle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

}

void Rectangle::move(const Vector2f& offset)
{
	Transform moving;
	moving.move(offset);

	apply_transform(moving);
}

void Rectangle::rotate(float angle)
{
	Transform rotation;
	rotation.rotate(angle);

	apply_transform(rotation);
}

void Rectangle::scale(const Vector2f& factor)
{
	Transform scaling;
	scaling.scale(factor);

	apply_transform(scaling);
}

void Rectangle::apply_transform(const Transform& transform)
{
	for (int i = 0; i < 4; ++i)
	{
		m_vertices[i] = transform.transform_point(m_vertices[i]);
	}
}

void Rectangle::apply_transform(const Vector2f& offset, float angle, const Vector2f& factor)
{
	Transform transform;
	transform.move(offset);
	transform.rotate(angle);
	transform.scale(factor);

	for (int i = 0; i < 4; ++i)
	{
		m_vertices[i] = transform.transform_point(m_vertices[i]);
	}
}
