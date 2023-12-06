#include <iostream>
#include "SFML/Graphics.hpp"



int main()
{

	sf::RenderWindow main_window(sf::VideoMode(800, 600), "Graphics window"), properties_window(sf::VideoMode(300, 500), "Shape properties");

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

	}

	return 0;

}