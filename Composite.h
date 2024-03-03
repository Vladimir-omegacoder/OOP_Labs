#pragma once
#include<iostream>
#include "Figure.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"
#include <vector>

class Composite: public Figure
{
private:
	std::vector<Figure*> figures;

public:
	Composite()
	{
		this->color = sf::Color::Magenta;
	}

	Composite(const Composite& c)
	{
		this->color = sf::Color::Magenta;
		this->hidden = c.hidden;

		for (int i = 0; i < c.figures.size(); i++)
		{
			if (const Circle* circle = dynamic_cast<const Circle*>(c.figures[i]))
			{
				figures.push_back(new Circle(* circle));
			}
			else if (const Triangle * triangle = dynamic_cast<const Triangle*>(c.figures[i]))
			{
				figures.push_back(new Triangle(*triangle));
			}
			else if (const Square* square = dynamic_cast<const Square*>(c.figures[i]))
			{
				figures.push_back(new Square(*square));
			}
			else if (const Composite* composite = dynamic_cast<const Composite*>(c.figures[i]))
			{
				figures.push_back(new Composite(*composite));
			}
		}
	}
		
	~Composite()
	{
		for (int i = 0; i < figures.size(); i++)
		{
			delete figures[i];
		}
	}


	sf::FloatRect get_global_bounds() const;

	void set_ñolor(sf::Color color);

	void set_position(float x, float y);

	sf::Color get_now_color();


	
	void move(float x, float y);

	void scaling(sf::Vector2f a);

	void draw(sf::RenderWindow& window) const;

	void add_figure(const Figure& f);



	void write_to_file(std::ofstream& file);

	void read_from_file(std::ifstream& file);
};

