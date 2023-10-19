#include "Circle.h"





Circle::Circle(float radius, const Vector2f& pos) : m_pos(pos), m_radius(radius)
{
	Transform tr;
	tr.move(Vector2f(pos.x + radius, pos.y + radius));
	
	for (int i = 0; i < 32; i++)
	{
		m_vertices[i] = tr.transform_point(Vector2f(0, 14));
		tr.rotate(-11.25);
	}

	/*m_vertices[0] = Vector2f(0, -radius);

	Transform tr1, tr2;
	tr1.rotate(-11.25);

	for (int i = 1; i < 32; ++i)
	{
		m_vertices[i] = tr1.transform_point(m_vertices[i - 1]);
	}

	tr2.move(Vector2f(pos.x + radius, pos.y + radius));

	for (int i = 0; i < 32; ++i)
	{
		m_vertices[i] = tr2.transform_point(m_vertices[i]);
	}*/
}



float Circle::get_radius() const
{
	return m_radius;
}
