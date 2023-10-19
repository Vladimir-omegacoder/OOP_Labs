#include "Rectangle.h"





Rectangle::Rectangle(const Vector2f& size, const Vector2f& pos)
{
	m_vertices[0] = Vector2f(pos.x, pos.y);
	m_vertices[1] = Vector2f(pos.x + size.x, pos.y);
	m_vertices[2] = Vector2f(pos.x + size.x, pos.y + size.y);
	m_vertices[3] = Vector2f(pos.x, pos.y + size.y);
}



Vector2f Rectangle::get_pos() const
{
	return m_vertices[0];
}

void Rectangle::set_pos(const Vector2f& pos)
{
	Vector2f size = get_size();

	m_vertices[0] = pos;
	m_vertices[1] = Vector2f(pos.x + size.x, pos.y);
	m_vertices[2] = (pos + size);
	m_vertices[3] = Vector2f(pos.x, pos.y + size.y);
}

Vector2f Rectangle::get_size() const
{
	return Vector2f(m_vertices[1].x - m_vertices[0].x, m_vertices[3].y - m_vertices[0].y);
}

void Rectangle::set_size(const Vector2f& size)
{
	Vector2f cur_size = get_size();

	m_vertices[1].x += size.x - cur_size.x;
	m_vertices[2] += size - cur_size;
	m_vertices[3].y += size.y - cur_size.y;
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


