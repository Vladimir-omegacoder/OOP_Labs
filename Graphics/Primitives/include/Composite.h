#pragma once
#include "Shape.h"





class Composite : public Shape
{

private:

	Shape** shapes_arr;
	size_t arr_capacity;
	size_t arr_size;
	sf::Transformable transformations;



	/*sf::Vector2f calculate_origin() const
	{

		if (arr_size == 0)
		{
			throw std::out_of_range("Composite was empty");
		}

		sf::Vector2f new_origin;

		for (size_t i = 0; i < arr_size; i++)
		{
			new_origin += shapes_arr[i]->get_origin();
		}

		new_origin.x /= arr_size;
		new_origin.y /= arr_size;

		return new_origin;

	}*/


public:

	Composite() : shapes_arr(nullptr), arr_capacity(0), arr_size(0) {}

	Composite(const Composite& other) = delete;

	~Composite()
	{

		for (size_t i = 0; i < arr_size; i++)
		{
			delete shapes_arr[i];
		}

		delete[] shapes_arr;

	}



	void add_shape(Shape*&& shape)
	{

		if (arr_size < arr_capacity)
		{
			shapes_arr[arr_size] = shape;
		}
		else
		{

			if (arr_capacity == 0)
			{
				arr_capacity = 1;
			}

			Shape** temp = shapes_arr;

			shapes_arr = new Shape * [arr_capacity *= 2];

			for (size_t i = 0; i < arr_size; i++)
			{
				shapes_arr[i] = temp[i];
			}

			shapes_arr[arr_size] = shape;

		}

		++arr_size;
		shape = nullptr;

	}

	Shape*& operator[](size_t index)
	{
		return shapes_arr[index];
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