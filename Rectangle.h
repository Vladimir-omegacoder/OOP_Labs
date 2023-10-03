#pragma once
#include "Shape.h"
#include <iostream>



class Rectangle : public Shape
{

private:

	Point m_pos;

	float m_width;
	float m_height;


public:

	Rectangle() : m_pos{ 0, 0 }, m_width(0), m_height(0) {}

	Rectangle(Point pos, float width, float height)
		: m_pos(pos), m_width(width), m_height(height) {}


	//-------- Access to the private fields --------

	inline Point	Get_pos() const
	{
		return m_pos;
	}

	inline void		Set_pos(Point pos)
	{
		m_pos = pos;
	}


	inline float	Get_width() const
	{
		return m_width;
	}

	inline void		Set_width(float width)
	{
		m_width = width;
	}


	inline float	Get_height() const
	{
		return m_height;
	}

	inline void		Set_height(float height)
	{
		m_height = height;
	}

	//-----------------------------------------------



	virtual void	Draw() const override;			// Draw the shape

	virtual float	Perimeter() const override;		// Calculate the perimeter

	virtual float	Area() const override;			// Calculate the area

};

