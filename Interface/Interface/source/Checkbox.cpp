#include "../include/Checkbox.h"





void Checkbox::click(Checkbox& checkbox, Event_args** args, size_t args_count)
{
	checkbox.checked = !checkbox.checked;
	for (size_t i = 0; i < args_count; i++)
	{
		for (auto& handler : checkbox.�heckbox_check)
		{
			handler(&checkbox, args[i]);
		}
	}
}

void Checkbox::click(Checkbox& checkbox)
{
	checkbox.checked = !checkbox.checked;
	Checkbox_event_args args(Checkbox_event_args::Event_type::CHECK);
	for (auto& handler : checkbox.�heckbox_check)
	{
		handler(&checkbox, &args);
	}
}



void Checkbox::hover_cursor(Checkbox& checkbox, Event_args** args, size_t args_count)
{
	checkbox.cursor_inside = true;
	for (size_t i = 0; i < args_count; i++)
	{
		for (auto& handler : checkbox.�heckbox_cursor_hovered)
		{
			handler(&checkbox, args[i]);
		}
	}
}

void Checkbox::hover_cursor(Checkbox& checkbox)
{
	checkbox.cursor_inside = true;
	Checkbox_event_args args(Checkbox_event_args::Event_type::CURSOR_HOVER);
	for (auto& handler : checkbox.�heckbox_cursor_hovered)
	{
		handler(&checkbox, &args);
	}
}



void Checkbox::unhover_cursor(Checkbox& checkbox, Event_args** args, size_t args_count)
{
	checkbox.cursor_inside = false;
	for (size_t i = 0; i < args_count; i++)
	{
		for (auto& handler : checkbox.�heckbox_cursor_away)
		{
			handler(&checkbox, args[i]);
		}
	}
}

void Checkbox::unhover_cursor(Checkbox& checkbox)
{
	checkbox.cursor_inside = false;
	Checkbox_event_args args(Checkbox_event_args::Event_type::CURSOR_AWAY);
	for (auto& handler : checkbox.�heckbox_cursor_away)
	{
		handler(&checkbox, &args);
	}
}



bool Checkbox::try_click(Event_args** args, size_t args_count)
{
	if (cursor_inside)
	{
		click(*this, args, args_count);
		return true;
	}
	return false;
}

bool Checkbox::try_click()
{
	if (cursor_inside)
	{
		click(*this);
		return true;
	}
	return false;
}



bool Checkbox::try_hover(sf::Vector2i cursor_pos, Event_args** args, size_t args_count)
{

	sf::Vector2f a, b;
	a = �heckbox_graphics.getPosition();
	b = a + �heckbox_graphics.getLocalBounds().getSize();

	if (cursor_pos.x >= a.x && cursor_pos.x <= b.x && cursor_pos.y >= a.y && cursor_pos.y <= b.y)
	{
		hover_cursor(*this, args, args_count);
		return true;
	}

	return false;

}

bool Checkbox::try_hover(sf::Vector2i cursor_pos)
{

	sf::Vector2f a, b;
	a = �heckbox_graphics.getPosition();
	b = a + �heckbox_graphics.getLocalBounds().getSize();

	if (cursor_pos.x >= a.x && cursor_pos.x <= b.x && cursor_pos.y >= a.y && cursor_pos.y <= b.y)
	{
		Checkbox_event_args args(Checkbox_event_args::Event_type::CURSOR_HOVER);
		hover_cursor(*this);
		return true;
	}

	return false;

}



bool Checkbox::try_unhover(sf::Vector2i cursor_pos, Event_args** args, size_t args_count)
{

	sf::Vector2f a, b;
	a = �heckbox_graphics.getPosition();
	b = a + �heckbox_graphics.getLocalBounds().getSize();

	if (cursor_pos.x < a.x || cursor_pos.x > b.x || cursor_pos.y < a.y || cursor_pos.y > b.y)
	{
		unhover_cursor(*this, args, args_count);
		return true;
	}

	return false;

}

bool Checkbox::try_unhover(sf::Vector2i cursor_pos)
{

	sf::Vector2f a, b;
	a = �heckbox_graphics.getPosition();
	b = a + �heckbox_graphics.getLocalBounds().getSize();

	if (cursor_pos.x < a.x || cursor_pos.x > b.x || cursor_pos.y < a.y || cursor_pos.y > b.y)
	{
		Checkbox_event_args args(Checkbox_event_args::Event_type::CURSOR_AWAY);
		unhover_cursor(*this);
		return true;
	}

	return false;

}



void Checkbox::add_event_handler(Checkbox_event_handler handler, Checkbox_event_args::Event_type event_type)
{

	switch (event_type)
	{

	case Checkbox_event_args::CHECK:
		�heckbox_check.push_front(handler);
		break;

	case Checkbox_event_args::CURSOR_HOVER:
		�heckbox_cursor_hovered.push_front(handler);
		break;

	case Checkbox_event_args::CURSOR_AWAY:
		�heckbox_cursor_away.push_front(handler);
		break;

	default:
		break;

	}

}

void Checkbox::remove_event_handler(Checkbox_event_handler handler, Checkbox_event_args::Event_type event_type)
{

	switch (event_type)
	{

	case Checkbox_event_args::CHECK:
		�heckbox_check.remove(handler);
		break;

	case Checkbox_event_args::CURSOR_HOVER:
		�heckbox_cursor_hovered.remove(handler);
		break;

	case Checkbox_event_args::CURSOR_AWAY:
		�heckbox_cursor_away.remove(handler);
		break;

	default:
		break;

	}

}