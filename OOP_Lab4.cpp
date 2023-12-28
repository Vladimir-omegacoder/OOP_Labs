#include <iostream>
#include "SFML/Graphics.hpp"
#include "Graphics/Primitives.h"




int main()
{


	Regular circ(100, 4);
	circ.move(400, 300);
	circ.rotate(45);
	circ.set_origin(50, 50);
	std::cout << circ.get_position().x << ' ' << circ.get_position().y << '\n';

	std::cout << circ.get_origin().x << ' ' << circ.get_origin().y << '\n';

	


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

		//circ.rotate(0.01);

		main_window.clear();

		main_window.draw(circ);


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