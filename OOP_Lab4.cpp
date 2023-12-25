#include <iostream>
#include "SFML/Graphics.hpp"
#include "Interface/Controls.h"





#define BUTTON_TEXTURE DEFAULT_BUTTON_TEXTURE
#define BUTTON_PRESSED_TEXTURE DEFAULT_BUTTON_PRESSED_TEXTURE


class Button_texture_change_event_args : public Button_event_args
{

public:

	const sf::Texture& new_texture;

	Button_texture_change_event_args(Event_type event_type, const sf::Texture& new_texture) :
		Button_event_args(event_type), new_texture(new_texture) {}

};



int main()
{

	sf::RenderWindow main_window(sf::VideoMode(800, 600), "Graphics window");

	sf::Texture button_pressed_texture;
	sf::Texture button_released_texture;

	sf::RectangleShape button_graphics(sf::Vector2f(200, 100));
	button_graphics.move(300, 300);
	button_pressed_texture.loadFromFile(BUTTON_PRESSED_TEXTURE);
	button_released_texture.loadFromFile(BUTTON_TEXTURE);
	button_graphics.setTexture(&button_released_texture);

	Button button;
	button.get_graphics() = button_graphics;

	void(*press)(Button*, Button_event_args*) = [](Button* button, Button_event_args* args)
		{
			std::cout << "Button clicked!!!\n";
			if (auto texture_args = dynamic_cast<Button_texture_change_event_args*>(args))
			{
				button->get_graphics().setTexture(&(texture_args->new_texture));
			}
		};
	button.add_event_handler(press, Button_event_args::CLICK);

	void(*release)(Button*, Button_event_args*) = [](Button* button, Button_event_args* args)
		{
			std::cout << "Button released!!!\n";
			if (auto texture_args = dynamic_cast<Button_texture_change_event_args*>(args))
			{
				button->get_graphics().setTexture(&(texture_args->new_texture));
			}
		};
	button.add_event_handler(release, Button_event_args::RELEASE);



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
				Button_texture_change_event_args args(Button_event_args::CLICK, button_pressed_texture);
				button.try_click(&args);
			}

			if (main_event.type == sf::Event::MouseButtonReleased)
			{
				Button_texture_change_event_args args(Button_event_args::RELEASE, button_released_texture);
				button.try_release(&args);
			}

		}





		main_window.draw(button);

		main_window.display();

	}
	return 0;
}