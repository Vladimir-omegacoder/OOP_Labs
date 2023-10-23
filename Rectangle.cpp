#include "Rectangle.h"





Rectangle::Rectangle(const Vector2f& size, const Vector2f& pos) : m_size(size)
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

Vector2f Rectangle::get_size() const
{
	return m_size;
}

void Rectangle::set_size(const Vector2f& size)
{
	(*this) = Rectangle(size, Vector2f(0, 0));
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

	Vector2f width = m_vertices[0] - m_vertices[1];
	Vector2f height = m_vertices[0] - m_vertices[3];

	m_size.x = sqrtf(width.x * width.x + width.y * width.y);
	m_size.y = sqrtf(height.x * height.x + height.y * height.y);
}



std::ostream& operator<<(std::ostream& out, const Rectangle& rect)
{
	out << rect.m_size << " ; " << rect.get_pos();

	return out;
}

std::istream& operator>>(std::istream& in, Rectangle& rect)
{
	Vector2f temp;

	in >> temp;
	rect.set_size(temp);

	in.ignore(2);

	in >> temp;
	rect.move(temp);

	return in;
}
