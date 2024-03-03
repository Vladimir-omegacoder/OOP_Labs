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
	setlocale(LC_ALL, "ru");
	sf::RenderWindow main_window(sf::VideoMode(800, 600), "Lab 4");

	Controller& control = Controller::get_instance();

	Controller& control2 = Controller::get_instance();



	ControllerUtils utils;

	std::string path = "Save.txt";

	std::string name_fiure;

	std::fstream file;
	file.open(path, std::fstream::in | std::fstream::out);


	std::cout << &control << "\n";
	std::cout << &control2 << "\n";


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

				if (main_event.mouseButton.button == sf::Mouse::Right && control._actve())
				{
					control.add_compose(i);
				}
			}


			if (main_event.type == sf::Event::KeyReleased)
			{
				if (main_event.key.code == sf::Keyboard::Num1)
				{
					control.add_figure(new Circle(40.0f));
					control._figures().back()->move(100, 50);
				}

				if (main_event.key.code == sf::Keyboard::Num2)
				{
					control.add_figure(new Triangle(50.0f));
					control._figures().back()->move(200, 50);
				}

				if (main_event.key.code == sf::Keyboard::Num3)
				{
					control.add_figure(new Square(50.0f));
					control._figures().back()->move(300, 50);
				}


				//Копиовать

				if ((main_event.key.code == sf::Keyboard::C) && (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)))
				{
					std::cout << "Введiть iм'я фiгури: ";
					std::cin >> name_fiure;

					if (control.copy_figure(name_fiure))
					{
						std::cout << "Збережено....\n\n";
					}
					else
					{
						std::cout << "Помилка, не вдалося зберегти!!!\n\n";
					}
					
				}
				

				//Вставить
				if ((main_event.key.code == sf::Keyboard::V) && (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)))
				{
					std::cout << "-----Збереженi фiгури-----\n";

					int i = 1;

					for (auto& f: control._save_figures())
					{
						std::cout << i << ". " << f.first << "\n";
						i++;
					}
					std::cout << "--------------------------\n\n";



					std::cout << "Введiть iм'я фiгури: ";
					std::cin >> name_fiure;

					if (control.paste_figure(name_fiure))
					{
						std::cout << "Додано....\n\n";
					}
					else
					{
						std::cout << "Помилка, фiгури з такою назвою не збережено!!!\n\n";
					}				
				}



				//Сохранение в программе
				if (main_event.key.code == sf::Keyboard::S)
				{
					utils.save_state(control);

					std::cout << "------Збережено------\n\n";
				}


				//Выгрузка из программы
				if (main_event.key.code == sf::Keyboard::L)
				{
					utils.load_state(control);

					std::cout << "-----Завантажено-----\n\n";
				}


				//Сохранить в файл
				if (main_event.key.code == sf::Keyboard::O)
				{
					std::cout << "Введiть iм'я файла куди хочете зберегти сцену\n";
					std::cin >> path;

					utils.save_file(path, control);

					std::cout << "~~~~~~Збережено~~~~~~\n\n";
				}

				//Выгрузить из файла
				if (main_event.key.code == sf::Keyboard::P)
				{
					std::cout << "Введiть iм'я файла з вiдки хочете завантажити сцену\n";
					std::cin >> path;

					utils.load_file(path, control);

					std::cout << "~~~~~Завантажено~~~~~\n\n";
				}
			}
		}




		if (control._actve())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) // Стрелочка вправо
			{
				control._actve()->move(0.1, 0);
				control.in_window(control._actve(), main_window);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // Стрелочка влево
			{
				control._actve()->move(-0.1, 0);
				control.in_window(control._actve(), main_window);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) // Стрелочка вверх
			{
				control._actve()->move(0, -0.1);
				control.in_window(control._actve(), main_window);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) // Стрелочка вниз
			{
				control._actve()->move(0, 0.1);
				control.in_window(control._actve(), main_window);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) // Востановить
			{
				control._actve()->scaling(sf::Vector2f(1, 1));
				control._befor_activ_color() = control._actve()->get_сolor();
				control._actve()->show();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) // Перекрасить
			{
				control._befor_activ_color() = sf::Color::Blue;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) // Увеличить
			{
				control._actve()->scaling(sf::Vector2f(2, 2));
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // Скрыть
			{
				control._actve()->hide();
			}



			control.intersects();
		}


		


		main_window.clear();

		main_window.draw(control);

		main_window.display();
	}

	file.close();
}


