#pragma once
#include "Shape.h"
#include "../../Primitives.h"





class Composite : public Shape
{

private:

	Shape** shapes_arr;
	size_t arr_capacity;
	size_t arr_size;

	sf::Transformable transformations;
	sf::Color fill_color;
	sf::Color outline_color;
	float outline_thickness;
	const sf::Texture* texture;
	bool reset_rect;



	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;


public:

	Composite() : shapes_arr(nullptr), arr_capacity(0), arr_size(0) {}

	Composite(const Composite& other) :
		arr_capacity(other.arr_capacity), arr_size(other.arr_size), shapes_arr(new Shape* [other.arr_capacity] {}),
		transformations(other.transformations), fill_color(other.fill_color), outline_color(other.outline_color),
		outline_thickness(other.outline_thickness), texture(other.texture), reset_rect(other.reset_rect)
	{
		for (size_t i = 0; i < arr_size; i++)
		{
			if (const Line* line = dynamic_cast<const Line*>(other.shapes_arr[i]))
			{
				shapes_arr[i] = new Line(*line);
			}
			if (const Rectangle* rectangle = dynamic_cast<const Rectangle*>(other.shapes_arr[i]))
			{
				shapes_arr[i] = new Rectangle(*rectangle);
			}
			if (const Circle* circle = dynamic_cast<const Circle*>(other.shapes_arr[i]))
			{
				shapes_arr[i] = new Circle(*circle);
			}
			if (const Regular* regular = dynamic_cast<const Regular*>(other.shapes_arr[i]))
			{
				shapes_arr[i] = new Regular(*regular);
			}
			if (const Composite* composite = dynamic_cast<const Composite*>(other.shapes_arr[i]))
			{
				shapes_arr[i] = new Composite(*composite);
			}
		}
	}

	~Composite();



	void add_shape(Shape*&& shape);

	Shape*& operator[](size_t index)
	{
		return shapes_arr[index];
	}

	size_t capacity()
	{
		return arr_capacity;
	}

	size_t size()
	{
		return arr_size;
	}



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
	virtual sf::Vector2f get_point(size_t index) const override;

	virtual const sf::Transform& get_transform() const override;
	virtual const sf::Transform& get_inverse_transform() const override;

	virtual sf::FloatRect get_local_bounds() const override;
	virtual sf::FloatRect get_global_bounds() const override;

	virtual const sf::Texture* get_texture() const override;

};