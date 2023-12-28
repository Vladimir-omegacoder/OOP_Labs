#include <iostream>
#include "SFML/Graphics.hpp"
#include "Graphics/Primitives.h"




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


	Regular* square = new Regular(100, 4);
	//square->set_origin(50, 50);
	square->move(200, 100);

	Rectangle* rect = new Rectangle(sf::Vector2f(200, 100));
	rect->move(400, 300);
	
	Composite compost;
	compost.add_shape(std::move(square));
	compost.add_shape(std::move(rect));

	sf::FloatRect bounds = compost.get_local_bounds();

	std::cout << "X1: " << bounds.left << "    " << "X2: " << bounds.width << '\n';
	std::cout << "Y1: " << bounds.top << "    " << "Y2: " << bounds.height << '\n';


	compost.set_outline_thickness(10);
	compost.set_outline_color(sf::Color::Yellow);

	compost.set_fill_color(sf::Color::Blue);



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

		compost.rotate(0.01);
		compost.scale(1.0001, 1.0001);

		main_window.clear();

		
		main_window.draw(compost);

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