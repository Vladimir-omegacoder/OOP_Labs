#include "../include/Textbox.h"





void Textbox::click(Textbox& textbox, Event_args** args, size_t args_count)
{
	textbox.active = true;
	for (size_t i = 0; i < args_count; i++)
	{
		for (auto& handler : textbox.textbox_activate)
		{
			handler(&textbox, args[i]);
		}
	}
}

void Textbox::click(Textbox& textbox)
{
	textbox.active = true;
	Textbox_event_args args(Textbox_event_args::ACTIVATE);
	for (auto& handler : textbox.textbox_activate)
	{
		handler(&textbox, &args);
	}
}



void Textbox::release(Textbox& textbox, Event_args** args, size_t args_count)
{
	textbox.active = false;
	for (size_t i = 0; i < args_count; i++)
	{
		for (auto& handler : textbox.textbox_release)
		{
			handler(&textbox, args[i]);
		}
	}
}

void Textbox::release(Textbox& textbox)
{
	textbox.active = false;
	Textbox_event_args args(Textbox_event_args::RELEASE);
	for (auto& handler : textbox.textbox_release)
	{
		handler(&textbox, &args);
	}
}



void Textbox::hover_cursor(Textbox& textbox, Event_args** args, size_t args_count)
{
	textbox.cursor_inside = true;
	for (size_t i = 0; i < args_count; i++)
	{
		for (auto& handler : textbox.textbox_cursor_hovered)
		{
			handler(&textbox, args[i]);
		}
	}
}

void Textbox::hover_cursor(Textbox& textbox)
{
	textbox.cursor_inside = true;
	Textbox_event_args args(Textbox_event_args::CURSOR_HOVER);
	for (auto& handler : textbox.textbox_cursor_hovered)
	{
		handler(&textbox, &args);
	}
}



void Textbox::unhover_cursor(Textbox& textbox, Event_args** args, size_t args_count)
{
	textbox.cursor_inside = false;
	for (size_t i = 0; i < args_count; i++)
	{
		for (auto& handler : textbox.textbox_cursor_away)
		{
			handler(&textbox, args[i]);
		}
	}
}

void Textbox::unhover_cursor(Textbox& textbox)
{
	textbox.cursor_inside = false;
	Textbox_event_args args(Textbox_event_args::CURSOR_AWAY);
	for (auto& handler : textbox.textbox_cursor_away)
	{
		handler(&textbox, &args);
	}
}



bool Textbox::try_click(Event_args** args, size_t args_count)
{
	if (cursor_inside)
	{
		click(*this, args, args_count);
		return true;
	}
	return false;
}

bool Textbox::try_click()
{
	if (cursor_inside)
	{
		click(*this);
		return true;
	}
	return false;
}



bool Textbox::try_release(Event_args** args, size_t args_count)
{
	if (active && !cursor_inside)
	{
		release(*this, args, args_count);
		return true;
	}
	return false;
}

bool Textbox::try_release()
{
	if (active && !cursor_inside)
	{
		release(*this);
		return true;
	}
	return false;
}



bool Textbox::try_hover(sf::Vector2i cursor_pos, Event_args** args, size_t args_count)
{

	sf::Vector2f a, b;
	a = textbox_graphics.getPosition();
	b = a + textbox_graphics.getLocalBounds().getSize();

	if (cursor_pos.x >= a.x && cursor_pos.x <= b.x && cursor_pos.y >= a.y && cursor_pos.y <= b.y)
	{
		hover_cursor(*this, args, args_count);
		return true;
	}

	return false;

}

bool Textbox::try_hover(sf::Vector2i cursor_pos)
{

	sf::Vector2f a, b;
	a = textbox_graphics.getPosition();
	b = a + textbox_graphics.getLocalBounds().getSize();

	if (cursor_pos.x >= a.x && cursor_pos.x <= b.x && cursor_pos.y >= a.y && cursor_pos.y <= b.y)
	{
		Textbox_event_args args(Textbox_event_args::CURSOR_HOVER);
		hover_cursor(*this);
		return true;
	}

	return false;

}



bool Textbox::try_unhover(sf::Vector2i cursor_pos, Event_args** args, size_t args_count)
{

	sf::Vector2f a, b;
	a = textbox_graphics.getPosition();
	b = a + textbox_graphics.getLocalBounds().getSize();

	if (cursor_pos.x < a.x || cursor_pos.x > b.x || cursor_pos.y < a.y || cursor_pos.y > b.y)
	{
		unhover_cursor(*this, args, args_count);
		return true;
	}

	return false;

}

bool Textbox::try_unhover(sf::Vector2i cursor_pos)
{

	sf::Vector2f a, b;
	a = textbox_graphics.getPosition();
	b = a + textbox_graphics.getLocalBounds().getSize();

	if (cursor_pos.x < a.x || cursor_pos.x > b.x || cursor_pos.y < a.y || cursor_pos.y > b.y)
	{
		Textbox_event_args args(Textbox_event_args::CURSOR_AWAY);
		unhover_cursor(*this);
		return true;
	}

	return false;

}



void Textbox::add_event_handler(Textbox_event_handler handler, Textbox_event_args::Event_type event_type)
{

	switch (event_type)
	{

	case Textbox_event_args::CURSOR_HOVER:
		textbox_cursor_hovered.push_front(handler);
		break;

	case Textbox_event_args::CURSOR_AWAY:
		textbox_cursor_away.push_front(handler);
		break;

	case Textbox_event_args::ACTIVATE:
		textbox_activate.push_front(handler);
		break;

	case Textbox_event_args::RELEASE:
		textbox_release.push_front(handler);
		break;

	default:
		break;

	}

}

void Textbox::remove_event_handler(Textbox_event_handler handler, Textbox_event_args::Event_type event_type)
{

	switch (event_type)
	{

	case Textbox_event_args::CURSOR_HOVER:
		textbox_cursor_hovered.remove(handler);
		break;

	case Textbox_event_args::CURSOR_AWAY:
		textbox_cursor_away.remove(handler);
		break;

	case Textbox_event_args::ACTIVATE:
		textbox_activate.remove(handler);
		break;

	case Textbox_event_args::RELEASE:
		textbox_release.remove(handler);

	default:
		break;

	}

}