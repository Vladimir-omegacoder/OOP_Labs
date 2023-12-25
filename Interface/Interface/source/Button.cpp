#include "../include/Button.h"





void Button::click(Button& button, Button_event_args* args)
{
	button.clicked = true;
	for (auto& handler : button.button_clicked)
	{
		handler(&button, args);
	}
}

void Button::click(Button& button)
{
	button.clicked = true;
	Button_event_args args(Button_event_args::Event_type::CLICK);
	for (auto& handler : button.button_clicked)
	{
		handler(&button, &args);
	}
}



void Button::release(Button& button, Button_event_args* args)
{
	button.clicked = false;
	for (auto& handler : button.button_released)
	{
		handler(&button, args);
	}
}

void Button::release(Button& button)
{
	button.clicked = false;
	Button_event_args args(Button_event_args::Event_type::RELEASE);
	for (auto& handler : button.button_released)
	{
		handler(&button, &args);
	}
}



void Button::hover_cursor(Button& button, Button_event_args* args)
{
	button.cursor_inside = true;
	for (auto& handler : button.button_cursor_hovered)
	{
		handler(&button, args);
	}
}

void Button::hover_cursor(Button& button)
{
	button.cursor_inside = true;
	Button_event_args args(Button_event_args::Event_type::CURSOR_HOVER);
	for (auto& handler : button.button_cursor_hovered)
	{
		handler(&button, &args);
	}
}



void Button::unhover_cursor(Button& button, Button_event_args* args)
{
	button.cursor_inside = false;
	for (auto& handler : button.button_cursor_away)
	{
		handler(&button, args);
	}
}

void Button::unhover_cursor(Button& button)
{
	button.cursor_inside = false;
	Button_event_args args(Button_event_args::Event_type::CURSOR_AWAY);
	for (auto& handler : button.button_cursor_away)
	{
		handler(&button, &args);
	}
}



void Button::try_click(Button_event_args* args)
{
	if (cursor_inside)
	{
		click(*this, args);
	}
}

void Button::try_click()
{
	if (cursor_inside)
	{
		Button_event_args args(Button_event_args::Event_type::CLICK);
		click(*this, &args);
	}
}



void Button::try_release(Button_event_args* args)
{
	if (clicked)
	{
		release(*this, args);
	}
}

void Button::try_release()
{
	if (clicked)
	{
		Button_event_args args(Button_event_args::Event_type::RELEASE);
		release(*this, &args);
	}
}



void Button::try_hover(sf::Vector2i cursor_pos, Button_event_args* args)
{

	sf::Vector2f a, b;
	a = button_graphics.getPosition();
	b = a + button_graphics.getLocalBounds().getSize();

	if (cursor_pos.x >= a.x && cursor_pos.x <= b.x && cursor_pos.y >= a.y && cursor_pos.y <= b.y)
	{
		hover_cursor(*this, args);
	}

}

void Button::try_hover(sf::Vector2i cursor_pos)
{

	sf::Vector2f a, b;
	a = button_graphics.getPosition();
	b = a + button_graphics.getLocalBounds().getSize();

	if (cursor_pos.x >= a.x && cursor_pos.x <= b.x && cursor_pos.y >= a.y && cursor_pos.y <= b.y)
	{
		Button_event_args args(Button_event_args::Event_type::CURSOR_HOVER);
		hover_cursor(*this, &args);
	}

}



void Button::try_unhover(sf::Vector2i cursor_pos, Button_event_args* args)
{

	sf::Vector2f a, b;
	a = button_graphics.getPosition();
	b = a + button_graphics.getLocalBounds().getSize();

	if (cursor_pos.x < a.x || cursor_pos.x > b.x || cursor_pos.y < a.y || cursor_pos.y > b.y)
	{
		unhover_cursor(*this, args);
	}

}

void Button::try_unhover(sf::Vector2i cursor_pos)
{

	sf::Vector2f a, b;
	a = button_graphics.getPosition();
	b = a + button_graphics.getLocalBounds().getSize();

	if (cursor_pos.x < a.x || cursor_pos.x > b.x || cursor_pos.y < a.y || cursor_pos.y > b.y)
	{
		Button_event_args args(Button_event_args::Event_type::CURSOR_AWAY);
		unhover_cursor(*this, &args);
	}

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