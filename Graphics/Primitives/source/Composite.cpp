#include "../include/Composite.h"





void Composite::set_position(float x, float y)
{
	transformations.setPosition(x, y);
}

void Composite::set_position(const sf::Vector2f& position)
{
	transformations.setPosition(position);
}

void Composite::set_rotation(float angle)
{
	transformations.setRotation(angle);
}

void Composite::set_scale(float factor_x, float factor_y)
{
	transformations.setScale(factor_x, factor_y);
}

void Composite::set_scale(const sf::Vector2f& factors)
{
	transformations.setScale(factors);
}

void Composite::set_origin(float x, float y)
{
	transformations.setOrigin(x, y);
}

void Composite::set_origin(const sf::Vector2f& origin)
{
	transformations.setOrigin(origin);
}





void Composite::set_fill_color(const sf::Color color)
{
	fill_color = color;
	for (size_t i = 0; i < arr_size; i++)
	{
		shapes_arr[i]->set_fill_color(fill_color);
	}
}

void Composite::set_outline_color(const sf::Color color)
{
	outline_color = color;
}



void Composite::set_outline_thickness(float thickness)
{
	outline_thickness = thickness;
}



void Composite::set_texture(const sf::Texture* texture, bool reset_rect)
{
	this->texture = texture;
	this->reset_rect = reset_rect;
}



void Composite::move(float offset_x, float offset_y)
{
	transformations.move(offset_x, offset_y);
}

void Composite::move(const sf::Vector2f& offset)
{
	transformations.move(offset);
}

void Composite::rotate(float angle)
{
	transformations.rotate(angle);
}

void Composite::scale(float factor_x, float factor_y)
{
	transformations.scale(factor_x, factor_y);
}

void Composite::scale(const sf::Vector2f& factor)
{
	transformations.scale(factor);
}



const sf::Vector2f& Composite::get_position() const
{
	return transformations.getPosition();
}

float Composite::get_rotation() const
{
	return transformations.getRotation();
}

const sf::Vector2f& Composite::get_scale() const
{
	return transformations.getScale();
}



const sf::Vector2f& Composite::get_origin() const
{
	return transformations.getOrigin();
}



const sf::Color& Composite::get_fill_color() const
{
	return fill_color;
}

const sf::Color& Composite::get_outline_color() const
{
	return outline_color;
}



float Composite::get_outline_thickness() const
{
	return outline_thickness;
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
	return transformations.getTransform();
}

const sf::Transform& Composite::get_inverse_transform() const
{
	return transformations.getInverseTransform();
}



sf::FloatRect Composite::get_local_bounds() const
{

	if (arr_size == 0)
	{
		throw std::out_of_range("Composite was empty");
	}

	sf::FloatRect local_bounds = shapes_arr[0]->get_global_bounds();

	for (size_t i = 1; i < arr_size; i++)
	{

		sf::FloatRect shape_local_bounds = shapes_arr[i]->get_global_bounds();

		if (shape_local_bounds.left < local_bounds.left)
		{
			local_bounds.left = shape_local_bounds.left;
		}
		if (shape_local_bounds.left + shape_local_bounds.width > local_bounds.left + local_bounds.width)
		{
			local_bounds.width = shape_local_bounds.left + shape_local_bounds.width - local_bounds.left;
		}
		if (shape_local_bounds.top < local_bounds.top)
		{
			local_bounds.top = shape_local_bounds.top;
		}
		if (shape_local_bounds.top + shape_local_bounds.height > local_bounds.top + local_bounds.height)
		{
			local_bounds.height = shape_local_bounds.top + shape_local_bounds.height - local_bounds.top;
		}

	}

	return sf::FloatRect(0, 0, local_bounds.width, local_bounds.height);

}

sf::FloatRect Composite::get_global_bounds() const
{

	if (arr_size == 0)
	{
		throw std::out_of_range("Composite was empty");
	}

	sf::FloatRect local_bounds = shapes_arr[0]->get_global_bounds();

	for (size_t i = 1; i < arr_size; i++)
	{

		sf::FloatRect shape_local_bounds = shapes_arr[i]->get_global_bounds();

		if (shape_local_bounds.left < local_bounds.left)
		{
			local_bounds.width += (local_bounds.left - shape_local_bounds.left);
			local_bounds.left = shape_local_bounds.left;
		}
		if (local_bounds.left + local_bounds.width < shape_local_bounds.left + shape_local_bounds.width)
		{
			local_bounds.width = shape_local_bounds.left + shape_local_bounds.width - local_bounds.left;
		}
		if (shape_local_bounds.top < local_bounds.top)
		{
			local_bounds.height += (local_bounds.top - shape_local_bounds.top);
			local_bounds.top = shape_local_bounds.top;
		}
		if (local_bounds.top + local_bounds.height < shape_local_bounds.top + shape_local_bounds.height)
		{
			local_bounds.height = shape_local_bounds.top + shape_local_bounds.height - local_bounds.top;
		}

	}

	sf::Transform tr = transformations.getTransform();

	sf::FloatRect global_bounds = tr.transformRect(local_bounds);

	return global_bounds;

}





