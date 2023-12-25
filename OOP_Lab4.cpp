#include <iostream>
#include "SFML/Graphics.hpp"
#include "Interface/Controls.h"





#define CHECKBOX_TEXTURE				DEFAULT_CHECKBOX_TEXTURE
#define CHECKBOX_CHECKED_TEXTURE		DEFAULT_CHECKBOX_CHECKED_TEXTURE



class Checkbox_texture_change_event_args : public Checkbox_event_args
{

public:

	const sf::Texture& new_texture;

	Checkbox_texture_change_event_args(Event_type event_type, const sf::Texture& new_texture) :
		Checkbox_event_args(event_type), new_texture(new_texture) {}

};





int main()
{

	sf::RenderWindow main_window(sf::VideoMode(800, 600), "Graphics window");

	sf::Font font;
	font.loadFromFile(DEFAULT_CONTROLS_FONT);

	sf::Texture checkbox_unchecked_texture;
	sf::Texture checkbox_checked_texture;
	checkbox_unchecked_texture.loadFromFile(CHECKBOX_TEXTURE);
	checkbox_checked_texture.loadFromFile(CHECKBOX_CHECKED_TEXTURE);

	sf::RectangleShape checkbox_graphics(sf::Vector2f(50, 50));
	checkbox_graphics.move(300, 300);
	checkbox_graphics.setTexture(&checkbox_unchecked_texture);

	sf::Text checkbox_label;
	checkbox_label.setCharacterSize(50);
	checkbox_label.move(350, 300);
	checkbox_label.setFont(font);
	checkbox_label.setString("I'm a label!!!");


	Checkbox checkbox;
	checkbox.get_graphics() = checkbox_graphics;
	checkbox.get_text() = checkbox_label;

	void(*check)(Checkbox*, Checkbox_event_args*) = [](Checkbox* checkbox, Checkbox_event_args* args)
		{

			std::cout << "Checkbox checked!!!\n";

			if (auto texture_args = dynamic_cast<Checkbox_texture_change_event_args*>(args))
			{
				checkbox->get_graphics().setTexture(&texture_args->new_texture);
			}

		};
	checkbox.add_event_handler(check, Checkbox_event_args::CHECK);



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
				if (!checkbox.is_hovered())
				{
					checkbox.try_hover(sf::Mouse::getPosition(main_window));
				}
				else
				{
					checkbox.try_unhover(sf::Mouse::getPosition(main_window));
				}
			}

			if (main_event.type == sf::Event::MouseButtonPressed)
			{
				if (checkbox.is_checked())
				{
					Checkbox_texture_change_event_args args(Checkbox_event_args::CHECK, checkbox_unchecked_texture);
					checkbox.try_click(&args);
				}
				else
				{
					Checkbox_texture_change_event_args args(Checkbox_event_args::CHECK, checkbox_checked_texture);
					checkbox.try_click(&args);
				}
				
			}

		}




		main_window.draw(checkbox);

		main_window.display();

	}
	return 0;
}