#pragma once
#include <iostream>
#include "../graphics/Primitives.h"
#include <list>



#define SCENE_SIZE sf::Vector2u(800, 520)
#define SELECTION_COLOR sf::Color::Yellow


class Scene : public sf::Drawable
{

public:

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
					shape_actor->set_outline_color(SELECTION_COLOR);
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



		bool is_selected()
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



		bool is_visible()
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

	};


private:

	class Controller
	{

	private:

		Actor* selected_actor = nullptr;


	public:

		Controller() = default;

		Controller(const Controller& other) = delete;

		void select_actor(Actor* actor)
		{

			if (selected_actor != nullptr)
			{
				selected_actor->diselect();
			}

			selected_actor = actor;
			actor->select();

		}

		void diselect()
		{

			if (selected_actor != nullptr)
			{
				selected_actor->diselect();
			}

			selected_actor = nullptr;

		}

		Actor* get_selected_actor()
		{
			return selected_actor;
		}

	};



	sf::Sprite background;

	std::list<Actor> actors;
	std::list<Actor*> selection;
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

	Scene() = default;

	Scene(const Scene& other) = delete;



	sf::Sprite& get_backgruond() 
	{
		return background;
	}



	void add_to_selection(Actor* actor)
	{
		selection.push_back(actor);
	}

	void clear_selection()
	{
		selection.clear();
	}

	void add_actor(Actor&& actor)
	{
		actors.push_back(std::move(actor));
	}



	void select_actor(Actor* actor)
	{
		controller.select_actor(actor);
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

	Actor* get_selected_actor()
	{
		return controller.get_selected_actor();
	}

	Actor* try_select_actor(sf::Vector2i mouse_pos)
	{

		for (auto& i : actors)
		{

			sf::FloatRect shape_bounds = i->get_global_bounds();
			sf::FloatRect scene_bounds = background.getGlobalBounds();
			shape_bounds.left += scene_bounds.left;
			shape_bounds.top += scene_bounds.top;

			if (mouse_pos.x < shape_bounds.left || mouse_pos.x > shape_bounds.left + shape_bounds.width
				|| mouse_pos.y < shape_bounds.top || mouse_pos.y > shape_bounds.top + shape_bounds.height)
			{
				continue;
			}

			if (!i.is_selected())
			{
				controller.select_actor(&i);
			}

			return controller.get_selected_actor();

		}

		controller.diselect();

		return nullptr;

	}








};