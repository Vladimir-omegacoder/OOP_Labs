#pragma once
#include <iostream>
#include "../graphics/Primitives.h"
#include <vector>
#include <list>
#include <algorithm>
#include "../graphics/Primitives/include/Serializable.h"





class Scene_memento : public Serializable
{

private:

	friend class Scene;

	struct Data_block : public Serializable
	{

		enum Shape_type
		{
			NONE,
			SHAPE_LINE,
			SHAPE_RECTANGLE,
			SHAPE_CIRCLE,
			SHAPE_REGULAR,
			SHAPE_COMPOSITE,
		};



		Shape_type type = NONE;
		Shape* shape = nullptr;



		Data_block() = default;

		Data_block(Shape_type type, Shape* shape) :
			type(type), shape(shape) {}




		virtual void serialize(std::ofstream& out) const override
		{

			out.write((char*)&type, sizeof(type));
			shape->serialize(out);

		}

		virtual void deserialize(std::ifstream& in) override
		{

			in.read((char*)&type, sizeof(type));

			delete shape;

			switch (type)
			{

			case Scene_memento::Data_block::SHAPE_LINE:
				shape = new Line(0, 0);
				break;

			case Scene_memento::Data_block::SHAPE_RECTANGLE:
				shape = new Rectangle(sf::Vector2f(0, 0));
				break;

			case Scene_memento::Data_block::SHAPE_CIRCLE:
				shape = new Circle(0);
				break;

			case Scene_memento::Data_block::SHAPE_REGULAR:
				shape = new Regular(0, 0);
				break;

			case Scene_memento::Data_block::SHAPE_COMPOSITE:
				shape = new Composite();
				break;

			default:
				break;

			}

			shape->deserialize(in);

		}

	};

	std::vector<Data_block> content;

public:

	Scene_memento() : content(0) {}

	~Scene_memento()
	{
		clear();
	}

	void clear()
	{
		for (auto& i : content)
		{
			delete i.shape;
		}
		content.clear();
	}

	virtual void serialize(std::ofstream& out) const override
	{

		size_t size = content.size();
		out.write((char*)&size, sizeof(size));

		for (auto& i : content)
		{
			i.serialize(out);
		}

	}

	virtual void deserialize(std::ifstream& in) override
	{

		clear();

		size_t size;

		in.read((char*)&size, sizeof(size));

		for (size_t i = 0; i < size; i++)
		{
			Data_block temp;
			temp.deserialize(in);
			content.push_back(temp);
		}

	}

};





class Scene : public sf::Drawable
{

public:

	sf::Vector2u scene_size;

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

		const Shape& operator*() const
		{
			return *shape_actor;
		}

		Shape* operator->()
		{
			return shape_actor;
		}

		const Shape* operator->() const
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

		Controller() = default;


	public:

		Controller(const Controller& other) = delete;
		Controller& operator=(const Controller& other) = delete;

		Controller(Controller&& other) = delete;
		Controller& operator=(Controller&& other) = delete;

		inline static Controller* get_instance()
		{
			static Controller controller;
			return &controller;
		}

		void select_actor(Actor* actor)
		{

			for (auto& i : get_instance()->selection)
			{
				i->diselect();
			}
			get_instance()->selection.clear();

			if (actor != nullptr)
			{
				actor->select();
				get_instance()->selection.push_back(actor);
			}

		}

		void add_to_selection(Actor* actor)
		{

			if (actor == nullptr)
			{
				return;
			}

			auto it = std::find(get_instance()->selection.begin(), get_instance()->selection.end(), actor);

			if (it != get_instance()->selection.end())
			{
				(*it)->diselect();
				get_instance()->selection.erase(it);
			}
			else
			{
				actor->select();
				get_instance()->selection.push_back(actor);
			}

		}

		std::list<Actor*>& get_selection()
		{
			return get_instance()->selection;
		}

	};



	sf::Sprite background;

	std::list<Actor> actors;
	std::list<Actor> buffer;



	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override 
	{
		target.draw(background, states);
		for (auto& i : actors)
		{
			target.draw(i, background.getTransform());
		}
	}

	Scene() = default;


