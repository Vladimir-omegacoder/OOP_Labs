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


void Triangle::write_to_file(std::ofstream& file)
{
	float height = triangle.getRadius();

	file.write((char*)&height, sizeof(float));
	file.write((char*)&triangle.getFillColor(), sizeof(sf::Color));
	file.write((char*)&triangle.getPosition(), sizeof(sf::Vector2f));
	file.write((char*)&hidden, sizeof(bool));
	file.write((char*)&triangle.getScale(), sizeof(sf::Vector2f));
}

void Triangle::read_from_file(std::ifstream& file)
{
	float height;
	sf::Color color;
	sf::Vector2f position, scale;
	bool hidden;

	file.read((char*)&height, sizeof(float));
	file.read((char*)&color, sizeof(sf::Color));
	file.read((char*)&position, sizeof(sf::Vector2f));
	file.read((char*)&hidden, sizeof(bool));
	file.read((char*)&scale, sizeof(sf::Vector2f));

	triangle.setRadius(height);
	set_ñolor(color);
	set_position(position.x, position.y);
	if (hidden)
	{
		hide();
	}
	triangle.scale(scale);
}
