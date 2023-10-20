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

