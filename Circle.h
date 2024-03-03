#pragma once
#include "Figure.h"

class Circle: public Figure
{
private:

	sf::CircleShape circle;

public:

	Circle(const Circle& cir);

	Circle(float radius);

	Circle(float radius, sf::Color color);

	sf::FloatRect get_global_bounds() const;

	void set_position(float x, float y);

	void set_ñolor(sf::Color color);

	sf::Color get_now_color();



	void move(float x, float y);

	void scaling(sf::Vector2f a);

	void draw(sf::RenderWindow& window) const;



	void write_to_file(std::ofstream& file);

	void read_from_file(std::ifstream& file);

};

