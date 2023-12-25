#pragma once
#include "Control.h"



class TextboxEventArgs : public Event_args
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

	using TextboxEventHandler = void(*)(Textbox* sender, TextboxEventArgs* args);

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



	static void click(Textbox& textbox, TextboxEventArgs* args)
	{
		textbox.active = true;
		for (auto& handler : textbox.textbox_activate)
		{
			handler(&textbox, args);
		}
	}

	static void click(Textbox& textbox)
	{
		textbox.active = true;
		TextboxEventArgs args(TextboxEventArgs::ACTIVATE);
		for (auto& handler : textbox.textbox_activate)
		{
			handler(&textbox, &args);
		}
	}


	static void release(Textbox& textbox, TextboxEventArgs* args)
	{
		textbox.active = false;
		for (auto& handler : textbox.textbox_release)
		{
			handler(&textbox, args);
		}
	}

	static void release(Textbox& textbox)
	{
		textbox.active = false;
		TextboxEventArgs args(TextboxEventArgs::RELEASE);
		for (auto& handler : textbox.textbox_release)
		{
			handler(&textbox, &args);
		}
	}


	static void hover_cursor(Textbox& textbox, TextboxEventArgs* args)
	{
		textbox.cursor_inside = true;
		for (auto& handler : textbox.textbox_cursor_hovered)
		{
			handler(&textbox, args);
		}
	}

	static void hover_cursor(Textbox& textbox)
	{
		textbox.cursor_inside = true;
		TextboxEventArgs args(TextboxEventArgs::CURSOR_HOVER);
		for (auto& handler : textbox.textbox_cursor_hovered)
		{
			handler(&textbox, &args);
		}
	}


	static void unhover_cursor(Textbox& textbox, TextboxEventArgs* args)
	{
		textbox.cursor_inside = false;
		for (auto& handler : textbox.textbox_cursor_away)
		{
			handler(&textbox, args);
		}
	}

	static void unhover_cursor(Textbox& textbox)
	{
		textbox.cursor_inside = false;
		TextboxEventArgs args(TextboxEventArgs::CURSOR_AWAY);
		for (auto& handler : textbox.textbox_cursor_away)
		{
			handler(&textbox, &args);
		}
	}


	void try_click(TextboxEventArgs* args)
	{
		if (cursor_inside)
		{
			click(*this, args);
		}
	}

	void try_click()
	{
		TextboxEventArgs args(TextboxEventArgs::ACTIVATE);
		if (cursor_inside)
		{
			click(*this, &args);
		}
	}


	void try_release(TextboxEventArgs* args)
	{
		if (!cursor_inside)
		{
			release(*this, args);
		}
	}

	void try_release()
	{
		TextboxEventArgs args(TextboxEventArgs::RELEASE);
		if (!cursor_inside)
		{
			release(*this, &args);
		}
	}


	void try_hover(sf::Vector2i cursor_pos, TextboxEventArgs* args)
	{

		sf::Vector2f a, b;
		a = textbox_graphics.getPosition();
		b = a + textbox_graphics.getSize();

		if (cursor_pos.x >= a.x && cursor_pos.x <= b.x && cursor_pos.y >= a.y && cursor_pos.y <= b.y)
		{
			hover_cursor(*this, args);
		}

	}

	void try_hover(sf::Vector2i cursor_pos)
	{

		TextboxEventArgs args(TextboxEventArgs::CURSOR_HOVER);

		sf::Vector2f a, b;
		a = textbox_graphics.getPosition();
		b = a + textbox_graphics.getSize();

		if (cursor_pos.x >= a.x && cursor_pos.x <= b.x && cursor_pos.y >= a.y && cursor_pos.y <= b.y)
		{
			hover_cursor(*this, &args);
		}

	}


	void try_unhover(sf::Vector2i cursor_pos, TextboxEventArgs* args)
	{

		sf::Vector2f a, b;
		a = textbox_graphics.getPosition();
		b = a + textbox_graphics.getSize();

		if (cursor_pos.x < a.x || cursor_pos.x > b.x || cursor_pos.y < a.y || cursor_pos.y > b.y)
		{
			unhover_cursor(*this, args);
		}

	}

	void try_unhover(sf::Vector2i cursor_pos)
	{

		TextboxEventArgs args(TextboxEventArgs::CURSOR_AWAY);

		sf::Vector2f a, b;
		a = textbox_graphics.getPosition();
		b = a + textbox_graphics.getSize();

		if (cursor_pos.x < a.x || cursor_pos.x > b.x || cursor_pos.y < a.y || cursor_pos.y > b.y)
		{
			unhover_cursor(*this, &args);
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

	void remove_event_handler(TextboxEventHandler handler, TextboxEventArgs::Event_type event_type)
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