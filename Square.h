#pragma once
#include "Figure.h"

class Square: public Figure
{
private:

	sf::RectangleShape square;

public:

	Square(const Square& squ);

	Square(float side);

	Square(float side, sf::Color color);

	sf::FloatRect get_global_bounds() const;

	void set_position(float x, float y);

	void set_�olor(sf::Color color);

	sf::Color get_now_color();



	void move(float x, float y);

	void scaling(sf::Vector2f a);

	void draw(sf::RenderWindow& window) const;



	//void set_memento(Memento& memento) const;

	//void get_memento(const Memento& memento);
};
