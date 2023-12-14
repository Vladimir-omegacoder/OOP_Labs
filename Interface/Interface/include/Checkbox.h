#pragma once
#include "Control.h"



class CheckboxEventArgs : public EventArgs
{

public:

	enum Event_type
	{
		CHECK = 0,
		CURSOR_HOVER = 1,
		CURSOR_AWAY = 3,
	};


private:

	Event_type event_type;


public:

	CheckboxEventArgs(Event_type event_type) : event_type(event_type) {}

};





class Checkbox : public Control
{

private:

	using CheckboxEventHandler = void(*)(Checkbox* sender, CheckboxEventArgs args);

	std::list<CheckboxEventHandler> �heckbox_check;
	std::list<CheckboxEventHandler> �heckbox_cursor_hovered;
	std::list<CheckboxEventHandler> �heckbox_cursor_away;



	bool checked;
	bool cursor_inside;

	sf::RectangleShape �heckbox_graphics;
	sf::Text checkbox_label;



	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(�heckbox_graphics, states);
		target.draw(checkbox_label, states);
	}


public:

	Checkbox() = default;

	sf::RectangleShape& get_graphics()
	{
		return �heckbox_graphics;
	}

	sf::Text& get_text()
	{
		return checkbox_label;
	}



	void click()
	{
		checked = !checked;
		for (auto& handler : �heckbox_check)
		{
			handler(this, CheckboxEventArgs(CheckboxEventArgs::Event_type::CHECK));
		}
	}

	void hover_cursor()
	{
		cursor_inside = true;
		for (auto& handler : �heckbox_cursor_hovered)
		{
			handler(this, CheckboxEventArgs(CheckboxEventArgs::Event_type::CURSOR_HOVER));
		}
	}

	void unhover_cursor()
	{
		cursor_inside = false;
		for (auto& handler : �heckbox_cursor_away)
		{
			handler(this, CheckboxEventArgs(CheckboxEventArgs::Event_type::CURSOR_AWAY));
		}
	}



	void try_click()
	{
		if (cursor_inside)
		{
			click();
		}
	}

	void try_hover(sf::Vector2i cursor_pos)
	{

		sf::Vector2f a, b;
		a = �heckbox_graphics.getPosition();
		b = a + �heckbox_graphics.getSize();

		if (cursor_pos.x >= a.x && cursor_pos.x <= b.x && cursor_pos.y >= a.y && cursor_pos.y <= b.y)
		{
			hover_cursor();
		}

	}

	void try_unhover(sf::Vector2i cursor_pos)
	{

		sf::Vector2f a, b;
		a = �heckbox_graphics.getPosition();
		b = a + �heckbox_graphics.getSize();

		if (cursor_pos.x < a.x || cursor_pos.x > b.x || cursor_pos.y < a.y || cursor_pos.y > b.y)
		{
			unhover_cursor();
		}

	}



	bool is_checked()
	{
		return checked;
	}

	bool is_hovered()
	{
		return cursor_inside;
	}



	void add_event_handler(CheckboxEventHandler handler, CheckboxEventArgs::Event_type event_type)
	{

		switch (event_type)
		{

		case CheckboxEventArgs::CHECK:
			�heckbox_check.push_front(handler);
			break;

		case CheckboxEventArgs::CURSOR_HOVER:
			�heckbox_cursor_hovered.push_front(handler);
			break;

		case CheckboxEventArgs::CURSOR_AWAY:
			�heckbox_cursor_away.push_front(handler);
			break;

		default:
			break;

		}

	}

	void remove_event_handler(CheckboxEventHandler handler, CheckboxEventArgs::Event_type event_type)
	{

		switch (event_type)
		{

		case CheckboxEventArgs::CHECK:
			�heckbox_check.remove(handler);
			break;

		case CheckboxEventArgs::CURSOR_HOVER:
			�heckbox_cursor_hovered.remove(handler);
			break;

		case CheckboxEventArgs::CURSOR_AWAY:
			�heckbox_cursor_away.remove(handler);
			break;

		default:
			break;

		}

	}

};