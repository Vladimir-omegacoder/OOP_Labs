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
					//shape_actor->set_outline_color(Scene::selection_color);
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

		void select_actor(Actor& actor)
		{

			if (selected_actor != nullptr)
			{
				selected_actor->diselect();
			}

			selected_actor = &actor;
			actor.select();

		}

		Actor& get_selected_actor()
		{
			return *selected_actor;
		}

	};



	std::list<Actor> actors;
	std::list<Actor*const> selection;
	sf::Sprite background;
	sf::Color selection_color;
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



	bool try_select_actor(sf::Vector2i mouse_pos)
	{
		// TODO
	}



	void add_actor(const Actor& actor)
	{
		actors.push_back(actor);
		controller.select_actor(actors.back());
	}

	Actor& get_selected_actor()
	{
		return controller.get_selected_actor();
	}

	std::list<Actor*const>::iterator get_selection()
	{
		return selection.begin();
	}



};