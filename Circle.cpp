#include "Circle.h"





Circle::Circle(float radius, const Vector2f& pos) : m_pos(pos), m_radius(radius)
{
	Transform tr;
	tr.move(Vector2f(pos.x + radius, pos.y + radius));
	
	for (int i = 0; i < 32; i++)
	{
		m_vertices[i] = tr.transform_point(Vector2f(0, radius));
		tr.rotate(11.25);
	}
}



Vector2f Circle::get_pos() const
{
	return m_pos;
}

float Circle::get_radius() const
{
	return m_radius;
}

void Circle::set_radius(float radius)
{
	(*this) = Circle(radius, Vector2f(0, 0));
}



void Circle::move(const Vector2f& offset)
{
	Transform moving;
	moving.move(offset);

	apply_transform(moving);
}

void Circle::rotate(float angle)
{
	Transform rotation;
	rotation.rotate(angle);

	apply_transform(rotation);
}

void Circle::scale(const Vector2f& factor)
{
	Transform scaling;
	scaling.scale(factor);

	apply_transform(scaling);
}

void Circle::apply_transform(const Transform& transform)
{
	for (int i = 0; i < 32; i++)
	{
		m_vertices[i] = transform.transform_point(m_vertices[i]);
	}

	m_pos = transform.transform_point(m_pos);

	Vector2f diameter_vector = m_vertices[16] - m_vertices[0];

	m_radius = sqrtf(diameter_vector.x * diameter_vector.x + diameter_vector.y * diameter_vector.y) / 2;
}



std::ostream& operator<<(std::ostream& out, const Circle& circle)
{
	out << circle.m_radius << " ; " << circle.m_pos;

	return out;
}

std::istream& operator>>(std::istream& in, Circle& circle)
{
	float radius;
	Vector2f new_pos;

	in >> radius;
	circle.set_radius(radius);

	in.ignore(2);

	in >> new_pos;
	circle.move(new_pos);

	return in;
}


