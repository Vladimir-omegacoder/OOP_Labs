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



void Line::set_fill_color(const sf::Color color)
{
    rect.setFillColor(color);
    edge1.setFillColor(color);
    edge2.setFillColor(color);
}

void Line::set_outline_color(const sf::Color color)
{
    rect.setOutlineColor(color);
    edge1.setOutlineColor(color);
    edge2.setOutlineColor(color);
}



void Line::set_outline_thickness(float thickness)
{
    rect.setOutlineThickness(thickness);
    edge1.setOutlineThickness(thickness);
    edge2.setOutlineThickness(thickness);
}



void Line::set_texture(const sf::Texture* texture, bool reset_rect)
{
    rect.setTexture(texture, reset_rect);
    edge1.setTexture(texture, reset_rect);
    edge2.setTexture(texture, reset_rect);
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

const sf::Color& Line::get_fill_color() const 
{
    return rect.getFillColor();
}

const sf::Color& Line::get_outline_color() const
{
    return rect.getOutlineColor();
}

float Line::get_outline_thickness() const
{
    return rect.getOutlineThickness();
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



size_t Line::get_point_count() const
{
    return 2;
}

sf::Vector2f Line::get_point(std::size_t index) const
{

    if (index == 0)
    {
        return sf::Vector2f(rect.getPoint(0).x, rect.getPoint(0).y + rect.getSize().y / 2);
    }
    if (index == 1)
    {
        return sf::Vector2f(rect.getPoint(1).x, rect.getPoint(1).y + rect.getSize().y / 2);
    }

    throw std::out_of_range("");

}



const sf::Transform& Line::get_transform() const 
{
    return rect.getTransform();
}

const sf::Transform& Line::get_inverse_transform() const 
{
    return rect.getInverseTransform();
}

sf::FloatRect Line::get_local_bounds() const
{

    sf::FloatRect bounds, edge1_bounds, edge2_bounds, rect_bounds;

    edge1_bounds = edge1.getLocalBounds();
    edge2_bounds = edge2.getLocalBounds();
    rect_bounds = rect.getLocalBounds();

    if (edge1_bounds.left < edge2_bounds.left)
    {
        bounds.left = edge1_bounds.left;
        bounds.width = edge1_bounds.width + rect_bounds.width;
    }
    else
    {
        bounds.left = edge2_bounds.left;
        bounds.width = edge2_bounds.width + rect_bounds.width;
    }

    if (edge1_bounds.top < edge2_bounds.top)
    {
        bounds.top = edge1_bounds.top;
        bounds.height = edge1_bounds.height + rect_bounds.height;
    }
    else
    {
        bounds.top = edge2_bounds.top;
        bounds.height = edge2_bounds.height + rect_bounds.height;
    }
    
    return bounds;

}

sf::FloatRect Line::get_global_bounds() const
{

    sf::FloatRect bounds, edge1_bounds, edge2_bounds, rect_bounds;

    edge1_bounds = edge1.getGlobalBounds();
    edge2_bounds = edge2.getGlobalBounds();
    rect_bounds = rect.getGlobalBounds();

    if (edge1_bounds.left < edge2_bounds.left)
    {
        bounds.left = edge1_bounds.left;
        bounds.width = edge1_bounds.width + rect_bounds.width;
    }
    else
    {
        bounds.left = edge2_bounds.left;
        bounds.width = edge2_bounds.width + rect_bounds.width;
    }

    if (edge1_bounds.top < edge2_bounds.top)
    {
        bounds.top = edge1_bounds.top;
        bounds.height = edge1_bounds.height + rect_bounds.height;
    }
    else
    {
        bounds.top = edge2_bounds.top;
        bounds.height = edge2_bounds.height + rect_bounds.height;
    }

    return bounds;

}



const sf::Texture* Line::get_texture() const
{
    return rect.getTexture();
}



void Line::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(edge1, states);
    target.draw(edge2, states);
    target.draw(rect, states);
}