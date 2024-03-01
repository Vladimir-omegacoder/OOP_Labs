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



void Regular::set_fill_color(const sf::Color color)
{
    polygon.setFillColor(color);
}

void Regular::set_outline_color(const sf::Color color)
{
    polygon.setOutlineColor(color);
}



void Regular::set_outline_thickness(float thickness)
{
    polygon.setOutlineThickness(thickness);
}



void Regular::set_texture(const sf::Texture* texture, bool reset_rect)
{
    polygon.setTexture(texture, reset_rect);
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

const sf::Color& Regular::get_fill_color() const
{
    return polygon.getFillColor();
}

const sf::Color& Regular::get_outline_color() const
{
    return polygon.getOutlineColor();
}



float Regular::get_outline_thickness() const
{
    return polygon.getOutlineThickness();
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



sf::FloatRect Regular::get_local_bounds() const
{
    return polygon.getLocalBounds();
}

sf::FloatRect Regular::get_global_bounds() const
{
    return polygon.getGlobalBounds();
}



const sf::Texture* Regular::get_texture() const
{
    return polygon.getTexture();
}



void Regular::serialize(std::ofstream& out) const
{

    float           radius = polygon.getRadius();
    size_t          point_count = get_point_count();
    sf::Vector2f    position = get_position();
    sf::Vector2f    scale = get_scale();
    sf::Vector2f    origin = get_origin();
    float           rotation = get_rotation();
    float           outline_thickness = get_outline_thickness();
    sf::Color       fill_color = get_fill_color();
    sf::Color       outline_color = get_outline_color();

    out.write((char*)&radius, sizeof(radius));
    out.write((char*)&point_count, sizeof(point_count));
    out.write((char*)&position, sizeof(position));
    out.write((char*)&scale, sizeof(scale));
    out.write((char*)&origin, sizeof(origin));
    out.write((char*)&rotation, sizeof(rotation));
    out.write((char*)&outline_thickness, sizeof(outline_thickness));
    out.write((char*)&fill_color, sizeof(fill_color));
    out.write((char*)&outline_color, sizeof(outline_color));

}

void Regular::deserialize(std::ifstream& in)
{

    float           radius;
    size_t          point_count;
    sf::Vector2f    position;
    sf::Vector2f    scale;
    sf::Vector2f    origin;
    float           rotation;
    float           outline_thickness;
    sf::Color       fill_color;
    sf::Color       outline_color;

    in.read((char*)&radius, sizeof(radius));
    in.read((char*)&point_count, sizeof(point_count));
    in.read((char*)&position, sizeof(position));
    in.read((char*)&scale, sizeof(scale));
    in.read((char*)&origin, sizeof(origin));
    in.read((char*)&rotation, sizeof(rotation));
    in.read((char*)&outline_thickness, sizeof(outline_thickness));
    in.read((char*)&fill_color, sizeof(fill_color));
    in.read((char*)&outline_color, sizeof(outline_color));

    polygon.setRadius(radius);
    polygon.setPointCount(point_count);
    set_position(position);
    set_scale(scale);
    set_origin(origin);
    set_rotation(rotation);
    set_outline_thickness(outline_thickness);
    set_fill_color(fill_color);
    set_outline_color(outline_color);

}



size_t Regular::get_point_count() const
{
    return polygon.getPointCount();
}

sf::Vector2f Regular::get_point(size_t index) const
{
    return polygon.getPoint(index);
}



void Regular::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(polygon, states);
}