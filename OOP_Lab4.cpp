#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "gui_app_config/Scene.h"




/*sf::Vector2f calculate_origin() const
	{

		if (arr_size == 0)
		{
			throw std::out_of_range("Composite was empty");
		}

		sf::Vector2f new_origin;

		for (size_t i = 0; i < arr_size; i++)
		{
			new_origin += shapes_arr[i]->get_origin();
		}

		new_origin.x /= arr_size;
		new_origin.y /= arr_size;

		return new_origin;

	}*/





int main()
{


	Scene scene;

	



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

		main_window.clear();

		

		main_window.display();

	}

	return 0;

}


