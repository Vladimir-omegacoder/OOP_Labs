#include <iostream>
#include "SFML/Graphics.hpp"
#include "Graphics/Primitives/Primitives.h"



int main()
{

	sf::RenderWindow main_window(sf::VideoMode(800, 600), "Graphics window");

	Rectangle rect(sf::Vector2f(200, 100));



	while (main_window.isOpen())
	{

		sf::Event main_event;

		while (main_window.pollEvent(main_event))
		{

			if (main_event.type == sf::Event::Closed)
			{
				main_window.close();
			}

		}

		main_window.clear(sf::Color::Black);
		main_window.draw(rect);
		rect.move(0.1, 0.1);

		main_window.display();

	}

	return 0;

}







/*sf::RenderWindow main_window(sf::VideoMode(800, 600), "Graphics window"), properties_window(sf::VideoMode(300, 500), "Shape properties");

	while (main_window.isOpen())
	{

		sf::Event window_event;

		while (main_window.pollEvent(window_event))
		{

			if (window_event.type == sf::Event::Closed)
			{
				main_window.close();
			}

			if (window_event.type == sf::Event::MouseButtonPressed)
			{
				std::cout << "Main window mouse was clicked!\n";
			}

		}



		while (properties_window.pollEvent(window_event))
		{

			if (window_event.type == sf::Event::Closed)
			{
				properties_window.close();
			}

			if (window_event.type == sf::Event::MouseButtonPressed)
			{
				std::cout << "Properties window mouse was clicked!\n";
			}

		}





		properties_window.display();
		main_window.display();

	}*/