#pragma once
#include "Shape.h"
#include <iostream>



class Circle : public Shape
{

private:

	Point m_pos;

	float m_radius;

	
public:

	Circle() : m_pos{0, 0}, m_radius(0) {}

	Circle(Point pos, float radius) : m_pos(pos), m_radius(radius) {}



	//-------- Access to the private fields --------

	inline Point	Get_pos() const
	{
		return m_pos;
	}

	inline void		Set_pos(Point pos)
	{
		m_pos = pos;
	}


	inline float	Get_radius() const
	{
		return m_radius;
	}

	inline void		Set_radius(float radius)
	{
		m_radius = radius;
	}

	//-----------------------------------------------



	virtual void	Draw() const override;			// Draw the shape

	virtual float	Perimeter() const override;		// Calculate the perimeter

	virtual float	Area() const override;			// Calculate the area

};

