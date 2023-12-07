#include "../include/Triangle.h"





void Triangle::set_position(float x, float y)
{
    triangle.setPosition(x, y);
}

void Triangle::set_position(const sf::Vector2f& position)
{
    triangle.setPosition(position);
}



void Triangle::set_rotation(float angle)
{
    triangle.setRotation(angle);
}



void Triangle::set_scale(float factor_x, float factor_y)
{
    triangle.setScale(factor_x, factor_y);
}

void Triangle::set_scale(const sf::Vector2f& factors)
{
    triangle.setScale(factors);
}



void Triangle::set_origin(float x, float y)
{
    triangle.setOrigin(x, y);
}

void Triangle::set_origin(const sf::Vector2f& origin)
{
    triangle.setOrigin(origin);
}



void Triangle::set_color(const sf::Color color)
{
    triangle.setFillColor(color);
}



const sf::Vector2f& Triangle::get_position() const
{
    return triangle.getPosition();
}

float Triangle::get_rotation() const
{
    return triangle.getRotation();
}

const sf::Vector2f& Triangle::get_scale() const
{
    return triangle.getScale();
}

const sf::Vector2f& Triangle::get_origin() const
{
    return triangle.getOrigin();
}

const sf::Color& Triangle::get_color() const
{
    return triangle.getFillColor();
}



void Triangle::move(float offset_x, float offset_y)
{
    triangle.move(offset_x, offset_y);
}

void Triangle::move(const sf::Vector2f& offset)
{
    triangle.move(offset);
}



void Triangle::rotate(float angle)
{
    triangle.rotate(angle);
}



void Triangle::scale(float factor_x, float factor_y)
{
    triangle.scale(factor_x, factor_y);
}

void Triangle::scale(const sf::Vector2f& factor)
{
    triangle.scale(factor);
}



const sf::Transform& Triangle::get_transform() const
{
    return triangle.getTransform();
}

const sf::Transform& Triangle::get_inverse_transform() const
{
    return triangle.getInverseTransform();
}



void Triangle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(triangle, states);
}