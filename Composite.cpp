#include "Composite.h"


void Composite::move(float x, float y)
{
	for (auto& i : figures)
	{
		i->move(x, y);
	}
}

void Composite::scaling(sf::Vector2f a)
{
	for (int i = 0; i < figures.size(); i++)
	{
		figures[i]->scaling(a);
	}
}

void Composite::draw(sf::RenderWindow& window) const
{
	for (auto& i : figures)
	{
		i->draw(window);
	}
}

void Composite::add_figure(const Figure& f)
{
	if (const Circle* circle = dynamic_cast<const Circle*>(&f))
	{
		figures.push_back(new Circle(*circle));
	}
	else if (const Triangle* triangle = dynamic_cast<const Triangle*>(&f))
	{
		figures.push_back(new Triangle(*triangle));
	}
	else if (const Square* square = dynamic_cast<const Square*>(&f))
	{
		figures.push_back(new Square(*square));
	}
	else if (const Composite* composite = dynamic_cast<const Composite*>(&f))
	{
		figures.push_back(new Composite(*composite));
	}

	figures.back()->set_ñolor(sf::Color::Magenta);
}




void Composite::write_to_file(std::ofstream& file)
{
	int size = figures.size();

	file.write((char*)&size, sizeof(int));

	for (int i = 0; i < size; i++)
	{
		char shape_type;

		if (const Circle* circle = dynamic_cast<const Circle*>(figures[i]))
		{
			shape_type = 'C';
		}
		else if (const Triangle* triangle = dynamic_cast<const Triangle*>(figures[i]))
		{
			shape_type = 'T';
		}
		else if (const Square* square = dynamic_cast<const Square*>(figures[i]))
		{
			shape_type = 'S';
		}
		else if (const Composite* composite = dynamic_cast<const Composite*>(figures[i]))
		{
			shape_type = 'K';
		}

		file.write((char*)&shape_type, sizeof(char));

		figures[i]->write_to_file(file);
	}

	file.write((char*)&hidden, sizeof(bool));
}


void Composite::read_from_file(std::ifstream& file)
{
	int size;
	char shape_type;
	bool hidden;

	file.read((char*)&size, sizeof(int));


	for (int i = 0; i < size; i++)
	{
		file.read((char*)&shape_type, sizeof(char));

		if (shape_type == 'C')
		{
			figures.push_back(new Circle(3));
			figures.back()->read_from_file(file);
		}
		else if (shape_type == 'T')
		{
			figures.push_back(new Triangle(3));
			figures.back()->read_from_file(file);
		}
		else if (shape_type == 'S')
		{
			figures.push_back(new Square(3));
			figures.back()->read_from_file(file);
		}
		else if (shape_type == 'K')
		{
			figures.push_back(new Composite());
			figures.back()->read_from_file(file);
		}
	}

	file.read((char*)&hidden, sizeof(bool));
	if (hidden)
	{
		hide();
	}
}


sf::FloatRect Composite::get_global_bounds() const
{

	sf::FloatRect r;

	if (const Circle* circle = dynamic_cast<const Circle*>(figures[0]))
	{
		r = circle->get_global_bounds();
	}
	else if (const Triangle* triangle = dynamic_cast<const Triangle*>(figures[0]))
	{
		r = triangle->get_global_bounds();
	}
	else if (const Square* square = dynamic_cast<const Square*>(figures[0]))
	{
		r = square->get_global_bounds();
	}
	else if (const Composite* composite = dynamic_cast<const Composite*>(figures[0]))
	{
		r = composite->get_global_bounds();
	}


	float x1 = r.getPosition().x;
	float x2 = r.getPosition().x + r.width;
	float y1 = r.getPosition().y;
	float y2 = r.getPosition().y + r.height;



	for (int i = 1; i < figures.size(); i++)
	{
		if (const Circle* circle = dynamic_cast<const Circle*>(figures[i]))
		{
			r = circle->get_global_bounds();
		}
		else if (const Triangle* triangle = dynamic_cast<const Triangle*>(figures[i]))
		{
			r = triangle->get_global_bounds();
		}
		else if (const Square* square = dynamic_cast<const Square*>(figures[i]))
		{
			r = square->get_global_bounds();
		}
		else if (const Composite* composite = dynamic_cast<const Composite*>(figures[i]))
		{
			r = composite->get_global_bounds();
		}




		if (x1 > r.getPosition().x)
		{
			x1 = r.getPosition().x;
		}

		if (y1 > r.getPosition().y)
		{
			y1 = r.getPosition().y;
		}

		if (x2 < r.getPosition().x + r.width)
		{
			x2 = r.getPosition().x + r.width;
		}

		if (y2 < r.getPosition().y + r.height)
		{
			y2 = r.getPosition().y + r.height;
		}
	}

	r.width = x2 - x1;
	r.height = y2 - y1;

	r.left = x1;
	r.top = y1;

	return r;
}

void Composite::set_ñolor(sf::Color color)
{
	for (int i = 0; i < figures.size(); i++)
	{
		figures[i]->set_ñolor(color);
	}
}


void Composite::set_position(float x, float y)
{
	for (int i = 0; i < figures.size(); i++)
	{
		figures[i]->set_position(x, y);
	}
}

sf::Color Composite::get_now_color()
{
	return figures[0]->get_now_color();
}