const sf::Texture* Composite::get_texture() const
{
	return texture;
}



void Composite::serialize(std::ofstream& out) const
{

	out.write((char*)&arr_capacity, sizeof(arr_capacity));
	out.write((char*)&arr_size, sizeof(arr_size));
	for (size_t i = 0; i < arr_size; i++)
	{

		int shape_type = -1;

		if (const Line* line = dynamic_cast<const Line*>(shapes_arr[i]))
		{
			shape_type = 1;
		}
		else if (const Rectangle* rectangle = dynamic_cast<const Rectangle*>(shapes_arr[i]))
		{
			shape_type = 2;
		}
		else if (const Circle* circle = dynamic_cast<const Circle*>(shapes_arr[i]))
		{
			shape_type = 3;
		}
		else if (const Regular* regular = dynamic_cast<const Regular*>(shapes_arr[i]))
		{
			shape_type = 4;
		}
		else if (const Composite* composite = dynamic_cast<const Composite*>(shapes_arr[i]))
		{
			shape_type = 5;
		}

		out.write((char*)&shape_type, sizeof(shape_type));

		shapes_arr[i]->serialize(out);

	}
	out.write((char*)&transformations, sizeof(transformations));
	out.write((char*)&fill_color, sizeof(fill_color));
	out.write((char*)&outline_color, sizeof(outline_color));
	out.write((char*)&outline_thickness, sizeof(outline_thickness));

}

void Composite::deserialize(std::ifstream& in)
{

	in.read((char*)&arr_capacity, sizeof(arr_capacity));
	in.read((char*)&arr_size, sizeof(arr_size));
	shapes_arr = new Shape* [arr_capacity] {};
	for (size_t i = 0; i < arr_size; i++)
	{

		int shape_type = -1;
		in.read((char*)&shape_type, sizeof(shape_type));

		Shape* shape = nullptr;

		switch (shape_type)
		{

		case 1:
			shape = new Line(0, 0);
			break;

		case 2:
			shape = new Rectangle(sf::Vector2f(0, 0));
			break;

		case 3:
			shape = new Circle(0);
			break;

		case 4:
			shape = new Regular(0, 0);
			break;

		case 5:
			shape = new Composite();
			break;

		default:
			break;

		}

		shape->deserialize(in);
		shapes_arr[i] = shape;

	}
	in.read((char*)&transformations, sizeof(transformations));
	in.read((char*)&fill_color, sizeof(fill_color));
	in.read((char*)&outline_color, sizeof(outline_color));
	in.read((char*)&outline_thickness, sizeof(outline_thickness));
	texture = nullptr;
	reset_rect = false;

}



void Composite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{

	sf::RenderStates object_states;

	object_states.texture = texture;
	object_states.transform = transformations.getTransform() * states.transform;

	sf::FloatRect global_bounds = get_global_bounds();
	sf::RectangleShape outline(sf::Vector2f(global_bounds.width, global_bounds.height));
	outline.setPosition(global_bounds.left, global_bounds.top);
	outline.setFillColor(sf::Color::Transparent);
	outline.setOutlineThickness(outline_thickness);
	outline.setOutlineColor(outline_color);
	target.draw(outline);

	for (size_t i = 0; i < arr_size; i++)
	{
		target.draw(*shapes_arr[i], object_states);
	}

}



Composite::~Composite()
{

	for (size_t i = 0; i < arr_size; i++)
	{
		delete shapes_arr[i];
	}

	delete[] shapes_arr;

}



void Composite::add_shape(Shape*&& shape)
{

	if (arr_size < arr_capacity)
	{
		shapes_arr[arr_size] = shape;
	}
	else
	{

		if (arr_capacity == 0)
		{
			transformations.setOrigin(shape->get_position());
			transformations.move(shape->get_position());
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