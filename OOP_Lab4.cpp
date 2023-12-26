#include <iostream>
#include "SFML/Graphics.hpp"
#include "Interface/Controls.h"





#define TOP_PANEL_TEXTURE "resources/background/top_panel_texture.png"


#define BUTTON_LINE					"resources/button/button_line/button_line.png"
#define BUTTON_LINE_PRESSED			"resources/button/button_line/button_line_pressed.png"

#define BUTTON_RECTANGLE			"resources/button/button_rectangle/button_rectangle.png"
#define BUTTON_RECTANGLE_PRESSED	"resources/button/button_rectangle/button_rectangle_pressed.png"

#define BUTTON_CIRCLE				"resources/button/button_circle/button_circle.png"
#define BUTTON_CIRCLE_PRESSED		"resources/button/button_circle/button_circle_pressed.png"

#define BUTTON_TRIANGLE				"resources/button/button_triangle/button_triangle.png"
#define BUTTON_TRIANGLE_PRESSED		"resources/button/button_triangle/button_triangle_pressed.png"

#define BUTTON_SQUARE				"resources/button/button_square/button_square.png"
#define BUTTON_SQUARE_PRESSED		"resources/button/button_square/button_square_pressed.png"

#define BUTTON_PENTAGON				"resources/button/button_pentagon/button_pentagon.png"
#define BUTTON_PENTAGON_PRESSED		"resources/button/button_pentagon/button_pentagon_pressed.png"

#define BUTTON_HEXAGON				"resources/button/button_hexagon/button_hexagon.png"
#define BUTTON_HEXAGON_PRESSED		"resources/button/button_hexagon/button_hexagon_pressed.png"


#define BUTTON_DELETE				"resources/button/button_delete/button_delete.png"
#define BUTTON_DELETE_PRESSED		"resources/button/button_delete/button_delete_pressed.png"

#define BUTTON_RESET				"resources/button/button_reset/button_reset.png"
#define BUTTON_RESET_PRESSED		"resources/button/button_reset/button_reset_pressed.png"

#define BUTTON_AGGREGATE			"resources/button/button_aggregate/button_aggregate.png"
#define BUTTON_AGGREGATE_PRESSED	"resources/button/button_aggregate/button_aggregate_pressed.png"

#define BUTTON_PROPERTIES			"resources/button/button_properties/button_properties.png"
#define BUTTON_PROPERTIES_PRESSED	"resources/button/button_properties/button_properties_pressed.png"





