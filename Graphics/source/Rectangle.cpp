#include "..\include\Rectangle.h"





void Rectangle::set_position(float x, float y)
{
	rect.setPosition(x, y);
}

void Rectangle::set_position(const sf::Vector2f& position)
{
	rect.setPosition(position);
}



void Rectangle::set_rotation(float angle) 
{
    rect.setRotation(angle);
}



void Rectangle::set_scale(float factor_x, float factor_y) 
{
    rect.setScale(factor_x, factor_y);
}

void Rectangle::set_scale(const sf::Vector2f& factors) 
{
    rect.setScale(factors);
}



void Rectangle::set_origin(float x, float y) 
{
    rect.setOrigin(x, y);
}

void Rectangle::set_origin(const sf::Vector2f& origin) 
{
    rect.setOrigin(origin);
}



void Rectangle::set_color(const sf::Color color)
{
    rect.setFillColor(color);
}



const sf::Vector2f& Rectangle::get_position() const 
{
    return rect.getPosition();
}

float Rectangle::get_rotation() const 
{
    return rect.getRotation();
}

const sf::Vector2f& Rectangle::get_scale() const 
{
    return rect.getScale();
}

const sf::Vector2f& Rectangle::get_origin() const
{
    return rect.getOrigin();
}

const sf::Color& Rectangle::get_color() const
{
    rect.getFillColor();
}



void Rectangle::move(float offset_x, float offset_y) 
{
    rect.move(offset_x, offset_y);
}

void Rectangle::move(const sf::Vector2f& offset) 
{
    rect.move(offset);
}



void Rectangle::scale(float factor_x, float factor_y) 
{
    rect.scale(factor_x, factor_y);
}

void Rectangle::scale(const sf::Vector2f& factor) 
{
    rect.scale(factor);
}



const sf::Transform& Rectangle::get_transform() const 
{
    return rect.getTransform();
}

const sf::Transform& Rectangle::get_inverse_transform() const 
{
    return rect.getInverseTransform();
}