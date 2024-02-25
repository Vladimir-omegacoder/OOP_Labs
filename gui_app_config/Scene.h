#pragma once
#include <iostream>
#include "../graphics/Primitives.h"
#include <list>
#include <algorithm>




class Scene : public sf::Drawable
{

public:

	sf::Vector2u SCENE_SIZE;

	class Actor : public sf::Drawable
	{

		Shape* shape_actor;
		bool selected;
		bool visible;



		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
		{

			if (visible)
			{

				if (selected)
				{
					shape_actor->set_outline_color(sf::Color::Yellow);
				}
				else
				{
					shape_actor->set_outline_color(sf::Color::Transparent);
				}

				target.draw(*shape_actor, states);

			}

		}


	public:

		Actor() : shape_actor(nullptr), selected(false), visible(true) {}

		Actor(Shape* shape, bool selected = false, bool visible = true)
			: shape_actor(shape), selected(selected), visible(visible) 
		{
			shape->set_outline_thickness(3);
		}

		Actor(const Actor& other) = delete;

		Actor(Actor&& other) : shape_actor(other.shape_actor), selected(other.selected), visible(other.visible)
		{
			other.shape_actor = nullptr;
		}

		~Actor()
		{
			delete shape_actor;
		}

		Shape& operator*()
		{
			return *shape_actor;
		}

		Shape* operator->()
		{
			return shape_actor;
		}

		void set_ptr(Shape* shape)
		{
			shape_actor = shape;
		}

		const Shape* get_ptr() const
		{
			return shape_actor;
		}

		Shape* get_ptr()
		{
			return shape_actor;
		}



		bool is_selected() const
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

		friend bool operator==(const Actor& left, const Actor& right);

	};


private:

	class Controller
	{

	private:

		std::list<Actor*> selection;


	public:

		Controller() = default;

		Controller(const Controller& other) = delete;

		void select_actor(Actor* actor)
		{

			for (auto& i : selection)
			{
				i->diselect();
			}
			selection.clear();

			if (actor != nullptr)
			{
				actor->select();
				selection.push_back(actor);
			}

		}

		void add_to_selection(Actor* actor)
		{

			if (actor == nullptr)
			{
				return;
			}

			auto it = std::find(selection.begin(), selection.end(), actor);

			if (it != selection.end())
			{
				(*it)->diselect();
				selection.erase(it);
			}
			else
			{
				actor->select();
				selection.push_back(actor);
			}

		}

		std::list<Actor*>& get_selection()
		{
			return selection;
		}

	};



	sf::Sprite background;

	std::list<Actor> actors;
	std::list<Actor> buffer;
	Controller controller;



	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override 
	{
		target.draw(background, states);
		for (auto& i : actors)
		{
			target.draw(i, background.getTransform());
		}
	}


public:

	Scene(const sf::Vector2u& size) : SCENE_SIZE(size) {}

	Scene(const Scene& other) = delete;



	sf::Sprite& get_backgruond() 
	{
		return background;
	}



	void add_actor(Actor&& actor)
	{
		actors.push_front(std::move(actor));
	}



	void select_actor(Actor* actor, bool add_to_selection = false)
	{

		if (actor == nullptr)
		{
			return;
		}

		if (!add_to_selection)
		{
			controller.select_actor(actor);
		}
		else
		{
			controller.add_to_selection(actor);
		}

	}
	
	bool cursor_inside(sf::Vector2i mouse_pos)
	{
		sf::FloatRect bounds = background.getGlobalBounds();

		if (mouse_pos.x < bounds.left || mouse_pos.x > bounds.left + bounds.width
			|| mouse_pos.y < bounds.top || mouse_pos.y > bounds.top + bounds.height)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	std::list<Actor*>& get_selection()
	{
		return controller.get_selection();
	}

	Actor* try_select_actor(sf::Vector2i mouse_pos, bool add_to_selection = false)
	{

		for (auto& i : actors)
		{

			sf::FloatRect shape_bounds = i->get_global_bounds();
			shape_bounds.left *= background.getScale().x;
			shape_bounds.top *= background.getScale().y;
			shape_bounds.width *= background.getScale().x;
			shape_bounds.height *= background.getScale().y;
			sf::FloatRect scene_bounds = background.getGlobalBounds();
			shape_bounds.left += scene_bounds.left;
			shape_bounds.top += scene_bounds.top;

			if (mouse_pos.x < shape_bounds.left || mouse_pos.x > shape_bounds.left + shape_bounds.width
				|| mouse_pos.y < shape_bounds.top || mouse_pos.y > shape_bounds.top + shape_bounds.height)
			{
				continue;
			}


			if (add_to_selection)
			{
				controller.add_to_selection(&i);
			}
			else
			{
				controller.select_actor(&i);
			}

			return &i;

		}

		for (auto& i : controller.get_selection())
		{
			i->diselect();
		}

		controller.get_selection().clear();

		return nullptr;

	}

	void remove_selected_actors()
	{
		for (auto& i : controller.get_selection())
		{
			actors.remove(*i);
		}
		controller.get_selection().clear();
	}

	void aggregate_selected()
	{

		if (controller.get_selection().size() < 2)
		{
			return;
		}

		Composite* composite = new Composite();
		for (auto& i : controller.get_selection())
		{
			i->diselect();
			i->get_ptr()->set_outline_color(sf::Color::Transparent);
			Shape* temp = i->get_ptr();
			i->set_ptr(nullptr);
			composite->add_shape(std::move(temp));
		}

		for (auto it = actors.begin(); it != actors.end();)
		{
			if (it->get_ptr() == nullptr)
			{
				actors.erase(it);
				it = actors.begin();
				continue;
			}
			++it;
		}

		controller.get_selection().clear();	

		actors.push_back(std::move(Actor(composite)));

		controller.select_actor(&actors.back());

	}

	void selection_to_buffer()
	{

		buffer.clear();

		for (auto& i : controller.get_selection())
		{

			if (const Line* line = dynamic_cast<const Line*>(i->get_ptr()))
			{
				buffer.push_back(new Line(*line));
			}
			else if (const Rectangle* rectangle = dynamic_cast<const Rectangle*>(i->get_ptr()))
			{
				buffer.push_back(new Rectangle(*rectangle));
			}
			else if (const Circle* circle = dynamic_cast<const Circle*>(i->get_ptr()))
			{
				buffer.push_back(new Circle(*circle));
			}
			else if (const Regular* regular = dynamic_cast<const Regular*>(i->get_ptr()))
			{
				buffer.push_back(new Regular(*regular));
			}
			else if (const Composite* composite = dynamic_cast<const Composite*>(i->get_ptr()))
			{
				buffer.push_back(new Composite(*composite));
			}

		}

	}

	void buffer_to_scene()
	{

		for (auto& i : buffer)
		{

			if (const Line* line = dynamic_cast<const Line*>(i.get_ptr()))
			{
				actors.push_back(new Line(*line));
			}
			else if (const Rectangle* rectangle = dynamic_cast<const Rectangle*>(i.get_ptr()))
			{
				actors.push_back(new Rectangle(*rectangle));
			}
			else if (const Circle* circle = dynamic_cast<const Circle*>(i.get_ptr()))
			{
				actors.push_back(new Circle(*circle));
			}
			else if (const Regular* regular = dynamic_cast<const Regular*>(i.get_ptr()))
			{
				actors.push_back(new Regular(*regular));
			}
			else if (const Composite* composite = dynamic_cast<const Composite*>(i.get_ptr()))
			{
				actors.push_back(new Composite(*composite));
			}

		}

	}

};



