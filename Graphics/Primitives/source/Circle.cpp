#include "../include/Circle.h"





void Circle::set_position(float x, float y)
{
    circle.setPosition(x, y);
}

void Circle::set_position(const sf::Vector2f& position)
{
    circle.setPosition(position);
}



void Circle::set_rotation(float angle)
{
    circle.setRotation(angle);
}



void Circle::set_scale(float factor_x, float factor_y)
{
    circle.setScale(factor_x, factor_y);
}

void Circle::set_scale(const sf::Vector2f& factors)
{
    circle.setScale(factors);
}



void Circle::set_origin(float x, float y)
{
    circle.setOrigin(x, y);
}

void Circle::set_origin(const sf::Vector2f& origin)
{
    circle.setOrigin(origin);
}



void Circle::set_color(const sf::Color color)
{
    circle.setFillColor(color);
}



const sf::Vector2f& Circle::get_position() const
{
    return circle.getPosition();
}

float Circle::get_rotation() const
{
    return circle.getRotation();
}

const sf::Vector2f& Circle::get_scale() const
{
    return circle.getScale();
}

const sf::Vector2f& Circle::get_origin() const
{
    return circle.getOrigin();
}

const sf::Color& Circle::get_color() const
{
    return circle.getFillColor();
}



void Circle::move(float offset_x, float offset_y)
{
    circle.move(offset_x, offset_y);
}

void Circle::move(const sf::Vector2f& offset)
{
    circle.move(offset);
}



void Circle::rotate(float angle)
{
    circle.rotate(angle);
}



void Circle::scale(float factor_x, float factor_y)
{
    circle.scale(factor_x, factor_y);
}

void Circle::scale(const sf::Vector2f& factor)
{
    circle.scale(factor);
}



size_t Circle::getPointCount() const
{
    return circle.getPointCount();
}

sf::Vector2f Circle::getPoint(std::size_t index) const
{
    return circle.getPoint(index);
}



const sf::Transform& Circle::get_transform() const
{
    return circle.getTransform();
}

const sf::Transform& Circle::get_inverse_transform() const
{
    return circle.getInverseTransform();
}



void Circle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(circle, states);
}