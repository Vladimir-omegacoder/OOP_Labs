#include "Convex.h"





Convex::Convex(size_t vertex_count) : m_vertices(new Vector2f[vertex_count]), m_vertex_count(vertex_count) {}

Convex::Convex(const Convex& other) : Convex(other.m_vertex_count) 
{
	for (int i = 0; i < m_vertex_count; ++i)
	{
		m_vertices[i] = other.m_vertices[i];
	}
}

Convex& Convex::operator=(const Convex& other)
{
	if(m_vertices == other.m_vertices)
	{
		return *this;
	}

	m_vertex_count = other.m_vertex_count;

	delete[] m_vertices;
	m_vertices = new Vector2f[m_vertex_count];
	for (int i = 0; i < m_vertex_count; ++i)
	{
		m_vertices[i] = other.m_vertices[i];
	}

	return *this;
}



Vector2f& Convex::operator[](int index)
{
	return m_vertices[index];
}

Vector2f Convex::operator[](int index) const
{
	return m_vertices[index];
}



void Convex::move(const Vector2f& offset)
{
	Transform moving;
	moving.move(offset);

	apply_transform(moving);
}

void Convex::rotate(float angle)
{
	Transform rotation;
	rotation.rotate(angle);

	apply_transform(rotation);
}

void Convex::scale(const Vector2f& factor)
{
	Transform scaling;
	scaling.scale(factor);

	apply_transform(scaling);
}

void Convex::apply_transform(const Transform& transform)
{
	for (int i = 0; i < m_vertex_count; ++i)
	{
		m_vertices[i] = transform.transform_point(m_vertices[i]);
	}
}



std::ostream& operator<<(std::ostream& out, const Convex& convex)
{
	for (int i = 0; i < convex.m_vertex_count - 1; ++i)
	{
		out << convex[i] << " ; ";
	}

	out << convex[convex.m_vertex_count - 1];

	return out;
}

std::istream& operator>>(std::istream& in, Convex& convex)
{
	for (int i = 0; i < convex.m_vertex_count - 1; ++i)
	{
		in >> convex[i];
		in.ignore(2);
	}

	in >> convex[convex.m_vertex_count - 1];

	return in;
}
