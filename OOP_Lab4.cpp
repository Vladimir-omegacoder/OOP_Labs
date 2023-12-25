#include <iostream>
#include "SFML/Graphics.hpp"
#include "Interface/Controls.h"



#define TEXTBOX_TEXTURE "text_box1.png"



void enter_symbol(Textbox& textbox, uint32_t character)
{

	if (character > 47 && character < 58)
	{
		sf::String temp = textbox.get_text().getString();
		temp += character;
		textbox.get_text().setString(temp);
	}

}

class CursorChangeTextboxEventArgs : public TextboxEventArgs
{

public:

	sf::Cursor& cursor;

	CursorChangeTextboxEventArgs(Event_type event_type, sf::Cursor& cursor, const sf::Cursor& new_cursor)
		: TextboxEventArgs(event_type), cursor(cursor) {}

};


int main()
{

	sf::RenderWindow main_window(sf::VideoMode(800, 600), "Graphics window");

	sf::Texture textbox1_texture;
	textbox1_texture.loadFromFile(TEXTBOX_TEXTURE);
	sf::Font font;
	font.loadFromFile(CONTROLS_FONT);
	sf::RectangleShape textbox_graphics(sf::Vector2f(300, 50));
	textbox_graphics.setPosition(300, 300);
	textbox_graphics.setTexture(&textbox1_texture);

	Textbox textbox;
	textbox.get_graphics() = textbox_graphics;
	textbox.get_text().setFont(font);
	textbox.get_text().setCharacterSize(50);

	void(*hover_cursor)(Textbox*, TextboxEventArgs) = [](Textbox* textbox, TextboxEventArgs args)
		{

			if (auto cursor_args = dynamic_cast<const CursorChangeTextboxEventArgs*>(&args))
			{
				cursor_args->cursor.loadFromSystem(sf::Cursor::Text);
			}

		};

	textbox.add_event_handler(hover_cursor, TextboxEventArgs::CURSOR_HOVER);

	void(*unhover_cursor)(Textbox*, TextboxEventArgs) = [](Textbox* textbox, TextboxEventArgs args)
		{

			if (auto cursor_args = dynamic_cast<const CursorChangeTextboxEventArgs*>(&args))
			{
				cursor_args->cursor.loadFromSystem(sf::Cursor::Arrow);
			}

		};

	textbox.add_event_handler(unhover_cursor, TextboxEventArgs::CURSOR_AWAY);



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
					textbox.try_hover(sf::Mouse::getPosition(main_window));
				}
				else
				{
					textbox.try_unhover(sf::Mouse::getPosition(main_window));
				}

			}

			if (main_event.type == sf::Event::MouseButtonPressed)
			{

				if (main_event.mouseButton.button == sf::Mouse::Left)
				{

					textbox.try_click();

				}

			}

			if (main_event.type == sf::Event::KeyPressed)
			{
				if (main_event.type == sf::Event::TextEntered)
				{
					if (textbox.is_active())
					{
						enter_symbol(textbox, main_event.text.unicode);
					}
				}
			}

		}


		main_window.draw(textbox);

		
		main_window.display();

	}

	return 0;

}