#include "Triangle.h"

Triangle::Triangle(const Triangle& tri)
{
	this->triangle = sf::CircleShape(tri.triangle);
	this->color = tri.color;
	this->hidden = tri.hidden;
}

Triangle::Triangle(float height)
{
	triangle = sf::CircleShape(height, 3);
	this->color = sf::Color::White;
	triangle.setFillColor(color);
}

Triangle::Triangle(float height, sf::Color color)
{
	triangle = sf::CircleShape(height, 3);
	this->color = sf::Color::White;
	triangle.setFillColor(color);
}

sf::FloatRect Triangle::get_global_bounds() const
{
	return triangle.getGlobalBounds();
}

void Triangle::set_position(float x, float y)
{
	triangle.setPosition(x, y);
}

void Triangle::set_ñolor(sf::Color color)
{
	triangle.setFillColor(color);
}

sf::Color Triangle::get_now_color()
{
	return triangle.getFillColor();
}



void Triangle::move(float x, float y)
{
	triangle.move(x, y);
}

void Triangle::scaling(sf::Vector2f a)
{
	triangle.setScale(a);
}

void Triangle::draw(sf::RenderWindow& window) const
{

	window.draw(triangle);

}

//void Triangle::set_memento(Memento& memento) const
//{
//	memento.figure = new Triangle(*this);
//}
//
//void Triangle::get_memento(const Memento& memento)
//{
//	Triangle* triangle_mem = dynamic_cast<Triangle*>(memento.figure);
//
//	triangle = sf::CircleShape(triangle_mem->triangle);
//	this->color = triangle_mem->color;
//	this->hidden = triangle_mem->hidden;
//}
