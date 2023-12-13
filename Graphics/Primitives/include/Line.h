#pragma once
#include "Shape.h"



class Line : public Shape
{

private:

	sf::RectangleShape rect;
	sf::CircleShape edge1, edge2;



	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


public:

	Line(float length, float thickness) : rect(sf::Vector2f(length - thickness, thickness)), edge1(thickness/2), edge2(thickness/2)
	{
		rect.setOrigin(-thickness / 2, 0);
		edge2.setOrigin(-length + thickness, 0);
	}



	virtual void set_position(float x, float y) override;
	virtual void set_position(const sf::Vector2f& position) override;

	virtual void set_rotation(float angle) override;

	virtual void set_scale(float factor_x, float factor_y);
	virtual void set_scale(const sf::Vector2f& factors);

	virtual void set_origin(float x, float y);
	virtual void set_origin(const sf::Vector2f& origin);


	void set_color(const sf::Color color);


	virtual const sf::Vector2f& get_position() const;

	virtual float get_rotation() const;

	virtual const sf::Vector2f& get_scale() const;

	virtual const sf::Vector2f& get_origin() const;

	const sf::Color& get_color() const;


	virtual void move(float offset_x, float offset_y);
	virtual void move(const sf::Vector2f& offset);

	virtual void rotate(float angle);

	virtual void scale(float factor_x, float factor_y);
	virtual void scale(const sf::Vector2f& factor);


	virtual size_t getPointCount() const;
	virtual sf::Vector2f getPoint(std::size_t index) const;


	virtual const sf::Transform& get_transform() const;
	virtual const sf::Transform& get_inverse_transform() const;

};