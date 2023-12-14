#pragma once
#include "Control.h"



class CheckboxEventArgs : public EventArgs
{

public:

	enum Event_type
	{
		CLICK = 0,
		RELEASE = 1,
		CURSOR_HOVER = 2,
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

	std::list<CheckboxEventHandler> ñheckbox_clicked;
	std::list<CheckboxEventHandler> ñheckbox_cursor_hovered;
	std::list<CheckboxEventHandler> ñheckbox_cursor_away;

	bool checked;
	bool cursor_inside;



	sf::RectangleShape ñheckbox_graphics;
	sf::Text 

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(button_graphics, states);
	}


public:

	Button() = default;

	sf::RectangleShape& get_graphics()
	{
		return button_graphics;
	}



	void click()
	{
		clicked = true;
		for (auto& handler : button_clicked)
		{
			handler(this, ButtonEventArgs(ButtonEventArgs::Event_type::CLICK));
		}
	}

	void release()
	{
		clicked = false;
		for (auto& handler : button_released)
		{
			handler(this, ButtonEventArgs(ButtonEventArgs::Event_type::RELEASE));
		}
	}

	void hover_cursor()
	{
		cursor_inside = true;
		for (auto& handler : button_cursor_hovered)
		{
			handler(this, ButtonEventArgs(ButtonEventArgs::Event_type::CURSOR_HOVER));
		}
	}

	void unhover_cursor()
	{
		cursor_inside = false;
		for (auto& handler : button_cursor_away)
		{
			handler(this, ButtonEventArgs(ButtonEventArgs::Event_type::CURSOR_AWAY));
		}
	}



	void try_click()
	{
		if (cursor_inside)
		{
			click();
		}
	}

	void try_release()
	{
		if (!cursor_inside)
		{
			release();
		}
	}

	void try_hover(sf::Vector2i cursor_pos)
	{

		sf::Vector2f a, b;
		a = button_graphics.getPosition();
		b = a + button_graphics.getSize();

		if (cursor_pos.x >= a.x && cursor_pos.x <= b.x && cursor_pos.y >= a.y && cursor_pos.y <= b.y)
		{
			hover_cursor();
		}

	}

	void try_unhover(sf::Vector2i cursor_pos)
	{

		sf::Vector2f a, b;
		a = button_graphics.getPosition();
		b = a + button_graphics.getSize();

		if (cursor_pos.x < a.x || cursor_pos.x > b.x || cursor_pos.y < a.y || cursor_pos.y > b.y)
		{
			unhover_cursor();
		}

	}



	bool is_clicked()
	{
		return clicked;
	}

	bool is_hovered()
	{
		return cursor_inside;
	}



	void add_event_handler(ButtonEventHandler handler, ButtonEventArgs::Event_type event_type)
	{

		switch (event_type)
		{

		case ButtonEventArgs::CLICK:
			button_clicked.push_front(handler);
			break;

		case ButtonEventArgs::RELEASE:
			button_released.push_front(handler);
			break;

		case ButtonEventArgs::CURSOR_HOVER:
			button_cursor_hovered.push_front(handler);
			break;

		case ButtonEventArgs::CURSOR_AWAY:
			button_cursor_away.push_front(handler);
			break;

		default:
			break;

		}

	}

	void remove_event_handler(ButtonEventHandler handler, ButtonEventArgs::Event_type event_type)
	{

		switch (event_type)
		{

		case ButtonEventArgs::CLICK:
			button_clicked.remove(handler);
			break;

		case ButtonEventArgs::RELEASE:
			button_released.remove(handler);
			break;

		case ButtonEventArgs::CURSOR_HOVER:
			button_cursor_hovered.remove(handler);
			break;

		case ButtonEventArgs::CURSOR_AWAY:
			button_cursor_away.remove(handler);
			break;

		default:
			break;

		}

	}

};