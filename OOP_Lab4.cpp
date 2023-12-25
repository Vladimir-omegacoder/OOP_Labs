#include <iostream>
#include "SFML/Graphics.hpp"
#include "Interface/Controls.h"







int main()
{

	sf::RenderWindow main_window(sf::VideoMode(800, 600), "Graphics window");

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

		main_window.display();

	}

	return 0;

}