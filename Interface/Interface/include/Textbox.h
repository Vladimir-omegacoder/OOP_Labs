#pragma once
#include "Control.h"



class Textbox_event_args : public Event_args
{

public:

	enum Event_type
	{
		ACTIVATE = 0,
		RELEASE = 1,
		CURSOR_HOVER = 2,
		CURSOR_AWAY = 3,
	};


private:

	const Event_type event_type;


public:

	Textbox_event_args(Event_type event_type) : event_type(event_type) {}

};





class Textbox : public Control
{

private:

	using Textbox_event_handler = void(*)(Textbox* sender, Event_args* args);

	std::list<Textbox_event_handler> textbox_activate;
	std::list<Textbox_event_handler> textbox_release;
	std::list<Textbox_event_handler> textbox_cursor_hovered;
	std::list<Textbox_event_handler> textbox_cursor_away;



	bool active;
	bool cursor_inside;

	sf::Sprite textbox_graphics;
	sf::Text textbox_content;



	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(textbox_graphics, states);
		target.draw(textbox_content, states);
	}


public:

	Textbox() = default;

	sf::Sprite& get_graphics()
	{
		return textbox_graphics;
	}

	sf::Text& get_text()
	{
		return textbox_content;
	}



	static void click(Textbox& textbox, Event_args** args, size_t args_count);

	static void click(Textbox& textbox);


	static void release(Textbox& textbox, Event_args** args, size_t args_count);

	static void release(Textbox& textbox);


	static void hover_cursor(Textbox& textbox, Event_args** args, size_t args_count);

	static void hover_cursor(Textbox& textbox);


	static void unhover_cursor(Textbox& textbox, Event_args** args, size_t args_count);

	static void unhover_cursor(Textbox& textbox);


	bool try_click(Event_args** args, size_t args_count);

	bool try_click();


	bool try_release(Event_args** args, size_t args_count);

	bool try_release();


	bool try_hover(sf::Vector2i cursor_pos, Event_args** args, size_t args_count);

	bool try_hover(sf::Vector2i cursor_pos);


	bool try_unhover(sf::Vector2i cursor_pos, Event_args** args, size_t args_count);

	bool try_unhover(sf::Vector2i cursor_pos);



	bool is_active()
	{
		return active;
	}

	bool is_hovered()
	{
		return cursor_inside;
	}



	void add_event_handler(Textbox_event_handler handler, Textbox_event_args::Event_type event_type);

	void remove_event_handler(Textbox_event_handler handler, Textbox_event_args::Event_type event_type);

};