#pragma once
#include "Figure.h"

class Triangle: public Figure
{
private:

	sf::CircleShape triangle;

public:

	Triangle(const Triangle& tri);

	Triangle(float height);

	Triangle(float height, sf::Color color);

	sf::FloatRect get_global_bounds() const;

	void set_position(float x, float y);

	void set_ñolor(sf::Color color);

	sf::Color get_now_color();





	void move(float x, float y);

	void scaling(sf::Vector2f a);

	void draw(sf::RenderWindow& window) const;



	//void set_memento(Memento& memento) const;

	//void get_memento(const Memento& memento);
};

