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


void Circle::set_fill_color(const sf::Color color)
{
    circle.setFillColor(color);
}

void Circle::set_outline_color(const sf::Color color)
{
    circle.setOutlineColor(color);
}



void Circle::set_outline_thickness(float thickness)
{
    circle.setOutlineThickness(thickness);
}



void Circle::set_texture(const sf::Texture* texture, bool reset_rect)
{
    circle.setTexture(texture, reset_rect);
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

const sf::Color& Circle::get_fill_color() const
{
    return circle.getFillColor();
}

const sf::Color& Circle::get_outline_color() const
{
    return circle.getOutlineColor();
}

float Circle::get_outline_thickness() const
{
    return circle.getOutlineThickness();
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



size_t Circle::get_point_count() const
{
    return circle.getPointCount();
}

sf::Vector2f Circle::get_point(size_t index) const
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



sf::FloatRect Circle::get_local_bounds() const
{
    return circle.getLocalBounds();
}

sf::FloatRect Circle::get_global_bounds() const
{
    return circle.getGlobalBounds();
}



const sf::Texture* Circle::get_texture() const
{
    return circle.getTexture();
}



void Circle::serialize(std::ofstream& out) const
{

    float           radius = circle.getRadius();
    sf::Vector2f    position = get_position();
    sf::Vector2f    scale = get_scale();
    sf::Vector2f    origin = get_origin();
    float           rotation = get_rotation();
    float           outline_thickness = get_outline_thickness();
    sf::Color       fill_color = get_fill_color();
    sf::Color       outline_color = get_outline_color();

    out.write((char*)&radius, sizeof(radius));
    out.write((char*)&position, sizeof(position));
    out.write((char*)&scale, sizeof(scale));
    out.write((char*)&origin, sizeof(origin));
    out.write((char*)&rotation, sizeof(rotation));
    out.write((char*)&outline_thickness, sizeof(outline_thickness));
    out.write((char*)&fill_color, sizeof(fill_color));
    out.write((char*)&outline_color, sizeof(outline_color));

}

void Circle::deserialize(std::ifstream& in)
{

    float           radius;
    sf::Vector2f    position;
    sf::Vector2f    scale;
    sf::Vector2f    origin;
    float           rotation;
    float           outline_thickness;
    sf::Color       fill_color;
    sf::Color       outline_color;

    in.read((char*)&radius, sizeof(radius));
    in.read((char*)&position, sizeof(position));
    in.read((char*)&scale, sizeof(scale));
    in.read((char*)&origin, sizeof(origin));
    in.read((char*)&rotation, sizeof(rotation));
    in.read((char*)&outline_thickness, sizeof(outline_thickness));
    in.read((char*)&fill_color, sizeof(fill_color));
    in.read((char*)&outline_color, sizeof(outline_color));

    circle.setRadius(radius);
    set_position(position);
    set_scale(scale);
    set_origin(origin);
    set_rotation(rotation);
    set_outline_thickness(outline_thickness);
    set_fill_color(fill_color);
    set_outline_color(outline_color);

}



void Circle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(circle, states);
}