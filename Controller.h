#pragma once
#include "Figure.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Composite.h"
#include <vector>

class Controller: public sf::Drawable
{
public:
	std::vector<Figure*> figures;

	Figure* actve = nullptr;

	Figure* buffer = nullptr;

	sf::Color befor_activ_color;




	sf::FloatRect get_bound(Figure* f)
	{
		sf::FloatRect r;

		if (const Circle* circle = dynamic_cast<const Circle*>(f))
		{
			r = circle->get_global_bounds();
		}
		else if (const Triangle* triangle = dynamic_cast<const Triangle*>(f))
		{
			r = triangle->get_global_bounds();
		}
		else if (const Square* square = dynamic_cast<const Square*>(f))
		{
			r = square->get_global_bounds();
		}
		else if (const Composite* composite = dynamic_cast<const Composite*>(f))
		{
			r = composite->get_global_bounds();
		}

		return r;
	}

	bool in_square(float x, float y, float width, float height, sf::Vector2i v)
	{
		if (v.x >= x && v.x <= x + width && v.y >= y && v.y <= y + height)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void in_window(Figure* f, sf::RenderWindow& main_window)
	{
		sf::FloatRect r = get_bound(f);


		if (r.left < 0)
		{
			f->move(main_window.getSize().x - r.width, 0);
		}
		else if (r.left + r.width > main_window.getSize().x)
		{
			f->move(-(float)main_window.getSize().x + r.width, 0);
		}
		else if (r.top < 0)
		{
			f->move(0, main_window.getSize().y - r.height);
		}

		else if (r.top + r.height > main_window.getSize().y)
		{
			f->move(0, -(float)main_window.getSize().y + r.height);
		}
	}


	Figure* click_figure(sf::Vector2i mouse_pos)
	{
		sf::FloatRect r;

		for (auto& i : figures)
		{
			r = get_bound(i);

			if (in_square(r.getPosition().x, r.getPosition().y, r.width, r.height, mouse_pos))
			{
				return i;
			}
		}

		return nullptr;
	}



	void intersects()
	{
		for (auto& i : figures)
		{
			if (actve->get_global_bounds().intersects(i->get_global_bounds()) == true)
			{
				if (actve != i)
				{
					i->set_�olor(sf::Color::Green);
				}
			}
		}
	}



	void copy()
	{
		if (actve)
		{
			if (buffer != nullptr)
			{
				delete buffer;
				buffer = nullptr;
			}

			if (Circle* circle_ptr = dynamic_cast<Circle*>(actve))
			{
				buffer = new Circle(*circle_ptr);
			}
			else if (Square* square_ptr = dynamic_cast<Square*>(actve))
			{
				buffer = new Square (*square_ptr);
			}
			else if (Triangle* triangle_ptr = dynamic_cast<Triangle*>(actve))
			{			
				buffer = new Triangle (*triangle_ptr);
			}
			else if (Composite* composite_ptr = dynamic_cast<Composite*>(actve))
			{			
				buffer = new Composite (*composite_ptr);
			}

			buffer->set_�olor(befor_activ_color);
		}
		else
		{
			buffer = nullptr;
		}
	}

	void paste()
	{
		if (buffer)
		{
			if (Circle* circle_ptr = dynamic_cast<Circle*>(buffer))
			{
				figures.push_back(new Circle(*circle_ptr));
			}
			else if (Square* square_ptr = dynamic_cast<Square*>(buffer))
			{
				figures.push_back(new Square(*square_ptr));
			}
			else if (Triangle* triangle_ptr = dynamic_cast<Triangle*>(buffer))
			{
				figures.push_back(new Triangle(*triangle_ptr));
			}
			else if (Composite* composite_ptr = dynamic_cast<Composite*>(buffer))
			{
				figures.push_back(new Composite(*composite_ptr));
			}
		}
	}





	bool activate_figure(Figure* i)
	{
		if (i)
		{
			if (actve)
			{
				actve->set_�olor(befor_activ_color);
			}

			actve = i;

			befor_activ_color = actve->get_now_color();

			actve->set_�olor(sf::Color::Red);

			return true;
		}

		else
		{
			if (actve)
			{
				if (actve->get_hidden())
				{
					actve->set_�olor(sf::Color::Transparent);
				}
				else
				{
					actve->set_�olor(befor_activ_color);
				}

				actve = nullptr;
			}

			return false;
		}
	}

	void add_compose(Figure* i)
	{
		if (i)
		{
			Composite* copm = new Composite();

			sf::Color color_i = i->get_�olor();

			i->set_�olor(sf::Color::Blue);

			copm->add_figure(*i);

			copm->add_figure(*actve);

			i->set_�olor(color_i);

			figures.push_back(copm);



			activate_figure(figures.back());
		}
	}


	void add_figure(Figure* i)
	{
		figures.push_back(i);
	}


	~Controller()
	{
		for (auto& i : figures)
		{
			delete i;
		}
	}
	

private:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		for (auto& i : figures)
		{
			i->draw((sf::RenderWindow&)target);
		}
	}
};

