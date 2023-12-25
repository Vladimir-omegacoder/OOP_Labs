#include <iostream>
#include "SFML/Graphics.hpp"
#include "Interface/Controls.h"





#define TEXTBOX_TEXTURE DEFAULT_CHECKBOX_TEXTURE



void enter_symbol(Textbox& textbox, uint32_t character)
{

	if (character > 25 && character < 36)
	{
		if (textbox.get_text().getString().getSize() < 6)
		{
			sf::String temp = textbox.get_text().getString();
			temp += character + 22;
			textbox.get_text().setString(temp);

		}
	}

	if (character == 59)
	{
		if (textbox.get_text().getString().getSize() > 0)
		{
			sf::String temp = textbox.get_text().getString();
			temp.erase(temp.getSize() - 1, 1);
			textbox.get_text().setString(temp);
		}
	}

}



class Cursor_change_textbox_event_args : public Textbox_event_args
{

public:

	sf::RenderWindow& window;
	const sf::Cursor& new_cursor;

	Cursor_change_textbox_event_args(Event_type event_type, sf::RenderWindow& window, const sf::Cursor& new_cursor)
		: Textbox_event_args(event_type), window(window), new_cursor(new_cursor) {}

};





int main()
{

	sf::RenderWindow main_window(sf::VideoMode(800, 600), "Graphics window");

	sf::Texture textbox1_texture;
	textbox1_texture.loadFromFile(TEXTBOX_TEXTURE);

	sf::Font font;
	font.loadFromFile(DEFAULT_CONTROLS_FONT);

	sf::RectangleShape textbox_graphics(sf::Vector2f(300, 50));
	textbox_graphics.setPosition(300, 300);
	textbox_graphics.setTexture(&textbox1_texture);

	Textbox textbox;
	textbox.get_graphics() = textbox_graphics;
	textbox.get_text().setFont(font);
	textbox.get_text().setFillColor(sf::Color::Blue);
	textbox.get_text().setCharacterSize(50);
	textbox.get_text().setPosition(300, 295);

	sf::Cursor text_cursor;
	text_cursor.loadFromSystem(sf::Cursor::Text);

	void(*hover_cursor)(Textbox*, Textbox_event_args*) = [](Textbox* textbox, Textbox_event_args* args)
		{

			if (auto change_cursor = dynamic_cast<Cursor_change_textbox_event_args*>(args))
			{
				sf::Cursor text_cursor;
				text_cursor.loadFromSystem(sf::Cursor::Text);
				change_cursor->window.setMouseCursor(text_cursor);
			}

		};
	textbox.add_event_handler(hover_cursor, Textbox_event_args::CURSOR_HOVER);

	void(*unhover_cursor)(Textbox*, Textbox_event_args*) = [](Textbox* textbox, Textbox_event_args* args)
		{

			if (auto change_cursor = dynamic_cast<Cursor_change_textbox_event_args*>(args))
			{
				sf::Cursor arrow_cursor;
				arrow_cursor.loadFromSystem(sf::Cursor::Arrow);
				change_cursor->window.setMouseCursor(arrow_cursor);
			}

		};
	textbox.add_event_handler(unhover_cursor, Textbox_event_args::CURSOR_AWAY);



	while (main_window.isOpen())
	{

		sf::Event main_event;

		while (main_window.pollEvent(main_event))
		{

			if (main_event.type == sf::Event::Closed)
			{

				main_window.close();

			}

			if (main_event.type == sf::Event::MouseMoved)
			{

				if (!textbox.is_hovered())
				{
					Cursor_change_textbox_event_args cur_chng_args(Textbox_event_args::CURSOR_HOVER, main_window, text_cursor);
					textbox.try_hover(sf::Mouse::getPosition(main_window), &cur_chng_args);
				}
				else
				{
					Cursor_change_textbox_event_args cur_chng_args(Textbox_event_args::CURSOR_AWAY, main_window, text_cursor);
					textbox.try_unhover(sf::Mouse::getPosition(main_window), &cur_chng_args);
				}

			}

			if (main_event.type == sf::Event::MouseButtonPressed)
			{

				if (main_event.mouseButton.button == sf::Mouse::Left)
				{

					textbox.try_click();

				}

			}

			if (main_event.type == sf::Event::MouseButtonReleased)
			{

				if (main_event.mouseButton.button == sf::Mouse::Left)
				{

					textbox.try_release();

				}

			}

			if (main_event.type == sf::Event::KeyPressed)
			{

				if (textbox.is_active())
				{
					enter_symbol(textbox, main_event.key.code);
				}

			}

		}





		main_window.draw(textbox);


		main_window.display();

	}

	return 0;

}