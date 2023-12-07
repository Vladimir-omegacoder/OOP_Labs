#include "../include/Line.h"





void Line::set_position(float x, float y) 
{
    rect.setPosition(x, y);
    edge1.setPosition(x, y);
    edge2.setPosition(x, y);
}

void Line::set_position(const sf::Vector2f& position) 
{
    rect.setPosition(position);
    edge1.setPosition(position);
    edge2.setPosition(position);
}



void Line::set_rotation(float angle) 
{
    rect.setRotation(angle);
    edge1.setRotation(angle);
    edge2.setRotation(angle);
}



void Line::set_scale(float factor_x, float factor_y) 
{
    rect.setScale(factor_x, factor_y);
    edge1.setScale(factor_x, factor_y);
    edge2.setScale(factor_x, factor_y);
}

void Line::set_scale(const sf::Vector2f& factors) 
{
    rect.setScale(factors);
    edge1.setScale(factors);
    edge2.setScale(factors);
}



void Line::set_origin(float x, float y) 
{
    edge1.setOrigin(x, y);
    rect.setOrigin(x-rect.getSize().y / 2, y);
    edge2.setOrigin(x-rect.getSize().x, y);
}

void Line::set_origin(const sf::Vector2f& origin) 
{
    edge1.setOrigin(origin);
    rect.setOrigin(origin.x - rect.getSize().y / 2, origin.y);
    edge2.setOrigin(origin.x - rect.getSize().x, origin.y);
}



void Line::set_color(const sf::Color color)
{
    rect.setFillColor(color);
    edge1.setFillColor(color);
    edge2.setFillColor(color);
}



const sf::Vector2f& Line::get_position() const 
{
    return rect.getPosition();
}

float Line::get_rotation() const 
{
    return rect.getRotation();
}

const sf::Vector2f& Line::get_scale() const 
{
    return rect.getScale();
}

const sf::Vector2f& Line::get_origin() const 
{
    return rect.getOrigin();
}

const sf::Color& Line::get_color() const 
{
    return rect.getFillColor();
}



void Line::move(float offset_x, float offset_y) 
{
    rect.move(offset_x, offset_y);
    edge1.move(offset_x, offset_y);
    edge2.move(offset_x, offset_y);
}

void Line::move(const sf::Vector2f& offset) 
{
    rect.move(offset);
    edge1.move(offset);
    edge2.move(offset);
}



void Line::rotate(float angle) 
{
    rect.rotate(angle);
    edge1.rotate(angle);
    edge2.rotate(angle);
}



void Line::scale(float factor_x, float factor_y) 
{
    rect.scale(factor_x, factor_y);
    edge1.scale(factor_x, factor_y);
    edge2.scale(factor_x, factor_y);
}

void Line::scale(const sf::Vector2f& factor) 
{
    rect.scale(factor);
    edge1.scale(factor);
    edge2.scale(factor);
}



const sf::Transform& Line::get_transform() const 
{
    return rect.getTransform();
}

const sf::Transform& Line::get_inverse_transform() const 
{
    return rect.getInverseTransform();
}



void Line::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(rect, states);
    target.draw(edge1, states);
    target.draw(edge2, states);
}