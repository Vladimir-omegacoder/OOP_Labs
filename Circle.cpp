#include "Circle.h"



void Circle::Draw() const
{

	std::cout << "~~~ Drawing a " << m_radius
		<< " radius circle at " << '(' << m_pos.x << "; " << m_pos.y << ") ~~~\n";

}

float Circle::Perimeter() const
{

	return 2.f * 3.14159265359f * m_radius;

}

float Circle::Area() const
{

	return 3.14159265359f * m_radius * m_radius;

}
