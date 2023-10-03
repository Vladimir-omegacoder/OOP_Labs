#include "Triangle.h"



void Triangle::Draw() const
{

	std::cout << "~~~ Drawing a triangle with: "
		<< "v1(" << m_v1.x << "; " << m_v1.y << "), "
		<< "v2(" << m_v2.x << "; " << m_v2.y << "), "
		<< "v3(" << m_v3.x << "; " << m_v3.y << ") ~~~\n";

}

float Triangle::Perimeter() const
{

	Point a = m_v2 - m_v1;
	Point b = m_v3 - m_v2;
	Point c = m_v1 - m_v3;

	return float(sqrt(a.x * a.x + a.y * a.y) + sqrt(b.x * b.x + b.y * b.y) + sqrt(c.x * c.x + c.y * c.y));

}

float Triangle::Area() const
{

	Point a = m_v2 - m_v1;
	Point b = m_v3 - m_v2;
	Point c = m_v1 - m_v3;

	float a_len = sqrt(a.x * a.x + a.y * a.y);
	float b_len = sqrt(b.x * b.x + b.y * b.y);
	float c_len = sqrt(c.x * c.x + c.y * c.y);

	float p = (a_len + b_len + c_len) / 2;

	return sqrt(p * (p - a_len) * (p - b_len) * (p - c_len));

}