public:

	Scene(const Scene& other) = delete;
	Scene& operator=(const Scene& other) = delete;

	Scene(Scene&& other) = delete;
	Scene& operator=(Scene&& other) = delete;

	inline static Scene* get_instance()
	{
		static Scene scene;
		return &scene;
	}



	void set_scene_size(const sf::Vector2u& size)
	{
		get_instance()->scene_size = size;
	}

	sf::Vector2u get_scene_size() const
	{
		return get_instance()->scene_size;
	}

	sf::Sprite& get_backgruond() 
	{
		return get_instance()->background;
	}



	void add_actor(Actor&& actor)
	{
		get_instance()->actors.push_front(std::move(actor));
	}



	void select_actor(Actor* actor, bool add_to_selection = false)
	{

		if (actor == nullptr)
		{
			return;
		}

		if (!add_to_selection)
		{
			Controller::get_instance()->select_actor(actor);
		}
		else
		{
			Controller::get_instance()->add_to_selection(actor);
		}

	}
	
	bool cursor_inside(sf::Vector2i mouse_pos)
	{
		sf::FloatRect bounds = get_instance()->background.getGlobalBounds();

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
		return Controller::get_instance()->get_selection();
	}

	Actor* try_select_actor(sf::Vector2i mouse_pos, bool add_to_selection = false)
	{

		for (auto& i : get_instance()->actors)
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
				Controller::get_instance()->add_to_selection(&i);
			}
			else
			{
				Controller::get_instance()->select_actor(&i);
			}

			return &i;

		}

		for (auto& i : Controller::get_instance()->get_selection())
		{
			i->diselect();
		}

		Controller::get_instance()->get_selection().clear();

		return nullptr;

	}



	void remove_selected_actors()
	{
		for (auto& i : Controller::get_instance()->get_selection())
		{
			get_instance()->actors.remove(*i);
		}
		Controller::get_instance()->get_selection().clear();
	}

	void aggregate_selected()
	{

		if (Controller::get_instance()->get_selection().size() < 2)
		{
			return;
		}

		Composite* composite = new Composite();
		for (auto& i : Controller::get_instance()->get_selection())
		{
			i->diselect();
			i->get_ptr()->set_outline_color(sf::Color::Transparent);
			Shape* temp = i->get_ptr();
			i->set_ptr(nullptr);
			composite->add_shape(std::move(temp));
		}

		for (auto it = get_instance()->actors.begin(); it != get_instance()->actors.end();)
		{
			if (it->get_ptr() == nullptr)
			{
				get_instance()->actors.erase(it);
				it = get_instance()->actors.begin();
				continue;
			}
			++it;
		}

		Controller::get_instance()->get_selection().clear();

		get_instance()->actors.push_back(std::move(Actor(composite)));

		Controller::get_instance()->select_actor(&get_instance()->actors.back());

	}



	void selection_to_buffer()
	{

		get_instance()->buffer.clear();

		for (auto& i : Controller::get_instance()->get_selection())
		{

			if (const Line* line = dynamic_cast<const Line*>(i->get_ptr()))
			{
				get_instance()->buffer.push_back(new Line(*line));
			}
			else if (const Rectangle* rectangle = dynamic_cast<const Rectangle*>(i->get_ptr()))
			{
				get_instance()->buffer.push_back(new Rectangle(*rectangle));
			}
			else if (const Circle* circle = dynamic_cast<const Circle*>(i->get_ptr()))
			{
				get_instance()->buffer.push_back(new Circle(*circle));
			}
			else if (const Regular* regular = dynamic_cast<const Regular*>(i->get_ptr()))
			{
				get_instance()->buffer.push_back(new Regular(*regular));
			}
			else if (const Composite* composite = dynamic_cast<const Composite*>(i->get_ptr()))
			{
				get_instance()->buffer.push_back(new Composite(*composite));
			}

		}

	}

	void buffer_to_scene()
	{

		for (auto& i : get_instance()->buffer)
		{

			if (const Line* line = dynamic_cast<const Line*>(i.get_ptr()))
			{
				get_instance()->actors.push_back(new Line(*line));
			}
			else if (const Rectangle* rectangle = dynamic_cast<const Rectangle*>(i.get_ptr()))
			{
				get_instance()->actors.push_back(new Rectangle(*rectangle));
			}
			else if (const Circle* circle = dynamic_cast<const Circle*>(i.get_ptr()))
			{
				get_instance()->actors.push_back(new Circle(*circle));
			}
			else if (const Regular* regular = dynamic_cast<const Regular*>(i.get_ptr()))
			{
				get_instance()->actors.push_back(new Regular(*regular));
			}
			else if (const Composite* composite = dynamic_cast<const Composite*>(i.get_ptr()))
			{
				get_instance()->actors.push_back(new Composite(*composite));
			}

		}

	}



	void reset_default_state()
	{
		get_instance()->actors.clear();
		get_instance()->buffer.clear();
		Controller::get_instance()->get_selection().clear();
	}

	void save_state(Scene_memento& memento) const
	{

		memento.clear();

		for (auto& i : get_instance()->actors)
		{
			
			if (const Line* line = dynamic_cast<const Line*>(i.get_ptr()))
			{
				memento.content.push_back(std::move(Scene_memento::Data_block(Scene_memento::Data_block::SHAPE_LINE ,new Line(*line))));
			}
			else if (const Rectangle* rectangle = dynamic_cast<const Rectangle*>(i.get_ptr()))
			{
				memento.content.push_back(std::move(Scene_memento::Data_block(Scene_memento::Data_block::SHAPE_RECTANGLE, new Rectangle(*rectangle))));
			}
			else if (const Circle* circle = dynamic_cast<const Circle*>(i.get_ptr()))
			{
				memento.content.push_back(std::move(Scene_memento::Data_block(Scene_memento::Data_block::SHAPE_CIRCLE, new Circle(*circle))));
			}
			else if (const Regular* regular = dynamic_cast<const Regular*>(i.get_ptr()))
			{
				memento.content.push_back(std::move(Scene_memento::Data_block(Scene_memento::Data_block::SHAPE_REGULAR, new Regular(*regular))));
			}
			else if (const Composite* composite = dynamic_cast<const Composite*>(i.get_ptr()))
			{
				memento.content.push_back(std::move(Scene_memento::Data_block(Scene_memento::Data_block::SHAPE_COMPOSITE, new Composite(*composite))));
			}

		}

	}

	void load_state(const Scene_memento& memento)
	{

		reset_default_state();

		for (auto& i : memento.content)
		{

			if (const Line* line = dynamic_cast<const Line*>(i.shape))
			{
				get_instance()->actors.push_back(Actor(new Line(*line)));
			}
			else if (const Rectangle* rectangle = dynamic_cast<const Rectangle*>(i.shape))
			{
				get_instance()->actors.push_back(Actor(new Rectangle(*rectangle)));
			}
			else if (const Circle* circle = dynamic_cast<const Circle*>(i.shape))
			{
				get_instance()->actors.push_back(Actor(new Circle(*circle)));
			}
			else if (const Regular* regular = dynamic_cast<const Regular*>(i.shape))
			{
				get_instance()->actors.push_back(Actor(new Regular(*regular)));
			}
			else if (const Composite* composite = dynamic_cast<const Composite*>(i.shape))
			{
				get_instance()->actors.push_back(Actor(new Composite(*composite)));
			}

		}

	}

};







class Scene_utils
{

private:

	Scene_memento memento;


public:

	Scene_utils() = default;

	void save_snapshot(const Scene& scene)
	{
		scene.save_state(memento);
	}

	void load_snapshot(Scene& scene)
	{
		scene.load_state(memento);
	}

	void save_snapshot_file(const char* filename) const
	{

		std::ofstream out;
		out.exceptions(std::ofstream::badbit | std::ofstream::failbit);

		try
		{
			out.open(filename, std::ios_base::trunc);
			memento.serialize(out);
			out.close();
		}
		catch (const std::exception& ex)
		{
			std::cerr << ex.what() << '\n';
		}

	}

	void load_snapshot_file(const char* filename)
	{

		std::ifstream in;
		in.exceptions(std::ofstream::badbit | std::ofstream::failbit);

		try
		{
			in.open(filename);
			memento.deserialize(in);
			in.close();
		}
		catch (const std::exception& ex)
		{
			std::cerr << ex.what() << '\n';
		}

	}

};