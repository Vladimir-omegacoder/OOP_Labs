#include <iostream>
#include "SFML/Graphics.hpp"
#include "Interface/Controls.h"



#define CHECKBOX_TEXTURE "check_box1_unchecked.png"
#define CHECKBOX_CHECKBOX_TEXTURE "check_box1_checked.png"

sf::Texture checkbox_unchecked_texture;
sf::Texture checkbox_checked_texture;





int main()
{

	sf::RenderWindow main_window(sf::VideoMode(800, 600), "Graphics window");
	sf::Font font;
	font.loadFromFile("calibri.ttf");
	

	sf::RectangleShape checkbox_graphics(sf::Vector2f(50, 50));
	checkbox_graphics.move(300, 300);
	checkbox_unchecked_texture.loadFromFile(CHECKBOX_TEXTURE);
	checkbox_checked_texture.loadFromFile(CHECKBOX_CHECKBOX_TEXTURE);
	checkbox_graphics.setTexture(&checkbox_unchecked_texture);

	sf::Text checkbox_label;
	checkbox_label.setCharacterSize(50);
	checkbox_label.move(350, 300);
	checkbox_label.setFont(font);
	checkbox_label.setString("I'm a label!!!");


	Checkbox checkbox;
	checkbox.get_graphics() = checkbox_graphics;
	checkbox.get_text() = checkbox_label;
	void(*check)(Checkbox*, CheckboxEventArgs) = [](Checkbox* checkbox, CheckboxEventArgs args)
		{

			std::cout << "Checkbox checked!!!\n";

			if (checkbox->is_checked())
			{
				checkbox->get_graphics().setTexture(&checkbox_checked_texture);
			}
			else
			{
				checkbox->get_graphics().setTexture(&checkbox_unchecked_texture);
			}
			
		};
	checkbox.add_event_handler(check, CheckboxEventArgs::CHECK);



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
				checkbox.try_click();
			}

		}




		main_window.draw(checkbox);
		
		main_window.display();

	}

	return 0;

}