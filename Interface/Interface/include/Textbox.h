#pragma once
#include "Control.h"



class TextboxEventArgs : public EventArgs
{

public:

	enum Event_type
	{
		ACTIVATE = 0,
		RELEASE = 1,
		CURSOR_HOVER = 2,
		CURSOR_AWAY = 3,
	};



	const Event_type event_type;



	TextboxEventArgs(Event_type event_type) : event_type(event_type) {}

};





class Textbox : public Control
{

private:

	using TextboxEventHandler = void(*)(Textbox* sender, TextboxEventArgs args);

	std::list<TextboxEventHandler> textbox_activate;
	std::list<TextboxEventHandler> textbox_release;
	std::list<TextboxEventHandler> textbox_cursor_hovered;
	std::list<TextboxEventHandler> textbox_cursor_away;



	bool active;
	bool cursor_inside;

	sf::RectangleShape textbox_graphics;
	sf::Text textbox_content;



	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(textbox_graphics, states);
		target.draw(textbox_content, states);
	}


public:

	Textbox() = default;

	sf::RectangleShape& get_graphics()
	{
		return textbox_graphics;
	}

	sf::Text& get_text()
	{
		return textbox_content;
	}



	void click()
	{
		active = true;
		for (auto& handler : textbox_activate)
		{
			handler(this, TextboxEventArgs(TextboxEventArgs::Event_type::ACTIVATE));
		}
	}

	void release()
	{
		active = false;
		for (auto& handler : textbox_activate)
		{
			handler(this, TextboxEventArgs(TextboxEventArgs::Event_type::RELEASE));
		}
	}

	void hover_cursor()
	{
		cursor_inside = true;
		for (auto& handler : textbox_cursor_hovered)
		{
			handler(this, TextboxEventArgs(TextboxEventArgs::Event_type::CURSOR_HOVER));
		}
	}

	void unhover_cursor()
	{
		cursor_inside = false;
		for (auto& handler : textbox_cursor_away)
		{
			handler(this, TextboxEventArgs(TextboxEventArgs::Event_type::CURSOR_AWAY));
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
		a = textbox_graphics.getPosition();
		b = a + textbox_graphics.getSize();

		if (cursor_pos.x >= a.x && cursor_pos.x <= b.x && cursor_pos.y >= a.y && cursor_pos.y <= b.y)
		{
			hover_cursor();
		}

	}

	void try_unhover(sf::Vector2i cursor_pos)
	{

		sf::Vector2f a, b;
		a = textbox_graphics.getPosition();
		b = a + textbox_graphics.getSize();

		if (cursor_pos.x < a.x || cursor_pos.x > b.x || cursor_pos.y < a.y || cursor_pos.y > b.y)
		{
			unhover_cursor();
		}

	}



	bool is_active()
	{
		return active;
	}

	bool is_hovered()
	{
		return cursor_inside;
	}



	void add_event_handler(TextboxEventHandler handler, TextboxEventArgs::Event_type event_type)
	{

		switch (event_type)
		{

		case TextboxEventArgs::CURSOR_HOVER:
			textbox_cursor_hovered.push_front(handler);
			break;

		case TextboxEventArgs::CURSOR_AWAY:
			textbox_cursor_away.push_front(handler);
			break;

		case TextboxEventArgs::ACTIVATE:
			textbox_activate.push_front(handler);
			break;

		case TextboxEventArgs::RELEASE:
			textbox_release.push_front(handler);
			break;

		default:
			break;

		}

	}

	void remove_event_handler(TextboxEventHandler handler, CheckboxEventArgs::Event_type event_type)
	{

		switch (event_type)
		{

		case TextboxEventArgs::CURSOR_HOVER:
			textbox_cursor_hovered.remove(handler);
			break;

		case TextboxEventArgs::CURSOR_AWAY:
			textbox_cursor_away.remove(handler);
			break;

		case TextboxEventArgs::ACTIVATE:
			textbox_activate.remove(handler);
			break;

		case TextboxEventArgs::RELEASE:
			textbox_release.remove(handler);

		default:
			break;

		}

	}

};