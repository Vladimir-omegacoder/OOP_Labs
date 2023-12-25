#include "../include/Checkbox.h"





void Checkbox::click(Checkbox& checkbox, Checkbox_event_args* args)
{
	checkbox.checked = !checkbox.checked;
	for (auto& handler : checkbox.ñheckbox_check)
	{
		handler(&checkbox, args);
	}
}

void Checkbox::click(Checkbox& checkbox)
{
	checkbox.checked = !checkbox.checked;
	Checkbox_event_args args(Checkbox_event_args::Event_type::CHECK);
	for (auto& handler : checkbox.ñheckbox_check)
	{
		handler(&checkbox, &args);
	}
}



void Checkbox::hover_cursor(Checkbox& checkbox, Checkbox_event_args* args)
{
	checkbox.cursor_inside = true;
	for (auto& handler : checkbox.ñheckbox_cursor_hovered)
	{
		handler(&checkbox, args);
	}
}

void Checkbox::hover_cursor(Checkbox& checkbox)
{
	checkbox.cursor_inside = true;
	Checkbox_event_args args(Checkbox_event_args::Event_type::CURSOR_HOVER);
	for (auto& handler : checkbox.ñheckbox_cursor_hovered)
	{
		handler(&checkbox, &args);
	}
}



void Checkbox::unhover_cursor(Checkbox& checkbox, Checkbox_event_args* args)
{
	checkbox.cursor_inside = false;
	for (auto& handler : checkbox.ñheckbox_cursor_away)
	{
		handler(&checkbox, args);
	}
}

void Checkbox::unhover_cursor(Checkbox& checkbox)
{
	checkbox.cursor_inside = false;
	Checkbox_event_args args(Checkbox_event_args::Event_type::CURSOR_AWAY);
	for (auto& handler : checkbox.ñheckbox_cursor_away)
	{
		handler(&checkbox, &args);
	}
}



void Checkbox::try_click(Checkbox_event_args* args)
{
	if (cursor_inside)
	{
		click(*this, args);
	}
}

void Checkbox::try_click()
{
	if (cursor_inside)
	{
		Checkbox_event_args args(Checkbox_event_args::Event_type::CHECK);
		click(*this, &args);
	}
}



void Checkbox::try_hover(sf::Vector2i cursor_pos, Checkbox_event_args* args)
{

	sf::Vector2f a, b;
	a = ñheckbox_graphics.getPosition();
	b = a + ñheckbox_graphics.getSize();

	if (cursor_pos.x >= a.x && cursor_pos.x <= b.x && cursor_pos.y >= a.y && cursor_pos.y <= b.y)
	{
		hover_cursor(*this, args);
	}

}

void Checkbox::try_hover(sf::Vector2i cursor_pos)
{

	sf::Vector2f a, b;
	a = ñheckbox_graphics.getPosition();
	b = a + ñheckbox_graphics.getSize();

	if (cursor_pos.x >= a.x && cursor_pos.x <= b.x && cursor_pos.y >= a.y && cursor_pos.y <= b.y)
	{
		Checkbox_event_args args(Checkbox_event_args::Event_type::CURSOR_HOVER);
		hover_cursor(*this, &args);
	}

}



void Checkbox::try_unhover(sf::Vector2i cursor_pos, Checkbox_event_args* args)
{

	sf::Vector2f a, b;
	a = ñheckbox_graphics.getPosition();
	b = a + ñheckbox_graphics.getSize();

	if (cursor_pos.x < a.x || cursor_pos.x > b.x || cursor_pos.y < a.y || cursor_pos.y > b.y)
	{
		unhover_cursor(*this, args);
	}

}

void Checkbox::try_unhover(sf::Vector2i cursor_pos)
{

	sf::Vector2f a, b;
	a = ñheckbox_graphics.getPosition();
	b = a + ñheckbox_graphics.getSize();

	if (cursor_pos.x < a.x || cursor_pos.x > b.x || cursor_pos.y < a.y || cursor_pos.y > b.y)
	{
		Checkbox_event_args args(Checkbox_event_args::Event_type::CURSOR_AWAY);
		unhover_cursor(*this, &args);
	}

}



void Checkbox::add_event_handler(Checkbox_event_handler handler, Checkbox_event_args::Event_type event_type)
{

	switch (event_type)
	{

	case Checkbox_event_args::CHECK:
		ñheckbox_check.push_front(handler);
		break;

	case Checkbox_event_args::CURSOR_HOVER:
		ñheckbox_cursor_hovered.push_front(handler);
		break;

	case Checkbox_event_args::CURSOR_AWAY:
		ñheckbox_cursor_away.push_front(handler);
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
		ñheckbox_check.remove(handler);
		break;

	case Checkbox_event_args::CURSOR_HOVER:
		ñheckbox_cursor_hovered.remove(handler);
		break;

	case Checkbox_event_args::CURSOR_AWAY:
		ñheckbox_cursor_away.remove(handler);
		break;

	default:
		break;

	}

}