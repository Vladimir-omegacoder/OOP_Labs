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



#define SCENE_BACKGROUND "scene_background.png"


int main()
{


	Scene scene;

	sf::Texture scene_texture;
	scene_texture.loadFromFile(SCENE_BACKGROUND);
	scene.get_backgruond().setTexture(scene_texture);
	scene.get_backgruond().setPosition(0, 80);

	Shape* circ = new Circle(50);
	circ->move(300, 300);

	scene.add_actor(std::move(Scene::Actor(new Rectangle(sf::Vector2f(200, 100)))));
	scene.add_actor(std::move(Scene::Actor(circ)));


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

			if (main_event.type == sf::Event::MouseButtonPressed)
			{
				scene.try_select_actor(sf::Mouse::getPosition(main_window));
			}

		}

		if (scene.get_selected_actor() != nullptr)
		{
			scene.get_selected_actor()->operator*().rotate(0.01);
		}

		main_window.clear();

		main_window.draw(scene);

		main_window.display();

	}

	return 0;

}


