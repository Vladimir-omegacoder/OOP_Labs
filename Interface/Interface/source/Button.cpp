#include "../include/Button.h"





void Button::click(Button& button, Event_args** args, size_t args_count)
{
	button.clicked = true;
	for (size_t i = 0; i < args_count; i++)
	{
		for (auto& handler : button.button_clicked)
		{
			handler(&button, args[i]);
		}
	}
}

void Button::click(Button& button)
{
	button.clicked = true;
	Button_event_args args(Button_event_args::Event_type::CLICK);
	Event_args* p_args = &args;
	for (auto& handler : button.button_clicked)
	{
		handler(&button, p_args);
	}
}



void Button::release(Button& button, Event_args** args, size_t args_count)
{
	button.clicked = false;
	for (size_t i = 0; i < args_count; i++)
	{
		for (auto& handler : button.button_released)
		{
			handler(&button, args[i]);
		}
	}
}

void Button::release(Button& button)
{
	button.clicked = false;
	Button_event_args args(Button_event_args::Event_type::RELEASE);
	Event_args* p_args = &args;
	for (auto& handler : button.button_released)
	{
		handler(&button, p_args);
	}
}



void Button::hover_cursor(Button& button, Event_args** args, size_t args_count)
{
	button.cursor_inside = true;
	for (size_t i = 0; i < args_count; i++)
	{
		for (auto& handler : button.button_cursor_hovered)
		{
			handler(&button, args[i]);
		}
	}
}

void Button::hover_cursor(Button& button)
{
	button.cursor_inside = true;
	Button_event_args args(Button_event_args::Event_type::CURSOR_HOVER);
	Event_args* p_args = &args;
	for (auto& handler : button.button_cursor_hovered)
	{
		handler(&button, p_args);
	}
}



void Button::unhover_cursor(Button& button, Event_args** args, size_t args_count)
{
	button.cursor_inside = false;
	for (size_t i = 0; i < args_count; i++)
	{
		for (auto& handler : button.button_cursor_away)
		{
			handler(&button, args[i]);
		}
	}
}

void Button::unhover_cursor(Button& button)
{
	button.cursor_inside = false;
	Button_event_args args(Button_event_args::Event_type::CURSOR_AWAY);
	Event_args* p_args = &args;
	for (auto& handler : button.button_cursor_away)
	{
		handler(&button, p_args);
	}
}



bool Button::try_click(Event_args** args, size_t args_count)
{
	if (cursor_inside)
	{
		click(*this, args, args_count);
		return true;
	}
	return false;
}

bool Button::try_click()
{
	if (cursor_inside)
	{
		click(*this);
		return true;
	}
	return false;
}



bool Button::try_release(Event_args** args, size_t args_count)
{
	if (clicked)
	{
		release(*this, args, args_count);
		return true;
	}
	return false;
}

bool Button::try_release()
{
	if (clicked)
	{
		release(*this);
		return true;
	}
	return false;
}



bool Button::try_hover(sf::Vector2i cursor_pos, Event_args** args, size_t args_count)
{

	sf::Vector2f a, b;
	a = button_graphics.getPosition();
	b = a + button_graphics.getLocalBounds().getSize();

	if (cursor_pos.x >= a.x && cursor_pos.x <= b.x && cursor_pos.y >= a.y && cursor_pos.y <= b.y)
	{
		hover_cursor(*this, args, args_count);
		return true;
	}

	return false;

}

bool Button::try_hover(sf::Vector2i cursor_pos)
{

	sf::Vector2f a, b;
	a = button_graphics.getPosition();
	b = a + button_graphics.getLocalBounds().getSize();

	if (cursor_pos.x >= a.x && cursor_pos.x <= b.x && cursor_pos.y >= a.y && cursor_pos.y <= b.y)
	{
		Button_event_args args(Button_event_args::Event_type::CURSOR_HOVER);
		hover_cursor(*this);
		return true;
	}

	return false;

}



bool Button::try_unhover(sf::Vector2i cursor_pos, Event_args** args, size_t args_count)
{

	sf::Vector2f a, b;
	a = button_graphics.getPosition();
	b = a + button_graphics.getLocalBounds().getSize();

	if (cursor_pos.x < a.x || cursor_pos.x > b.x || cursor_pos.y < a.y || cursor_pos.y > b.y)
	{
		unhover_cursor(*this, args, args_count);
		return true;
	}

	return false;

}

bool Button::try_unhover(sf::Vector2i cursor_pos)
{

	sf::Vector2f a, b;
	a = button_graphics.getPosition();
	b = a + button_graphics.getLocalBounds().getSize();

	if (cursor_pos.x < a.x || cursor_pos.x > b.x || cursor_pos.y < a.y || cursor_pos.y > b.y)
	{
		Button_event_args args(Button_event_args::Event_type::CURSOR_AWAY);
		unhover_cursor(*this);
		return true;
	}

	return false;

}



void Button::add_event_handler(Button_event_handler handler, Button_event_args::Event_type event_type)
{

	switch (event_type)
	{

	case Button_event_args::CLICK:
		button_clicked.push_front(handler);
		break;

	case Button_event_args::RELEASE:
		button_released.push_front(handler);
		break;

	case Button_event_args::CURSOR_HOVER:
		button_cursor_hovered.push_front(handler);
		break;

	case Button_event_args::CURSOR_AWAY:
		button_cursor_away.push_front(handler);
		break;

	default:
		break;

	}

}

void Button::remove_event_handler(Button_event_handler handler, Button_event_args::Event_type event_type)
{

	switch (event_type)
	{

	case Button_event_args::CLICK:
		button_clicked.remove(handler);
		break;

	case Button_event_args::RELEASE:
		button_released.remove(handler);
		break;

	case Button_event_args::CURSOR_HOVER:
		button_cursor_hovered.remove(handler);
		break;

	case Button_event_args::CURSOR_AWAY:
		button_cursor_away.remove(handler);
		break;

	default:
		break;

	}

}