#include <iostream>
#include "SFML/Graphics.hpp"
#include "Figure.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Composite.h"
#include <vector>
#include <list>
#include <iterator>
#include <fstream>
#include <string>

#include "ControllerUtils.h"
#include "Controller.h"



int main()
{
	sf::RenderWindow main_window(sf::VideoMode(800, 600), "Lab 4");

	Controller control;
	ControllerUtils utils;

	std::string path = "Save.txt";

	std::fstream file;
	file.open(path, std::fstream::in | std::fstream::out);


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
				Figure* i = control.click_figure(sf::Mouse::getPosition(main_window));

				if (main_event.mouseButton.button == sf::Mouse::Left)
				{
					control.activate_figure(i);
				}

				if (main_event.mouseButton.button == sf::Mouse::Right && control.actve)
				{
					control.add_compose(i);
				}
			}


			if (main_event.type == sf::Event::KeyReleased)
			{
				if (main_event.key.code == sf::Keyboard::Num1)
				{
					control.add_figure(new Circle(40.0f));
					control.figures.back()->move(100, 50);
				}

				if (main_event.key.code == sf::Keyboard::Num2)
				{
					control.add_figure(new Triangle(50.0f));
					control.figures.back()->move(200, 50);
				}

				if (main_event.key.code == sf::Keyboard::Num3)
				{
					control.add_figure(new Square(50.0f));
					control.figures.back()->move(300, 50);
				}


				//Копиовать

				if ((main_event.key.code == sf::Keyboard::C) && (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)))
				{
					control.copy();
				}
				

				//Вставить
				if ((main_event.key.code == sf::Keyboard::V) && (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)))
				{
					control.paste();
				}



				if (main_event.key.code == sf::Keyboard::S)
				{
					utils.save_state(control);
				}


				if (main_event.key.code == sf::Keyboard::L)
				{
					utils.load_state(control);
				}






				//if (main_event.key.code == sf::Keyboard::O)
				//{
				//	utils.save_in_file(file, control);
				//}

				//if (main_event.key.code == sf::Keyboard::P)
				//{
				//	utils.load_in_file(file, control);
				//}

			}
		}




		if (control.actve)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // Стрелочка вправо
			{
				control.actve->move(0.1, 0);
				control.in_window(control.actve, main_window);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // Стрелочка влево
			{
				control.actve->move(-0.1, 0);
				control.in_window(control.actve, main_window);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // Стрелочка вверх
			{
				control.actve->move(0, -0.1);
				control.in_window(control.actve, main_window);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) // Стрелочка вниз
			{
				control.actve->move(0, 0.1);
				control.in_window(control.actve, main_window);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) // Востановить
			{
				control.actve->scaling(sf::Vector2f(1, 1));
				control.befor_activ_color = control.actve->get_сolor();
				control.actve->show();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) // Перекрасить
			{
				control.befor_activ_color = sf::Color::Blue;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) // Увеличить
			{
				control.actve->scaling(sf::Vector2f(2, 2));
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // Скрыть
			{
				control.actve->hide();
			}



			control.intersects();
		}


		


		main_window.clear();

		main_window.draw(control);

		main_window.display();
	}

	file.close();
}


