#include "Circle.h"

Circle::Circle(float radius, sf::Color color)
{
	circle = sf::CircleShape(radius);
	this->color = sf::Color::Cyan;
	circle.setFillColor(color);
}

Circle::Circle(const Circle& cir)
{
	this->circle = sf::CircleShape(cir.circle);
	this->color = cir.color;
	this->hidden = cir.hidden;
}

Circle::Circle(float radius)
{
	circle = sf::CircleShape(radius);
	this->color = sf::Color::Cyan;
	circle.setFillColor(color);
}

void Circle::move(float x, float y)
{
	circle.move(x, y);
}

sf::FloatRect Circle::get_global_bounds() const
{
	return circle.getGlobalBounds();
}

void Circle::draw(sf::RenderWindow& window) const
{

	window.draw(circle);

}

//void Circle::set_memento(Memento& memento) const
//{
//	memento.figure = new Circle(*this);
//}
//
//void Circle::get_memento(const Memento& memento)
//{
//	Circle* circle_mem = dynamic_cast<Circle*>(memento.figure);
//
//	circle = sf::CircleShape(circle_mem->circle);
//	this->color = circle_mem->color;
//	this->hidden = circle_mem->hidden;
//}


void Circle::set_position(float x, float y)
{
	circle.setPosition(x, y);
}

void Circle::set_ñolor(sf::Color color)
{
	circle.setFillColor(color);
}

sf::Color Circle::get_now_color()
{
	return circle.getFillColor();
}



void Circle::scaling(sf::Vector2f a)
{
	circle.setScale(a);
}
