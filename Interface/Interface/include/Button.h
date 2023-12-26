#pragma once
#include "Control.h"



class Button_event_args : public Event_args
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

	const Event_type event_type;


public:

	Button_event_args(Event_type event_type) : event_type(event_type) {}

};





class Button : public Control
{

private:

	using Button_event_handler = void(*)(Button* sender, Button_event_args* args);

	std::list<Button_event_handler> button_clicked;
	std::list<Button_event_handler> button_released;
	std::list<Button_event_handler> button_cursor_hovered;
	std::list<Button_event_handler> button_cursor_away;



	bool clicked;
	bool cursor_inside;

	sf::Sprite button_graphics;



	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(button_graphics, states);
	}


public:

	Button() = default;

	sf::Sprite& get_graphics()
	{
		return button_graphics;
	}



	static void click(Button& button, Button_event_args* args);

	static void click(Button& button);


	static void release(Button& button, Button_event_args* args);

	static void release(Button& button);


	static void hover_cursor(Button& button, Button_event_args* args);

	static void hover_cursor(Button& button);


	static void unhover_cursor(Button& button, Button_event_args* args);

	static void unhover_cursor(Button& button);


	bool try_click(Button_event_args* args);

	bool try_click();


	bool try_release(Button_event_args* args);

	bool try_release();


	bool try_hover(sf::Vector2i cursor_pos, Button_event_args* args);

	bool try_hover(sf::Vector2i cursor_pos);


	bool try_unhover(sf::Vector2i cursor_pos, Button_event_args* args);

	bool try_unhover(sf::Vector2i cursor_pos);


	bool is_clicked()
	{
		return clicked;
	}

	bool is_hovered()
	{
		return cursor_inside;
	}


	void add_event_handler(Button_event_handler handler, Button_event_args::Event_type event_type);

	void remove_event_handler(Button_event_handler handler, Button_event_args::Event_type event_type);

};