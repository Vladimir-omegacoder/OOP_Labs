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


void Circle::write_to_file(std::ofstream& file)
{
	float radius = circle.getRadius();

	file.write((char*)&radius, sizeof(float));
	file.write((char*)&circle.getFillColor(), sizeof(sf::Color));
	file.write((char*)&circle.getPosition(), sizeof(sf::Vector2f));
	file.write((char*)&hidden, sizeof(bool));
	file.write((char*)&circle.getScale(), sizeof(sf::Vector2f));
}

void Circle::read_from_file(std::ifstream& file)
{
	float radius;
	sf::Color color;
	sf::Vector2f position, scale;
	bool hidden;

	file.read((char*)&radius, sizeof(float));
	file.read((char*)&color, sizeof(sf::Color));
	file.read((char*)&position, sizeof(sf::Vector2f));
	file.read((char*)&hidden, sizeof(bool));
	file.read((char*)&scale, sizeof(sf::Vector2f));

	circle.setRadius(radius);
	set_ñolor(color);
	set_position(position.x, position.y);
	if (hidden)
	{
		hide();
	}
	circle.scale(scale);
}


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
