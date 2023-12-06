#pragma once
#include "SFML/Graphics.hpp"





class Shape : public sf::Drawable
{

public:

	virtual ~Shape() {}



	virtual void set_position(float x, float y) = 0;
	virtual void set_position(const sf::Vector2f& position) = 0;

	virtual void set_rotation(float angle) = 0;

	virtual void set_scale(float factor_x, float factor_y) = 0;
	virtual void set_scale(const sf::Vector2f& factors) = 0;

	virtual void set_origin(float x, float y) = 0;
	virtual void set_origin(const sf::Vector2f& origin) = 0;


	virtual const sf::Vector2f& get_position() const = 0;

	virtual float get_rotation() const = 0;

	virtual const sf::Vector2f& get_scale() const = 0;

	virtual const sf::Vector2f& get_origin() const = 0;


	virtual void move(float offset_x, float offset_y) = 0;
	virtual void move(const sf::Vector2f& offset) = 0;

	virtual void rotate(float angle) = 0;

	virtual void scale(float factor_x, float factor_y) = 0;
	virtual void scale(const sf::Vector2f& factor) = 0;


	virtual const sf::Transform& get_transform() const = 0;
	virtual const sf::Transform& get_inverse_transform() const = 0;


};

