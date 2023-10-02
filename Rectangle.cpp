#include "Rectangle.h"



void Rectangle::Draw() const
{

	std::cout << "~~~ Drawing a " << m_width << 'x' << m_height 
		<< " rectangle at " << '(' << m_pos.x << "; " << m_pos.y << ") ~~~";

}

float Rectangle::Perimeter() const
{

	return 2 * (m_width + m_height);

}

float Rectangle::Area() const
{

	return m_width * m_height;

}
