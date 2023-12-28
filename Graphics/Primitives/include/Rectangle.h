#pragma once
#include "Shape.h"



class Rectangle : public Shape
{

private:

	sf::RectangleShape rect;



	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


public:

	Rectangle(const sf::Vector2f& size = sf::Vector2f(0, 0)) : rect(size) {}



	virtual void set_position(float x, float y) override;
	virtual void set_position(const sf::Vector2f& position) override;
	virtual void set_rotation(float angle) override;
	virtual void set_scale(float factor_x, float factor_y) override;
	virtual void set_scale(const sf::Vector2f& factors) override;

	virtual void set_origin(float x, float y) override;
	virtual void set_origin(const sf::Vector2f& origin) override;

	virtual void set_fill_color(const sf::Color color) override;
	virtual void set_outline_color(const sf::Color color) override;

	virtual void set_outline_thickness(float thickness) override;

	virtual void set_texture(const sf::Texture* texture, bool reset_rect = false) override;



	virtual void move(float offset_x, float offset_y) override;
	virtual void move(const sf::Vector2f& offset) override;
	virtual void rotate(float angle) override;
	virtual void scale(float factor_x, float factor_y) override;
	virtual void scale(const sf::Vector2f& factor) override;



	virtual const sf::Vector2f& get_position() const override;
	virtual float get_rotation() const override;
	virtual const sf::Vector2f& get_scale() const override;

	virtual const sf::Vector2f& get_origin() const override;

	virtual const sf::Color& get_fill_color() const override;
	virtual const sf::Color& get_outline_color() const override;

	virtual float get_outline_thickness() const override;

	virtual size_t get_point_count() const override;
	virtual sf::Vector2f get_point(std::size_t index) const override;

	virtual const sf::Transform& get_transform() const override;
	virtual const sf::Transform& get_inverse_transform() const override;

	virtual sf::FloatRect get_local_bounds() const override;
	virtual sf::FloatRect get_global_bounds() const override;

	virtual const sf::Texture* get_texture() const override;

};