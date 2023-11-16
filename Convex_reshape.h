#pragma once
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Convex.h"







class Convex_reshape
{

private:

	Convex* m_convex;


public:

	Convex_reshape() = default;

	Convex_reshape(Convex& convex) : m_convex(&convex) {}



	Convex_reshape& operator()(Convex& convex)
	{
		m_convex = &convex;
		return *this;
	}



	Convex_reshape& operator=(const Rectangle& rectangle)
	{

		delete m_convex->m_vertices;
		m_convex->m_vertex_count = 4;
		m_convex->m_vertices = new Vector2f[4]
		{
			rectangle.m_vertices[0],
			rectangle.m_vertices[1],
			rectangle.m_vertices[2],
			rectangle.m_vertices[3],
		};

		return *this;

	}

	Convex_reshape& operator=(const Circle& circle)
	{

		delete m_convex->m_vertices;
		m_convex->m_vertex_count = 32;
		m_convex->m_vertices = new Vector2f[32];
		
		for (int i = 0; i < 32; i++)
		{
			m_convex->m_vertices[i] = circle.m_vertices[i];
		}

		return *this;

	}

};

