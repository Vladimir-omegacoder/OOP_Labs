#pragma once
#include "Shape.h"




class Regular : public Shape
{

protected:

	sf::CircleShape polygon;



	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


public:

	Regular(float side_length, size_t point_count) : polygon(side_length / 2 * sin(3.1415926535 / point_count), point_count) {}



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


	virtual const sf::Transform& get_transform() const;
	virtual const sf::Transform& get_inverse_transform() const;


	virtual size_t getPointCount() const;
	virtual sf::Vector2f getPoint(std::size_t index) const;



	static Regular triangle(float side_length)
	{
		return Regular(side_length, 3);
	}

	static Regular square(float side_length)
	{
		return Regular(side_length, 4);
	}

	static Regular pentagon(float side_length)
	{
		return Regular(side_length, 5);
	}

	static Regular hexagon(float side_length)
	{
		return Regular(side_length, 6);
	}

};