int main()
{

	sf::RenderWindow main_window(sf::VideoMode(800, 600), "Graphics window");

	class Control_panel : public sf::Drawable
	{

	private:

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
		{
			target.draw(background);
		}


	public:

		sf::Sprite background;

		Control_panel() = default;

		bool cursor_inside(sf::Vector2i cursor_pos)
		{

			sf::Vector2f a, b;
			a = background.getPosition();
			b = a + background.getLocalBounds().getSize();

			if (cursor_pos.x >= a.x && cursor_pos.x <= b.x && cursor_pos.y >= a.y && cursor_pos.y <= b.y)
			{
				return true;
			}
			else
			{
				return false;
			}

		}

	};


	
	// Creating background
	sf::Texture texture_top_panel;
	texture_top_panel.loadFromFile(TOP_PANEL_TEXTURE);
	Control_panel top_panel;
	top_panel.background.setTexture(texture_top_panel, true);
	


	// Setting button size(optional)
	const sf::Vector2i BUTTON_SIZE(50, 50);

	// Loading textures
	sf::Texture
		texture_button_line, texture_button_line_pressed,
		texture_button_rectangle, texture_button_rectangle_pressed,
		texture_button_circle, texture_button_circle_pressed,
		texture_button_triangle, texture_button_triangle_pressed,
		texture_button_square, texture_button_square_pressed,
		texture_button_pentagon, texture_button_pentagon_pressed,
		texture_button_hexagon, texture_button_hexagon_pressed,
		texture_button_delete, texture_button_delete_pressed,
		texture_button_reset, texture_button_reset_pressed,
		texture_button_aggregate, texture_button_aggregate_pressed,
		texture_button_properties, texture_button_properties_pressed;

	texture_button_line.loadFromFile(BUTTON_LINE);
	texture_button_line_pressed.loadFromFile(BUTTON_LINE_PRESSED);

	texture_button_rectangle.loadFromFile(BUTTON_RECTANGLE);
	texture_button_rectangle_pressed.loadFromFile(BUTTON_RECTANGLE_PRESSED);

	texture_button_circle.loadFromFile(BUTTON_CIRCLE);
	texture_button_circle_pressed.loadFromFile(BUTTON_CIRCLE_PRESSED);

	texture_button_triangle.loadFromFile(BUTTON_TRIANGLE);
	texture_button_triangle_pressed.loadFromFile(BUTTON_TRIANGLE_PRESSED);

	texture_button_square.loadFromFile(BUTTON_SQUARE);
	texture_button_square_pressed.loadFromFile(BUTTON_SQUARE_PRESSED);

	texture_button_pentagon.loadFromFile(BUTTON_PENTAGON);
	texture_button_pentagon_pressed.loadFromFile(BUTTON_PENTAGON_PRESSED);

	texture_button_hexagon.loadFromFile(BUTTON_HEXAGON);
	texture_button_hexagon_pressed.loadFromFile(BUTTON_HEXAGON_PRESSED);

	texture_button_delete.loadFromFile(BUTTON_DELETE);
	texture_button_delete_pressed.loadFromFile(BUTTON_DELETE_PRESSED);

	texture_button_reset.loadFromFile(BUTTON_RESET);
	texture_button_reset_pressed.loadFromFile(BUTTON_RESET_PRESSED);

	texture_button_aggregate.loadFromFile(BUTTON_AGGREGATE);
	texture_button_aggregate_pressed.loadFromFile(BUTTON_AGGREGATE_PRESSED);

	texture_button_properties.loadFromFile(BUTTON_PROPERTIES);
	texture_button_properties_pressed.loadFromFile(BUTTON_PROPERTIES_PRESSED);

	// Creating buttons
	Button button_line,
		button_rectangle,
		button_circle,
		button_triangle,
		button_square,
		button_pentagon,
		button_hexagon,
		button_delete,
		button_reset,
		button_aggregate,
		button_properties;

	// Applying loaded textures to the buttons
	button_line.		get_graphics().setTexture(texture_button_line);
	button_rectangle.	get_graphics().setTexture(texture_button_rectangle);
	button_circle.		get_graphics().setTexture(texture_button_circle);
	button_triangle.	get_graphics().setTexture(texture_button_triangle);
	button_square.		get_graphics().setTexture(texture_button_square);
	button_pentagon.	get_graphics().setTexture(texture_button_pentagon);
	button_hexagon.		get_graphics().setTexture(texture_button_hexagon);
	button_delete.		get_graphics().setTexture(texture_button_delete);
	button_reset.		get_graphics().setTexture(texture_button_reset);
	button_aggregate.	get_graphics().setTexture(texture_button_aggregate);
	button_properties.	get_graphics().setTexture(texture_button_properties);

	// Aligning buttons on the panel
	button_line.		get_graphics().setPosition(60 * 0 + 10, 10);
	button_rectangle.	get_graphics().setPosition(10 + 60 * 1 + 10, 10);
	button_circle.		get_graphics().setPosition(20 + 60 * 2 + 10, 10);
	button_triangle.	get_graphics().setPosition(30 + 60 * 3 + 10, 10);
	button_square.		get_graphics().setPosition(40 + 60 * 4 + 10, 10);
	button_pentagon.	get_graphics().setPosition(50 + 60 * 5 + 10, 10);
	button_hexagon.		get_graphics().setPosition(60 + 60 * 6 + 10, 10);
	button_properties.	get_graphics().setPosition(90 + 60 * 7 + 10, 10);
	button_reset.		get_graphics().setPosition(100 + 60 * 8 + 10, 10);
	button_aggregate.	get_graphics().setPosition(110 + 60 * 9 + 10, 10);
	button_delete.		get_graphics().setPosition(120 + 60 * 10 + 10, 10);

	// Adding animation to the buttons
	class Button_texture_change_event_args : public Button_event_args
	{

	public:

		const sf::Texture& new_texture;

		Button_texture_change_event_args(Event_type event_type, const sf::Texture& new_texture) :
			Button_event_args(event_type), new_texture(new_texture) {}

	};

	void(*press)(Button*, Button_event_args*) = [](Button* button, Button_event_args* args)
		{
			if (auto texture_args = dynamic_cast<Button_texture_change_event_args*>(args))
			{
				button->get_graphics().setTexture(texture_args->new_texture);
			}
		};

	void(*release)(Button*, Button_event_args*) = [](Button* button, Button_event_args* args)
		{
			if (auto texture_args = dynamic_cast<Button_texture_change_event_args*>(args))
			{
				button->get_graphics().setTexture(texture_args->new_texture);
			}
		};

	button_line.		add_event_handler(press, Button_event_args::CLICK);
	button_rectangle.	add_event_handler(press, Button_event_args::CLICK);
	button_circle.		add_event_handler(press, Button_event_args::CLICK);
	button_triangle.	add_event_handler(press, Button_event_args::CLICK);
	button_square.		add_event_handler(press, Button_event_args::CLICK);
	button_pentagon.	add_event_handler(press, Button_event_args::CLICK);
	button_hexagon.		add_event_handler(press, Button_event_args::CLICK);
	button_properties.	add_event_handler(press, Button_event_args::CLICK);
	button_reset.		add_event_handler(press, Button_event_args::CLICK);
	button_aggregate.	add_event_handler(press, Button_event_args::CLICK);
	button_delete.		add_event_handler(press, Button_event_args::CLICK);

	button_line.		add_event_handler(release, Button_event_args::RELEASE);
	button_rectangle.	add_event_handler(release, Button_event_args::RELEASE);
	button_circle.		add_event_handler(release, Button_event_args::RELEASE);
	button_triangle.	add_event_handler(release, Button_event_args::RELEASE);
	button_square.		add_event_handler(release, Button_event_args::RELEASE);
	button_pentagon.	add_event_handler(release, Button_event_args::RELEASE);
	button_hexagon.		add_event_handler(release, Button_event_args::RELEASE);
	button_properties.	add_event_handler(release, Button_event_args::RELEASE);
	button_reset.		add_event_handler(release, Button_event_args::RELEASE);
	button_aggregate.	add_event_handler(release, Button_event_args::RELEASE);
	button_delete.		add_event_handler(release, Button_event_args::RELEASE);











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

				if (!button_properties.is_hovered())
					button_properties.try_hover(sf::Mouse::getPosition(main_window));
				else
					button_properties.try_unhover(sf::Mouse::getPosition(main_window));


				if (!button_delete.is_hovered())
					button_delete.try_hover(sf::Mouse::getPosition(main_window));
				else
					button_delete.try_unhover(sf::Mouse::getPosition(main_window));


				if (!button_reset.is_hovered())
					button_reset.try_hover(sf::Mouse::getPosition(main_window));
				else
					button_reset.try_unhover(sf::Mouse::getPosition(main_window));


				if (!button_aggregate.is_hovered())
					button_aggregate.try_hover(sf::Mouse::getPosition(main_window));
				else
					button_aggregate.try_unhover(sf::Mouse::getPosition(main_window));


				if (!button_line.is_hovered())
					button_line.try_hover(sf::Mouse::getPosition(main_window));
				else
					button_line.try_unhover(sf::Mouse::getPosition(main_window));


				if (!button_rectangle.is_hovered())
					button_rectangle.try_hover(sf::Mouse::getPosition(main_window));
				else
					button_rectangle.try_unhover(sf::Mouse::getPosition(main_window));


				if (!button_circle.is_hovered())
					button_circle.try_hover(sf::Mouse::getPosition(main_window));
				else
					button_circle.try_unhover(sf::Mouse::getPosition(main_window));


				if (!button_triangle.is_hovered())
					button_triangle.try_hover(sf::Mouse::getPosition(main_window));
				else
					button_triangle.try_unhover(sf::Mouse::getPosition(main_window));


				if (!button_square.is_hovered())
					button_square.try_hover(sf::Mouse::getPosition(main_window));
				else
					button_square.try_unhover(sf::Mouse::getPosition(main_window));


				if (!button_pentagon.is_hovered())
					button_pentagon.try_hover(sf::Mouse::getPosition(main_window));
				else
					button_pentagon.try_unhover(sf::Mouse::getPosition(main_window));


				if (!button_hexagon.is_hovered())
					button_hexagon.try_hover(sf::Mouse::getPosition(main_window));
				else
					button_hexagon.try_unhover(sf::Mouse::getPosition(main_window));

			}

			if (main_event.type == sf::Event::MouseButtonPressed)
			{

				if (top_panel.cursor_inside(sf::Mouse::getPosition(main_window)))
				{

					Button_texture_change_event_args button_properties_args(Button_event_args::CLICK, texture_button_properties_pressed);
					if (button_properties.try_click(&button_properties_args))
						break;

					Button_texture_change_event_args button_delete_args(Button_event_args::CLICK, texture_button_delete_pressed);
					if (button_delete.try_click(&button_delete_args))
						break;

					Button_texture_change_event_args button_reset_args(Button_event_args::CLICK, texture_button_reset_pressed);
					if (button_reset.try_click(&button_reset_args))
						break;

					Button_texture_change_event_args button_aggregate_args(Button_event_args::CLICK, texture_button_aggregate_pressed);
					if (button_aggregate.try_click(&button_aggregate_args))
						break;



					Button_texture_change_event_args button_line_args(Button_event_args::CLICK, texture_button_line_pressed);
					if (button_line.try_click(&button_line_args))
						break;

					Button_texture_change_event_args button_rectangle_args(Button_event_args::CLICK, texture_button_rectangle_pressed);
					if (button_rectangle.try_click(&button_rectangle_args))
						break;

					Button_texture_change_event_args button_circle_args(Button_event_args::CLICK, texture_button_circle_pressed);
					if (button_circle.try_click(&button_circle_args))
						break;

					Button_texture_change_event_args button_triangle_args(Button_event_args::CLICK, texture_button_triangle_pressed);
					if (button_triangle.try_click(&button_triangle_args))
						break;

					Button_texture_change_event_args button_square_args(Button_event_args::CLICK, texture_button_square_pressed);
					if (button_square.try_click(&button_square_args))
						break;

					Button_texture_change_event_args button_pentagon_args(Button_event_args::CLICK, texture_button_pentagon_pressed);
					if (button_pentagon.try_click(&button_pentagon_args))
						break;

					Button_texture_change_event_args button_hexagon_args(Button_event_args::CLICK, texture_button_hexagon_pressed);
					if (button_hexagon.try_click(&button_hexagon_args))
						break;



				}



			}

			if (main_event.type == sf::Event::MouseButtonReleased)
			{
				
				Button_texture_change_event_args button_properties_args(Button_event_args::RELEASE, texture_button_properties);
				if (button_properties.try_release(&button_properties_args))
					break;

				Button_texture_change_event_args button_delete_args(Button_event_args::RELEASE, texture_button_delete);
				if (button_delete.try_release(&button_delete_args))
					break;

				Button_texture_change_event_args button_reset_args(Button_event_args::RELEASE, texture_button_reset);
				if (button_reset.try_release(&button_reset_args))
					break;

				Button_texture_change_event_args button_aggregate_args(Button_event_args::RELEASE, texture_button_aggregate);
				if (button_aggregate.try_release(&button_aggregate_args))
					break;



				Button_texture_change_event_args button_line_args(Button_event_args::RELEASE, texture_button_line);
				if (button_line.try_release(&button_line_args))
					break;

				Button_texture_change_event_args button_rectangle_args(Button_event_args::RELEASE, texture_button_rectangle);
				if (button_rectangle.try_release(&button_rectangle_args))
					break;

				Button_texture_change_event_args button_circle_args(Button_event_args::RELEASE, texture_button_circle);
				if (button_circle.try_release(&button_circle_args))
					break;

				Button_texture_change_event_args button_triangle_args(Button_event_args::RELEASE, texture_button_triangle);
				if (button_triangle.try_release(&button_triangle_args))
					break;

				Button_texture_change_event_args button_square_args(Button_event_args::RELEASE, texture_button_square);
				if (button_square.try_release(&button_square_args))
					break;

				Button_texture_change_event_args button_pentagon_args(Button_event_args::RELEASE, texture_button_pentagon);
				if (button_pentagon.try_release(&button_pentagon_args))
					break;

				Button_texture_change_event_args button_hexagon_args(Button_event_args::RELEASE, texture_button_hexagon);
				if (button_hexagon.try_release(&button_hexagon_args))
					break;



			}



		}



		main_window.draw(top_panel);
		main_window.draw(button_line);
		main_window.draw(button_rectangle);
		main_window.draw(button_circle);
		main_window.draw(button_triangle);
		main_window.draw(button_square);
		main_window.draw(button_pentagon);
		main_window.draw(button_hexagon);
		main_window.draw(button_delete);
		main_window.draw(button_reset);
		main_window.draw(button_aggregate);
		main_window.draw(button_properties);

		main_window.display();

	}

	return 0;

}