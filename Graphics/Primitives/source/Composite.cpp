#include "../include/Composite.h"



void Composite::set_position(float x, float y)
{
	for (size_t i = 0; i < arr_size; i++)
	{
		shapes_arr[i]->set_position(x, y);
	}
}

void Composite::set_position(const sf::Vector2f& position)
{
	for (size_t i = 0; i < arr_size; i++)
	{
		shapes_arr[i]->set_position(position);
	}
}

void Composite::set_rotation(float angle)
{
	for (size_t i = 0; i < arr_size; i++)
	{
		shapes_arr[i]->set_rotation(angle);
	}
}

void Composite::set_scale(float factor_x, float factor_y)
{
	for (size_t i = 0; i < arr_size; i++)
	{
		shapes_arr[i]->set_scale(factor_x, factor_y);
	}
}

void Composite::set_scale(const sf::Vector2f& factors)
{
	for (size_t i = 0; i < arr_size; i++)
	{
		shapes_arr[i]->set_scale(factors);
	}
}







void Composite::set_fill_color(const sf::Color color)
{
	for (size_t i = 0; i < arr_size; i++)
	{
		shapes_arr[i]->set_fill_color(color);
	}
}

void Composite::set_outline_color(const sf::Color color)
{
	for (size_t i = 0; i < arr_size; i++)
	{
		shapes_arr[i]->set_outline_color(color);
	}
}



void Composite::set_outline_thickness(float thickness)
{
	for (size_t i = 0; i < arr_size; i++)
	{
		shapes_arr[i]->set_outline_thickness(thickness);
	}
}



void Composite::set_texture(const sf::Texture* texture, bool reset_rect)
{
	for (size_t i = 0; i < arr_size; i++)
	{
		shapes_arr[i]->set_texture(texture, reset_rect);
	}
}



void Composite::move(float offset_x, float offset_y)
{
	for (size_t i = 0; i < arr_size; i++)
	{
		shapes_arr[i]->move(offset_x, offset_y);
	}
}

void Composite::move(const sf::Vector2f& offset)
{
	for (size_t i = 0; i < arr_size; i++)
	{
		shapes_arr[i]->move(offset);
	}
}

void Composite::rotate(float angle)
{
	for (size_t i = 0; i < arr_size; i++)
	{
		shapes_arr[i]->rotate(angle);
	}
}

void Composite::scale(float factor_x, float factor_y)
{
	for (size_t i = 0; i < arr_size; i++)
	{
		shapes_arr[i]->scale(factor_x, factor_y);
	}
}

void Composite::scale(const sf::Vector2f& factor)
{
	for (size_t i = 0; i < arr_size; i++)
	{
		shapes_arr[i]->scale(factor);
	}
}



const sf::Vector2f& Composite::get_position() const
{

	if (arr_size == 0)
	{
		throw std::out_of_range("Composite was empty");
	}

	return shapes_arr[0]->get_position();

}

float Composite::get_rotation() const
{

	if (arr_size == 0)
	{
		throw std::out_of_range("Composite was empty");
	}

	return shapes_arr[0]->get_rotation();

}

const sf::Vector2f& Composite::get_scale() const
{
	
	if (arr_size == 0)
	{
		throw std::out_of_range("Composite was empty");
	}

	return shapes_arr[0]->get_scale();

}



const sf::Vector2f& Composite::get_origin() const
{

	if (arr_size == 0)
	{
		throw std::out_of_range("Composite was empty");
	}

	return shapes_arr[0]->get_origin();

}



const sf::Color& Composite::get_fill_color() const
{
	
	if (arr_size == 0)
	{
		throw std::out_of_range("Composite was empty");
	}

	return shapes_arr[0]->get_fill_color();

}

const sf::Color& Composite::get_outline_color() const
{
	
	if (arr_size == 0)
	{
		throw std::out_of_range("Composite was empty");
	}

	return shapes_arr[0]->get_fill_color();

}



float Composite::get_outline_thickness() const
{

	if (arr_size == 0)
	{
		throw std::out_of_range("Composite was empty");
	}

	return shapes_arr[0]->get_outline_thickness();

}



size_t Composite::get_point_count() const
{
	
	if (arr_size == 0)
	{
		throw std::out_of_range("Composite was empty");
	}

	size_t count = 0;
	for (size_t i = 0; i < arr_size; i++)
	{
		count += shapes_arr[i]->get_point_count();
	}

	return count;

}

sf::Vector2f Composite::get_point(size_t index) const
{

	if (arr_size == 0)
	{
		throw std::out_of_range("Composite was empty");
	}

	size_t count = 0;
	for (size_t i = 0; i < arr_size; i++)
	{
		size_t current_count = shapes_arr[i]->get_point_count();
		if (count + current_count > index)
		{
			return shapes_arr[i]->get_point(index - count);
		}
	}

	throw std::out_of_range("Index was out of range");

}



const sf::Transform& Composite::get_transform() const
{

	if (arr_size == 0)
	{
		throw std::out_of_range("Composite was empty");
	}

	return shapes_arr[0]->get_transform();

}

const sf::Transform& Composite::get_inverse_transform() const
{
	
	if (arr_size == 0)
	{
		throw std::out_of_range("Composite was empty");
	}

	return shapes_arr[0]->get_inverse_transform();

}







const sf::Texture* Composite::get_texture() const
{
	if (arr_size == 0)
	{
		throw std::out_of_range("Composite was empty");
	}

	return shapes_arr[0]->get_texture();

}
