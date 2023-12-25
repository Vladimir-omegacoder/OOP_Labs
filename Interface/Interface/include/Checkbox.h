#pragma once
#include "Control.h"



class Checkbox_event_args : public Event_args
{

public:

	enum Event_type
	{
		CHECK = 0,
		CURSOR_HOVER = 1,
		CURSOR_AWAY = 3,
	};


private:

	const Event_type event_type;


public:

	Checkbox_event_args(Event_type event_type) : event_type(event_type) {}

};





class Checkbox : public Control
{

private:

	using Checkbox_event_handler = void(*)(Checkbox* sender, Checkbox_event_args* args);

	std::list<Checkbox_event_handler> ñheckbox_check;
	std::list<Checkbox_event_handler> ñheckbox_cursor_hovered;
	std::list<Checkbox_event_handler> ñheckbox_cursor_away;



	bool checked;
	bool cursor_inside;

	sf::RectangleShape ñheckbox_graphics;
	sf::Text checkbox_label;



	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(ñheckbox_graphics, states);
		target.draw(checkbox_label, states);
	}


public:

	Checkbox() = default;

	sf::RectangleShape& get_graphics()
	{
		return ñheckbox_graphics;
	}

	sf::Text& get_text()
	{
		return checkbox_label;
	}



	static void click(Checkbox& checkbox, Checkbox_event_args* args);

	static void click(Checkbox& checkbox);


	static void hover_cursor(Checkbox& checkbox, Checkbox_event_args* args);

	static void hover_cursor(Checkbox& checkbox);


	static void unhover_cursor(Checkbox& checkbox, Checkbox_event_args* args);

	static void unhover_cursor(Checkbox& checkbox);


	void try_click(Checkbox_event_args* args);

	void try_click();


	void try_hover(sf::Vector2i cursor_pos, Checkbox_event_args* args);

	void try_hover(sf::Vector2i cursor_pos);


	void try_unhover(sf::Vector2i cursor_pos, Checkbox_event_args* args);

	void try_unhover(sf::Vector2i cursor_pos);


	bool is_checked()
	{
		return checked;
	}

	bool is_hovered()
	{
		return cursor_inside;
	}


	void add_event_handler(Checkbox_event_handler handler, Checkbox_event_args::Event_type event_type);

	void remove_event_handler(Checkbox_event_handler handler, Checkbox_event_args::Event_type event_type);

};