#include "Square.h"

Square::Square(const Square& squ)
{
	this->square = sf::RectangleShape(squ.square);
	this->color = squ.color;
	this->hidden = squ.hidden;
}

Square::Square(float side)
{
	square = sf::RectangleShape(sf::Vector2f(side, side));
	this->color = sf::Color::Yellow;
	square.setFillColor(color);
}

Square::Square(float side, sf::Color color)
{
	square = sf::RectangleShape(sf::Vector2f(side, side));
	this->color = sf::Color::Yellow;
	square.setFillColor(color);
}

sf::FloatRect Square::get_global_bounds() const
{
	return square.getGlobalBounds();
}

void Square::set_position(float x, float y)
{
	square.setPosition(x, y);
}

void Square::set_ñolor(sf::Color color)
{
	square.setFillColor(color);
}

sf::Color Square::get_now_color()
{
	return square.getFillColor();
}



void Square::move(float x, float y)
{
	square.move(x, y);
}

void Square::scaling(sf::Vector2f a)
{
	square.setScale(a);
}

void Square::draw(sf::RenderWindow& window) const
{
	window.draw(square);
}


void Square::write_to_file(std::ofstream& file)
{
	float side = square.getSize().x;

	file.write((char*)&side, sizeof(float));
	file.write((char*)&square.getFillColor(), sizeof(sf::Color));
	file.write((char*)&square.getPosition(), sizeof(sf::Vector2f));
	file.write((char*)&hidden, sizeof(bool));
	file.write((char*)&square.getScale(), sizeof(sf::Vector2f));
}

void Square::read_from_file(std::ifstream& file)
{
	float side;
	sf::Color color;
	sf::Vector2f position, scale;
	bool hidden;

	file.read((char*)&side, sizeof(float));
	file.read((char*)&color, sizeof(sf::Color));
	file.read((char*)&position, sizeof(sf::Vector2f));
	file.read((char*)&hidden, sizeof(bool));
	file.read((char*)&scale, sizeof(sf::Vector2f));

	square.setSize(sf::Vector2f(side, side));
	set_ñolor(color);
	set_position(position.x, position.y);
	if (hidden)
	{
		hide();
	}
	square.scale(scale);
}
