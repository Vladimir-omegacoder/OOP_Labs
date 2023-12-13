#pragma once
#include "Graphics/Primitives.h"
#include <vector>



class Geometric : public sf::Drawable
{

private:

	Shape* figure;
	sf::VertexArray trail;
	bool visible;
	bool selected;
	bool has_trail;



	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{

		if (!visible)
		{
			return;
		}
		
		if (has_trail)
		{

			/*
			sf::VertexArray arr;
			for (size_t i = 0; i < figure->getPointCount(); i++)
			{
				arr.append(figure->get_transform().transformPoint(figure->getPoint(i)));
			}
			arr.getBounds().;
			
			std::vector<sf::Vertex> arr;
			for (int i = 0; i < figure->getPointCount(); i++)
			{
				arr.push_back(figure->get_transform().transformPoint(figure->getPoint(i)));
			}

			for (int i = 0; i < arr.size(); i++)
			{
				trail.append(arr[i]);
			}
			*/

			//target.draw(trail, states);

		}

		if (selected)
		{

			sf::VertexArray bounds;
			for (int i = 0; i < figure->getPointCount(); i++)
			{
				bounds.append(figure->getPoint(i));
			}

			sf::FloatRect rect_info(bounds.getBounds());

			sf::RectangleShape rect(sf::Vector2f(rect_info.getSize()));
			rect.setFillColor(sf::Color::Transparent);
			rect.setOutlineThickness(3);
			/*rect.setOutlineColor(sf::Color::Yellow);
			rect.setOrigin(rect.getSize() / 2.f);
			rect.setPosition(figure->get_position());
			rect.setRotation(figure->get_rotation());
			rect.setScale(figure->get_scale());*/

			target.draw(rect);

		}

		target.draw(*figure, states);

	}


public:

	static const Geometric line;
	static const Geometric rectangle;
	static const Geometric circle;
	static const Geometric triangle;
	static const Geometric square;
	static const Geometric pentagon;
	static const Geometric hexagon;
	


	Geometric(const Shape& shape) : figure(nullptr), trail(sf::PrimitiveType::TriangleStrip), visible(true), selected(false), has_trail(false)
	{

		if (const Line* temp = dynamic_cast<const Line*>(&shape))
		{
			figure = new Line(*temp);
			figure->set_origin(temp->getPoint(0) + (temp->getPoint(1) - temp->getPoint(0)) / 2.f);
			return;
		}
		if (const Rectangle* temp = dynamic_cast<const Rectangle*>(&shape))
		{
			figure = new Rectangle(*temp);
			figure->set_origin(temp->getPoint(0) + (temp->getPoint(2) - temp->getPoint(0)) / 2.f);
			return;
		}
		if (const Circle* temp = dynamic_cast<const Circle*>(&shape))
		{
			figure = new Circle(*temp);
			figure->set_origin(temp->getPoint(0) + (temp->getPoint(15) - temp->getPoint(0)) / 2.f);
			return;
		}
		if (const Regular* temp = dynamic_cast<const Regular*>(&shape))
		{

			figure = new Regular(*temp);

			sf::Vector2f center;
			for (int i = 0; i < temp->getPointCount(); i++)
			{
				center += temp->getPoint(i);
			}
			center /= float(temp->getPointCount());
			figure->set_origin(center);

			return;

		}

	}

	Geometric(const Geometric& other) : figure(nullptr), trail(sf::PrimitiveType::TriangleStrip), visible(other.visible), selected(other.selected), has_trail(other.has_trail)
	{

		const Shape* shape = other.figure;

		if (const Line* temp = dynamic_cast<const Line*>(shape))
		{
			figure = new Line(*temp);
			figure->set_origin(temp->getPoint(0) + (temp->getPoint(1) - temp->getPoint(0)) / 2.f);
			return;
		}
		if (const Rectangle* temp = dynamic_cast<const Rectangle*>(shape))
		{
			figure = new Rectangle(*temp);
			figure->set_origin(temp->getPoint(0) + (temp->getPoint(2) - temp->getPoint(0)) / 2.f);
			return;
		}
		if (const Circle* temp = dynamic_cast<const Circle*>(shape))
		{
			figure = new Circle(*temp);
			figure->set_origin(temp->getPoint(0) + (temp->getPoint(15) - temp->getPoint(0)) / 2.f);
			return;
		}
		if (const Regular* temp = dynamic_cast<const Regular*>(shape))
		{

			figure = new Regular(*temp);

			sf::Vector2f center;
			for (int i = 0; i < temp->getPointCount(); i++)
			{
				center += temp->getPoint(i);
			}
			center /= float(temp->getPointCount());
			figure->set_origin(center);

			return;

		}

	}

	Geometric& operator=(const Geometric& other)
	{

		if (figure == other.figure)
		{
			return *this;
		}



		delete figure;
		trail.clear();

		const Shape* shape = other.figure;

		if (const Line* temp = dynamic_cast<const Line*>(shape))
		{
			figure = new Line(*temp);
			figure->set_origin(temp->getPoint(0) + (temp->getPoint(1) - temp->getPoint(0)) / 2.f);
		}
		else if (const Rectangle* temp = dynamic_cast<const Rectangle*>(shape))
		{
			figure = new Rectangle(*temp);
			figure->set_origin(temp->getPoint(0) + (temp->getPoint(2) - temp->getPoint(0)) / 2.f);
		}
		else if (const Circle* temp = dynamic_cast<const Circle*>(shape))
		{
			figure = new Circle(*temp);
			figure->set_origin(temp->getPoint(0) + (temp->getPoint(15) - temp->getPoint(0)) / 2.f);
		}
		else if (const Regular* temp = dynamic_cast<const Regular*>(shape))
		{
			figure = new Regular(*temp);

			sf::Vector2f center;
			for (int i = 0; i < temp->getPointCount(); i++)
			{
				center += temp->getPoint(i);
			}
			center /= float(temp->getPointCount());
			figure->set_origin(center);

		}

		visible = other.visible;
		selected = other.selected;
		has_trail = other.has_trail;

		return *this;

	}

	~Geometric()
	{
		delete figure;
	}



	Shape* const get_shape()
	{
		return figure;
	}

	const Shape* const get_shape() const
	{
		return figure;
	}


	bool is_visible() const
	{
		return visible;
	}

	void show()
	{
		visible = true;
	}

	void hide()
	{
		visible = false;
	}


	bool is_active() const
	{
		return selected;
	}

	void select()
	{
		selected = true;
	}

	void diselect()
	{
		selected = false;
	}


	bool with_trail() const
	{
		return has_trail;
	}

	void enable_trail()
	{
		has_trail = true;
	}

	void disable_trail()
	{
		trail.clear();
		has_trail = false;
	}

};

