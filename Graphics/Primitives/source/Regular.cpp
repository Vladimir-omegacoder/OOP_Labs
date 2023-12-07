#include "../include/Regular.h"





void Regular::set_position(float x, float y)
{
    polygon.setPosition(x, y);
}

void Regular::set_position(const sf::Vector2f& position)
{
    polygon.setPosition(position);
}



void Regular::set_rotation(float angle)
{
    polygon.setRotation(angle);
}



void Regular::set_scale(float factor_x, float factor_y)
{
    polygon.setScale(factor_x, factor_y);
}

void Regular::set_scale(const sf::Vector2f& factors)
{
    polygon.setScale(factors);
}



void Regular::set_origin(float x, float y)
{
    polygon.setOrigin(x, y);
}

void Regular::set_origin(const sf::Vector2f& origin)
{
    polygon.setOrigin(origin);
}



void Regular::set_color(const sf::Color color)
{
    polygon.setFillColor(color);
}



const sf::Vector2f& Regular::get_position() const
{
    return polygon.getPosition();
}

float Regular::get_rotation() const
{
    return polygon.getRotation();
}

const sf::Vector2f& Regular::get_scale() const
{
    return polygon.getScale();
}

const sf::Vector2f& Regular::get_origin() const
{
    return polygon.getOrigin();
}

const sf::Color& Regular::get_color() const
{
    return polygon.getFillColor();
}



void Regular::move(float offset_x, float offset_y)
{
    polygon.move(offset_x, offset_y);
}

void Regular::move(const sf::Vector2f& offset)
{
    polygon.move(offset);
}



void Regular::rotate(float angle)
{
    polygon.rotate(angle);
}



void Regular::scale(float factor_x, float factor_y)
{
    polygon.scale(factor_x, factor_y);
}

void Regular::scale(const sf::Vector2f& factor)
{
    polygon.scale(factor);
}



const sf::Transform& Regular::get_transform() const
{
    return polygon.getTransform();
}

const sf::Transform& Regular::get_inverse_transform() const
{
    return polygon.getInverseTransform();
}



void Regular::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(polygon, states);
}