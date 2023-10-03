#pragma once
#include "Shape.h"
#include <iostream>



class Triangle : public Shape
{

private:

	Point m_v1;
	Point m_v2;
	Point m_v3;


public:

	Triangle() : m_v1{ 0, 0 }, m_v2{ 0, 0 }, m_v3{ 0, 0 } {}

	Triangle(Point v1, Point v2, Point v3)
		: m_v1(v1), m_v2(v2), m_v3(v3) {}



	//-------- Access to the private fields --------

	inline Point	Get_v1() const
	{
		return m_v1;
	}

	inline void		Set_v1(Point v)
	{
		m_v1 = v;
	}


	inline Point	Get_v2() const
	{
		return m_v2;
	}

	inline void		Set_v2(Point v)
	{
		m_v2 = v;
	}


	inline Point	Get_v3() const
	{
		return m_v3;
	}

	inline void		Set_v3(Point v)
	{
		m_v3 = v;
	}

	//-----------------------------------------------



	virtual void	Draw() const override;			// Draw the shape

	virtual float	Perimeter() const override;		// Calculate the perimeter

	virtual float	Area() const override;			// Calculate the area

};

