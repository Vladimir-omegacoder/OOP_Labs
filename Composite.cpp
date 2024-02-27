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



//void Composite::set_memento(Memento& memento) const
//{
//	memento.figure = new Composite(*this);
//}
//
//void Composite::get_memento(const Memento& memento)
//{
//	Composite* composite_mem = dynamic_cast<Composite*>(memento.figure);
//
//	this->color = composite_mem->color;
//	this->hidden = composite_mem->hidden;
//
//
//	for (int i = 0; i < composite_mem->figures.size(); i++)
//	{
//		if (const Circle* circle = dynamic_cast<const Circle*>(composite_mem->figures[i]))
//		{
//			figures.push_back(new Circle(*circle));
//		}
//		else if (const Triangle* triangle = dynamic_cast<const Triangle*>(composite_mem->figures[i]))
//		{
//			figures.push_back(new Triangle(*triangle));
//		}
//		else if (const Square* square = dynamic_cast<const Square*>(composite_mem->figures[i]))
//		{
//			figures.push_back(new Square(*square));
//		}
//		else if (const Composite* composite = dynamic_cast<const Composite*>(composite_mem->figures[i]))
//		{
//			figures.push_back(new Composite(*composite));
//		}
//	}
//}




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
