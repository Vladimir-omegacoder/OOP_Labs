#pragma once





struct Point
{
	float x = 0;
	float y = 0;

};

Point operator+(const Point a, const Point b)
{
	return Point{ a.x + b.x, a.y + b.y };
}

Point operator-(const Point a, const Point b)
{
	return Point{ a.x - b.x, a.y - b.y };
}



class Shape
{

public:

	virtual ~Shape() {}



	virtual void Draw() const = 0;			// Draw the shape

	virtual float Perimeter() const = 0;	// Calculate the perimeter

	virtual float Area() const = 0;			// Calculate the area

};

