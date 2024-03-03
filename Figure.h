#pragma once
#include "SFML/Graphics.hpp"
#include <fstream>

class Figure
{
protected:
	sf::Color color;
	bool hidden = false;

public:

	virtual ~Figure() {}

	virtual bool get_hidden()
	{
		return hidden;
	}

	virtual void hide()
	{
		hidden = true;
		this->set_ñolor(sf::Color::Transparent);
	}
	virtual void show()
	{	
		hidden = false;
		this->set_ñolor(color);
	}


	virtual void draw(sf::RenderWindow& window) const = 0;
	virtual void move(float x, float y) = 0;
	virtual void scaling(sf::Vector2f a) = 0;


	virtual void set_ñolor(sf::Color color) = 0;
	virtual sf::Color get_ñolor()
	{
		return color;
	}
	virtual sf::Color get_now_color() = 0;

	virtual void set_position(float x, float y) = 0;


	virtual sf::FloatRect get_global_bounds() const = 0;


	virtual void write_to_file(std::ofstream& file) = 0;
	virtual void read_from_file(std::ifstream& file) = 0;
};
