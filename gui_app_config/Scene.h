#pragma once
#include "../graphics/Primitives.h"
#include <list>



#define SCENE_SIZE sf::Vector2u(800, 520)
#define SELECTION_COLOR sf::Color::Yellow


class Scene : sf::Drawable
{

public:

	class Actor : sf::Drawable
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
					shape_actor->set_outline_color(Scene::selection_color);
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
			: shape_actor(shape), selected(selected), visible(visible) {}

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



	static sf::Color selection_color;
	sf::Sprite background;

	std::list<Actor> actors;
	std::list<Actor*> selection;
	Controller controller;



	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {}


public:

	Scene() = default;

	Scene(const Scene& other) = delete;



	sf::Sprite& get_backgruond() 
	{
		return background;
	}

	sf::Color& get_selection_color()
	{
		return selection_color;
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
		actors.push_back(actor);
	}



	void select_actor(Actor* actor)
	{
		controller.select_actor(actor);
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

			if (mouse_pos.x < shape_bounds.left || mouse_pos.x > shape_bounds.left + shape_bounds.width
				|| mouse_pos.y < shape_bounds.top || mouse_pos.y > shape_bounds.top + shape_bounds.height)
			{
				continue;
			}

			i.select();

			return controller.get_selected_actor();

		}

		controller.diselect();

		return nullptr;

	}








};