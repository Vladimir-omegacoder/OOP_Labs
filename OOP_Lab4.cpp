#include <iostream>
#include "SFML/Graphics.hpp"
#include "Interface/Controls.h"



#define BUTTON_TEXTURE "button1.png"
#define BUTTON_PRESSED_TEXTURE "button1_pressed.png"

sf::Texture button_pressed_texture;
sf::Texture button_released_texture;




int main()
{

	sf::RenderWindow main_window(sf::VideoMode(800, 600), "Graphics window");

	sf::RectangleShape button_graphics(sf::Vector2f(200, 100));
	button_graphics.move(300, 300);
	button_pressed_texture.loadFromFile(BUTTON_PRESSED_TEXTURE);
	button_released_texture.loadFromFile(BUTTON_TEXTURE);
	button_graphics.setTexture(&button_released_texture);


	Button button;
	button.get_graphics() = button_graphics;
	void(*press)(Button*, ButtonEventArgs) = [](Button* button, ButtonEventArgs args)
		{
			std::cout << "Button clicked!!!\n";
			button->get_graphics().setTexture(&button_pressed_texture);
		};
	button.add_event_handler(press, ButtonEventArgs::CLICK);
	void(*release)(Button*, ButtonEventArgs) = [](Button* button, ButtonEventArgs args)
		{			
			std::cout << "Button released!!!\n";
			button->get_graphics().setTexture(&button_released_texture);
		};
	button.add_event_handler(release, ButtonEventArgs::RELEASE);



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
				if (!button.is_hovered())
				{
					button.try_hover(sf::Mouse::getPosition(main_window));
				}
				else
				{
					button.try_unhover(sf::Mouse::getPosition(main_window));
				}
			}

			if (main_event.type == sf::Event::MouseButtonPressed)
			{
				if (!button.is_clicked())
				{
					button.try_click();
				}
			}

			if (main_event.type == sf::Event::MouseButtonReleased)
			{
				if (button.is_clicked())
				{
					button.release();
				}
			}

		}





		main_window.draw(button);
		
		main_window.display();

	}

	return 0;

}