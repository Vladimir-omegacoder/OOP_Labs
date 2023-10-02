#pragma once





struct Point
{
	float x = 0;
	float y = 0;
};



class Shape
{

private:

	Point m_pos			{ 0, 0 }; // Position
	Point m_origin		{ 0, 0 }; // Origin of the shape


public:


	virtual ~Shape() {}



	virtual void Draw() const = 0;			// Draw the shape

	virtual float Perimeter() const = 0;	// Calculate the perimeter

	virtual float Area() const = 0;			// Calculate the area

};

