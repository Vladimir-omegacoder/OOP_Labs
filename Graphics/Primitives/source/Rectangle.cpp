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



void Rectangle::set_fill_color(const sf::Color color)
{
    rect.setFillColor(color);
}

void Rectangle::set_outline_color(const sf::Color color)
{
    rect.setOutlineColor(color);
}



void Rectangle::set_outline_thickness(float thickness)
{
    rect.setOutlineThickness(thickness);
}



void Rectangle::set_texture(const sf::Texture* texture, bool reset_rect)
{
    rect.setTexture(texture, reset_rect);
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



const sf::Color& Rectangle::get_fill_color() const
{
    return rect.getFillColor();
}

const sf::Color& Rectangle::get_outline_color() const
{
    return rect.getOutlineColor();
}



float Rectangle::get_outline_thickness() const
{
    return rect.getOutlineThickness();
}



void Rectangle::move(float offset_x, float offset_y) 
{
    rect.move(offset_x, offset_y);
}

void Rectangle::move(const sf::Vector2f& offset) 
{
    rect.move(offset);
}



void Rectangle::rotate(float angle)
{
    rect.rotate(angle);
}



void Rectangle::scale(float factor_x, float factor_y) 
{
    rect.scale(factor_x, factor_y);
}

void Rectangle::scale(const sf::Vector2f& factor) 
{
    rect.scale(factor);
}



size_t Rectangle::get_point_count() const
{
    return rect.getPointCount();
}

sf::Vector2f Rectangle::get_point(size_t index) const
{
    return rect.getPoint(index);
}



const sf::Transform& Rectangle::get_transform() const 
{
    return rect.getTransform();
}

const sf::Transform& Rectangle::get_inverse_transform() const 
{
    return rect.getInverseTransform();
}



sf::FloatRect Rectangle::get_local_bounds() const
{
    return rect.getLocalBounds();
}

sf::FloatRect Rectangle::get_global_bounds() const
{
    return rect.getGlobalBounds();
}



const sf::Texture* Rectangle::get_texture() const
{
    return rect.getTexture();
}



void Rectangle::serialize(std::ofstream& out) const
{

    sf::Vector2f    size = rect.getSize();
    sf::Vector2f    position = get_position();
    sf::Vector2f    scale = get_scale();
    sf::Vector2f    origin = get_origin();
    float           rotation = get_rotation();
    float           outline_thickness = get_outline_thickness();
    sf::Color       fill_color = get_fill_color();
    sf::Color       outline_color = get_outline_color();

    out.write((char*)&size, sizeof(size));
    out.write((char*)&position, sizeof(position));
    out.write((char*)&scale, sizeof(scale));
    out.write((char*)&origin, sizeof(origin));
    out.write((char*)&rotation, sizeof(rotation));
    out.write((char*)&outline_thickness, sizeof(outline_thickness));
    out.write((char*)&fill_color, sizeof(fill_color));
    out.write((char*)&outline_color, sizeof(outline_color));
    
}

void Rectangle::deserialize(std::ifstream& in)
{

    sf::Vector2f    size;
    sf::Vector2f    position;
    sf::Vector2f    scale;
    sf::Vector2f    origin;
    float           rotation;
    float           outline_thickness;
    sf::Color       fill_color;
    sf::Color       outline_color;

    in.read((char*)&size, sizeof(size));
    in.read((char*)&position, sizeof(position));
    in.read((char*)&scale, sizeof(scale));
    in.read((char*)&origin, sizeof(origin));
    in.read((char*)&rotation, sizeof(rotation));
    in.read((char*)&outline_thickness, sizeof(outline_thickness));
    in.read((char*)&fill_color, sizeof(fill_color));
    in.read((char*)&outline_color, sizeof(outline_color));

    rect.setSize(size);
    set_position(position);
    set_scale(scale);
    set_origin(origin);
    set_rotation(rotation);
    set_outline_thickness(outline_thickness);
    set_fill_color(fill_color);
    set_outline_color(outline_color);

}



void Rectangle::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(rect, states);
}