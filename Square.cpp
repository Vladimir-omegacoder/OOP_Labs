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

//void Square::set_memento(Memento& memento) const
//{
//	memento.figure = new Square(*this);
//}
//
//void Square::get_memento(const Memento& memento)
//{
//	Square* square_mem = dynamic_cast<Square*>(memento.figure);
//
//	square = sf::RectangleShape(square_mem->square);
//	this->color = square_mem->color;
//	this->hidden = square_mem->hidden;
//}
