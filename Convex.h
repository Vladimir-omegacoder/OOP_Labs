#pragma once
#include "Shape.h"





class Convex : public Shape
{

protected:

	class Convex_utility
	{

	private:

		Convex* m_convex;
		size_t m_begin;
		size_t m_length;


	public:

		Convex_utility(Convex* convex, size_t begin, size_t length) : m_convex(convex), m_begin(begin), m_length(length) {}

		Convex& operator=(const Convex& convex)
		{
			
			size_t insert_size = (convex.m_vertex_count > m_length) ?
				m_length : convex.m_vertex_count;

			if (m_begin + insert_size > m_convex->m_vertex_count)
			{
				insert_size = m_convex->m_vertex_count - m_begin;
			}

			for (size_t i = 0; i < insert_size; i++)
			{
				(*m_convex)[m_begin + i] = convex[i];
			}

			return *m_convex;

		}

	};



	Vector2f* m_vertices;

	size_t m_vertex_count;


public:

	Convex(size_t vertex_count);

	Convex(const Convex& other);

	Convex& operator=(const Convex& other);

	~Convex() { delete[] m_vertices; }



	Vector2f& operator[](int index);

	Vector2f operator[](int index) const;



	Convex_utility operator()(size_t begin, size_t length);



	virtual void move(const Vector2f& offset);

	virtual void rotate(float angle);

	virtual void scale(const Vector2f& factor);

	virtual void apply_transform(const Transform& transform);



	friend std::ostream& operator<<(std::ostream& out, const Convex& convex);

	friend std::istream& operator>>(std::istream& in, Convex& convex);

};

