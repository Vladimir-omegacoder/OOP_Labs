#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Interface/Controls.h"
#include "gui_app_config/Scene.h"





#define MAIN_WINDOW_SIZE sf::Vector2u(800, 600)
#define PROPERTIES_WINDOW_SIZE sf::Vector2u(350, 500)


#define FONT_GENERAL DEFAULT_CONTROLS_FONT


#define SCENE_TEXTURE	  "resources/background/scene_texture.png"
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



#define TEXTBOX_GENERAL				DEFAULT_TEXTBOX_TEXTURE


#define BUTTON_MOVE					"resources/button/button_move/button_move.png"
#define BUTTON_MOVE_PRESSED			"resources/button/button_move/button_move_pressed.png"

#define BUTTON_ROTATE				"resources/button/button_rotate/button_rotate.png"
#define BUTTON_ROTATE_PRESSED		"resources/button/button_rotate/button_rotate_pressed.png"

#define BUTTON_SCALE				"resources/button/button_scale/button_scale.png"
#define BUTTON_SCALE_PRESSED		"resources/button/button_scale/button_scale_pressed.png"

#define BUTTON_COLOR				"resources/button/button_color/button_color.png"
#define BUTTON_COLOR_PRESSED		"resources/button/button_color/button_color_pressed.png"



#define CHECKBOX_GENERAL			"resources/checkbox/checkbox_unchecked.png"
#define CHECKBOX_CHECKED_GENERAL	"resources/checkbox/checkbox_checked.png"




void enter_symbol(Textbox& textbox, uint32_t character)
{

	if (character > 25 && character < 36)
	{
		if (textbox.get_text().getString().getSize() < 6)
		{
			sf::String temp = textbox.get_text().getString();
			temp += character + 22;
			textbox.get_text().setString(temp);

		}
	}

	if (character == 59)
	{
		if (textbox.get_text().getString().getSize() > 0)
		{
			sf::String temp = textbox.get_text().getString();
			temp.erase(temp.getSize() - 1, 1);
			textbox.get_text().setString(temp);
		}
	}

}







int main()
{

	sf::RenderWindow main_window(sf::VideoMode(MAIN_WINDOW_SIZE.x, MAIN_WINDOW_SIZE.y), "Main window");

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


	sf::Font general_font;
	general_font.loadFromFile(FONT_GENERAL);

	// Creating background
	sf::Texture texture_top_panel;
	texture_top_panel.loadFromFile(TOP_PANEL_TEXTURE);
	Control_panel top_panel;
	top_panel.background.setTexture(texture_top_panel, true);



	// Setting button size(optional)
	const sf::Vector2i BUTTON_SIZE(50, 50);

	// Loading textures for top panel buttons
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

	// Creating buttons for top panel
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
	button_line.get_graphics().setTexture(texture_button_line);
	button_rectangle.get_graphics().setTexture(texture_button_rectangle);
	button_circle.get_graphics().setTexture(texture_button_circle);
	button_triangle.get_graphics().setTexture(texture_button_triangle);
	button_square.get_graphics().setTexture(texture_button_square);
	button_pentagon.get_graphics().setTexture(texture_button_pentagon);
	button_hexagon.get_graphics().setTexture(texture_button_hexagon);
	button_delete.get_graphics().setTexture(texture_button_delete);
	button_reset.get_graphics().setTexture(texture_button_reset);
	button_aggregate.get_graphics().setTexture(texture_button_aggregate);
	button_properties.get_graphics().setTexture(texture_button_properties);

	// Aligning buttons on the panel
	button_line.get_graphics().setPosition(60 * 0 + 10, 10);
	button_rectangle.get_graphics().setPosition(10 + 60 * 1 + 10, 10);
	button_circle.get_graphics().setPosition(20 + 60 * 2 + 10, 10);
	button_triangle.get_graphics().setPosition(30 + 60 * 3 + 10, 10);
	button_square.get_graphics().setPosition(40 + 60 * 4 + 10, 10);
	button_pentagon.get_graphics().setPosition(50 + 60 * 5 + 10, 10);
	button_hexagon.get_graphics().setPosition(60 + 60 * 6 + 10, 10);
	button_properties.get_graphics().setPosition(90 + 60 * 7 + 10, 10);
	button_reset.get_graphics().setPosition(100 + 60 * 8 + 10, 10);
	button_aggregate.get_graphics().setPosition(110 + 60 * 9 + 10, 10);
	button_delete.get_graphics().setPosition(120 + 60 * 10 + 10, 10);


	// Adding animation for top panel buttons
	class Button_texture_change_event_args : public Button_event_args
	{

	public:

		const sf::Texture& new_texture;

		Button_texture_change_event_args(Event_type event_type, const sf::Texture& new_texture) :
			Button_event_args(event_type), new_texture(new_texture) {}

	};

	void(*press)(Button*, Event_args*) = [](Button* button, Event_args* args)
		{
			if (auto texture_args = dynamic_cast<Button_texture_change_event_args*>(args))
			{
				button->get_graphics().setTexture(texture_args->new_texture);
			}
		};

	void(*release)(Button*, Event_args*) = [](Button* button, Event_args* args)
		{
			if (auto texture_args = dynamic_cast<Button_texture_change_event_args*>(args))
			{
				button->get_graphics().setTexture(texture_args->new_texture);
			}
		};

	button_line.add_event_handler(press, Button_event_args::CLICK);
	button_rectangle.add_event_handler(press, Button_event_args::CLICK);
	button_circle.add_event_handler(press, Button_event_args::CLICK);
	button_triangle.add_event_handler(press, Button_event_args::CLICK);
	button_square.add_event_handler(press, Button_event_args::CLICK);
	button_pentagon.add_event_handler(press, Button_event_args::CLICK);
	button_hexagon.add_event_handler(press, Button_event_args::CLICK);
	button_properties.add_event_handler(press, Button_event_args::CLICK);
	button_reset.add_event_handler(press, Button_event_args::CLICK);
	button_aggregate.add_event_handler(press, Button_event_args::CLICK);
	button_delete.add_event_handler(press, Button_event_args::CLICK);

	button_line.add_event_handler(release, Button_event_args::RELEASE);
	button_rectangle.add_event_handler(release, Button_event_args::RELEASE);
	button_circle.add_event_handler(release, Button_event_args::RELEASE);
	button_triangle.add_event_handler(release, Button_event_args::RELEASE);
	button_square.add_event_handler(release, Button_event_args::RELEASE);
	button_pentagon.add_event_handler(release, Button_event_args::RELEASE);
	button_hexagon.add_event_handler(release, Button_event_args::RELEASE);
	button_properties.add_event_handler(release, Button_event_args::RELEASE);
	button_reset.add_event_handler(release, Button_event_args::RELEASE);
	button_aggregate.add_event_handler(release, Button_event_args::RELEASE);
	button_delete.add_event_handler(release, Button_event_args::RELEASE);





	// Creating properties window
	sf::RenderWindow properties_window(sf::VideoMode(PROPERTIES_WINDOW_SIZE.x, PROPERTIES_WINDOW_SIZE.y), "Properties");
	properties_window.close();

	// Attaching opening properties window to the properties button
	class Button_open_properties_window_event_args : public Button_event_args
	{

	public:

		sf::RenderWindow& window;

		Button_open_properties_window_event_args(Event_type event_type, sf::RenderWindow& window) :
			Button_event_args(event_type), window(window) {}

	};

	void(*open_properties_window)(Button*, Event_args*) = [](Button* button, Event_args* args)
		{
			if (auto open_window_args = dynamic_cast<Button_open_properties_window_event_args*>(args))
			{
				open_window_args->window.create(sf::VideoMode(PROPERTIES_WINDOW_SIZE.x, PROPERTIES_WINDOW_SIZE.y), "Properties");
			}
		};
	button_properties.add_event_handler(open_properties_window, Button_event_args::CLICK);

	// Creating Labels
	sf::Text
		label_X("X: ", general_font, 50),
		label_Y("Y: ", general_font, 50),
		label_Z("Z: ", general_font, 50);

	label_X.setPosition(30, 30);
	label_Y.setPosition(30, 80);
	label_Z.setPosition(30, 130);


	// Creating textboxes
	sf::Texture texture_textbox;
	texture_textbox.loadFromFile(TEXTBOX_GENERAL);

	Textbox textbox_X, textbox_Y, textbox_Z;
	textbox_X.get_graphics().setTexture(texture_textbox);
	textbox_Y.get_graphics().setTexture(texture_textbox);
	textbox_Z.get_graphics().setTexture(texture_textbox);
	textbox_X.get_text().setFont(general_font);
	textbox_Y.get_text().setFont(general_font);
	textbox_Z.get_text().setFont(general_font);

	textbox_X.get_graphics().setPosition(80, 34);
	textbox_Y.get_graphics().setPosition(80, 88);
	textbox_Z.get_graphics().setPosition(80, 141);
	textbox_X.get_text().setPosition(80, 30);
	textbox_Y.get_text().setPosition(80, 80);
	textbox_Z.get_text().setPosition(80, 130);

	textbox_X.get_text().setFillColor(sf::Color::Black);
	textbox_Y.get_text().setFillColor(sf::Color::Black);
	textbox_Z.get_text().setFillColor(sf::Color::Black);

	textbox_X.get_text().setCharacterSize(45);
	textbox_Y.get_text().setCharacterSize(45);
	textbox_Z.get_text().setCharacterSize(45);



	// Loading textures for properties window buttons
	sf::Texture texture_button_move, texture_button_move_pressed,
		texture_button_rotate, texture_button_rotate_pressed,
		texture_button_scale, texture_button_scale_pressed,
		texture_button_color, texture_button_color_pressed;

	texture_button_move.loadFromFile(BUTTON_MOVE);
	texture_button_move_pressed.loadFromFile(BUTTON_MOVE_PRESSED);

	texture_button_rotate.loadFromFile(BUTTON_ROTATE);
	texture_button_rotate_pressed.loadFromFile(BUTTON_ROTATE_PRESSED);

	texture_button_scale.loadFromFile(BUTTON_SCALE);
	texture_button_scale_pressed.loadFromFile(BUTTON_SCALE_PRESSED);

	texture_button_color.loadFromFile(BUTTON_COLOR);
	texture_button_color_pressed.loadFromFile(BUTTON_COLOR_PRESSED);



	// Creating buttons for properties window
	Button button_move, button_rotate, button_scale, button_color;

	button_move.get_graphics().setTexture(texture_button_move);
	button_rotate.get_graphics().setTexture(texture_button_rotate);
	button_scale.get_graphics().setTexture(texture_button_scale);
	button_color.get_graphics().setTexture(texture_button_color);

	button_move.get_graphics().setPosition(20, 220);
	button_rotate.get_graphics().setPosition(180, 220);
	button_scale.get_graphics().setPosition(20, 330);
	button_color.get_graphics().setPosition(180, 330);


	// Adding animation for properties window buttons
	button_move.add_event_handler(press, Button_event_args::CLICK);
	button_rotate.add_event_handler(press, Button_event_args::CLICK);
	button_scale.add_event_handler(press, Button_event_args::CLICK);
	button_color.add_event_handler(press, Button_event_args::CLICK);

	button_move.add_event_handler(release, Button_event_args::RELEASE);
	button_rotate.add_event_handler(release, Button_event_args::RELEASE);
	button_scale.add_event_handler(release, Button_event_args::RELEASE);
	button_color.add_event_handler(release, Button_event_args::RELEASE);



	// Creating buttons for properties window
	Checkbox checkbox_enable_trace, checkbox_enable_move_by_law;

	sf::Texture texture_checkbox_general, texture_checkbox_checked_general;
	texture_checkbox_general.loadFromFile(CHECKBOX_GENERAL);
	texture_checkbox_checked_general.loadFromFile(CHECKBOX_CHECKED_GENERAL);

	checkbox_enable_trace.get_graphics().setTexture(texture_checkbox_general);
	checkbox_enable_move_by_law.get_graphics().setTexture(texture_checkbox_general);
	checkbox_enable_trace.get_text().setFont(general_font);
	checkbox_enable_move_by_law.get_text().setFont(general_font);
	checkbox_enable_trace.get_text().setCharacterSize(30);
	checkbox_enable_move_by_law.get_text().setCharacterSize(30);

	checkbox_enable_trace.get_text().setString("trace");
	checkbox_enable_move_by_law.get_text().setString("move by law");

	checkbox_enable_trace.get_graphics().setPosition(20, 440);
	checkbox_enable_trace.get_text().setPosition(50, 430);

	checkbox_enable_move_by_law.get_graphics().setPosition(150, 440);
	checkbox_enable_move_by_law.get_text().setPosition(180, 430);


	// Adding animation for properties window buttons
	class Checkbox_texture_change_event_args : public Checkbox_event_args
	{

	public:

		const sf::Texture& new_texture;

		Checkbox_texture_change_event_args(Event_type event_type, const sf::Texture& new_texture) :
			Checkbox_event_args(event_type), new_texture(new_texture) {}

	};

	void(*check)(Checkbox*, Event_args*) = [](Checkbox* checkbox, Event_args* args)
		{

			if (auto texture_args = dynamic_cast<Checkbox_texture_change_event_args*>(args))
			{
				checkbox->get_graphics().setTexture(texture_args->new_texture);
			}

		};

	checkbox_enable_trace.add_event_handler(check, Checkbox_event_args::CHECK);
	checkbox_enable_move_by_law.add_event_handler(check, Checkbox_event_args::CHECK);






	// Creating main scene
	sf::Texture main_scene_texture;
	main_scene_texture.loadFromFile(SCENE_TEXTURE);

	Scene main_scene;
	main_scene.get_backgruond().setTexture(main_scene_texture);

	class Scene_action_event_args : public Event_args
	{

	public:

		Scene& scene;

		Scene_action_event_args(Scene& scene) : scene(scene) {}

	};






	sf::Clock clock;

	while (main_window.isOpen())
	{

		if (clock.getElapsedTime().asMilliseconds() > 50)
		{

			clock.restart();

			sf::Event main_event;

			while (main_window.pollEvent(main_event))
			{

				if (main_event.type == sf::Event::Closed)
				{

					main_window.close();

				}

				if (main_event.type == sf::Event::MouseMoved)
				{

					if (top_panel.cursor_inside(sf::Mouse::getPosition(main_window)))
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



				}

				if (main_event.type == sf::Event::MouseButtonPressed)
				{

					if (top_panel.cursor_inside(sf::Mouse::getPosition(main_window)))
					{

						const size_t PARAM_COUNT = 3;
						Event_args* args_arr[PARAM_COUNT]{};

						Button_texture_change_event_args button_propeties_args0(Button_event_args::CLICK, texture_button_properties_pressed);
						Button_open_properties_window_event_args button_propeties_args1(Button_event_args::CLICK, properties_window);
						args_arr[0] = &button_propeties_args0;
						args_arr[1] = &button_propeties_args1;
						if (button_properties.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


						Button_texture_change_event_args button_delete_args(Button_event_args::CLICK, texture_button_delete_pressed);
						args_arr[0] = &button_delete_args;
						if (button_delete.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


						Button_texture_change_event_args button_reset_args(Button_event_args::CLICK, texture_button_reset_pressed);
						args_arr[0] = &button_reset_args;
						if (button_reset.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


						Button_texture_change_event_args button_aggregate_args(Button_event_args::CLICK, texture_button_aggregate_pressed);
						args_arr[0] = &button_aggregate_args;
						if (button_aggregate.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;



						Button_texture_change_event_args button_line_args(Button_event_args::CLICK, texture_button_line_pressed);
						args_arr[0] = &button_line_args;
						if (button_line.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


						Button_texture_change_event_args button_rectangle_args(Button_event_args::CLICK, texture_button_rectangle_pressed);
						args_arr[0] = &button_rectangle_args;
						if (button_rectangle.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


						Button_texture_change_event_args button_circle_args(Button_event_args::CLICK, texture_button_circle_pressed);
						args_arr[0] = &button_circle_args;
						if (button_circle.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


						Button_texture_change_event_args button_triangle_args(Button_event_args::CLICK, texture_button_triangle_pressed);
						args_arr[0] = &button_triangle_args;
						if (button_triangle.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


						Button_texture_change_event_args button_square_args(Button_event_args::CLICK, texture_button_square_pressed);
						args_arr[0] = &button_square_args;
						if (button_square.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


						Button_texture_change_event_args button_pentagon_args(Button_event_args::CLICK, texture_button_pentagon_pressed);
						args_arr[0] = &button_pentagon_args;
						if (button_pentagon.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


						Button_texture_change_event_args button_hexagon_args(Button_event_args::CLICK, texture_button_hexagon_pressed);
						args_arr[0] = &button_hexagon_args;
						if (button_hexagon.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;



					}



				}

				if (main_event.type == sf::Event::MouseButtonReleased)
				{

					const size_t PARAM_COUNT = 3;
					Event_args* args_arr[PARAM_COUNT]{};

					Button_texture_change_event_args button_properties_args(Button_event_args::RELEASE, texture_button_properties);
					args_arr[0] = &button_properties_args;
					if (button_properties.try_release(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


					Button_texture_change_event_args button_delete_args(Button_event_args::RELEASE, texture_button_delete);
					args_arr[0] = &button_delete_args;
					if (button_delete.try_release(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


					Button_texture_change_event_args button_reset_args(Button_event_args::RELEASE, texture_button_reset);
					args_arr[0] = &button_reset_args;
					if (button_reset.try_release(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


					Button_texture_change_event_args button_aggregate_args(Button_event_args::RELEASE, texture_button_aggregate);
					args_arr[0] = &button_aggregate_args;
					if (button_aggregate.try_release(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;



					Button_texture_change_event_args button_line_args(Button_event_args::RELEASE, texture_button_line);
					args_arr[0] = &button_line_args;
					if (button_line.try_release(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


					Button_texture_change_event_args button_rectangle_args(Button_event_args::RELEASE, texture_button_rectangle);
					args_arr[0] = &button_rectangle_args;
					if (button_rectangle.try_release(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


					Button_texture_change_event_args button_circle_args(Button_event_args::RELEASE, texture_button_circle);
					args_arr[0] = &button_circle_args;
					if (button_circle.try_release(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


					Button_texture_change_event_args button_triangle_args(Button_event_args::RELEASE, texture_button_triangle);
					args_arr[0] = &button_triangle_args;
					if (button_triangle.try_release(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


					Button_texture_change_event_args button_square_args(Button_event_args::RELEASE, texture_button_square);
					args_arr[0] = &button_square_args;
					if (button_square.try_release(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


					Button_texture_change_event_args button_pentagon_args(Button_event_args::RELEASE, texture_button_pentagon);
					args_arr[0] = &button_pentagon_args;
					if (button_pentagon.try_release(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


					Button_texture_change_event_args button_hexagon_args(Button_event_args::RELEASE, texture_button_hexagon);
					args_arr[0] = &button_hexagon_args;
					if (button_hexagon.try_release(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;



				}



			}



			while (properties_window.pollEvent(main_event))
			{

				if (main_event.type == sf::Event::Closed)
				{

					properties_window.close();

				}

				if (main_event.type == sf::Event::MouseMoved)
				{

					if (!button_move.is_hovered())
						button_move.try_hover(sf::Mouse::getPosition(properties_window));
					else
						button_move.try_unhover(sf::Mouse::getPosition(properties_window));


					if (!button_rotate.is_hovered())
						button_rotate.try_hover(sf::Mouse::getPosition(properties_window));
					else
						button_rotate.try_unhover(sf::Mouse::getPosition(properties_window));


					if (!button_scale.is_hovered())
						button_scale.try_hover(sf::Mouse::getPosition(properties_window));
					else
						button_scale.try_unhover(sf::Mouse::getPosition(properties_window));


					if (!button_color.is_hovered())
						button_color.try_hover(sf::Mouse::getPosition(properties_window));
					else
						button_color.try_unhover(sf::Mouse::getPosition(properties_window));



					if (!textbox_X.is_hovered())
						textbox_X.try_hover(sf::Mouse::getPosition(properties_window));
					else
						textbox_X.try_unhover(sf::Mouse::getPosition(properties_window));


					if (!textbox_Y.is_hovered())
						textbox_Y.try_hover(sf::Mouse::getPosition(properties_window));
					else
						textbox_Y.try_unhover(sf::Mouse::getPosition(properties_window));


					if (!textbox_Z.is_hovered())
						textbox_Z.try_hover(sf::Mouse::getPosition(properties_window));
					else
						textbox_Z.try_unhover(sf::Mouse::getPosition(properties_window));



					if (!checkbox_enable_trace.is_hovered())
						checkbox_enable_trace.try_hover(sf::Mouse::getPosition(properties_window));
					else
						checkbox_enable_trace.try_unhover(sf::Mouse::getPosition(properties_window));


					if (!checkbox_enable_move_by_law.is_hovered())
						checkbox_enable_move_by_law.try_hover(sf::Mouse::getPosition(properties_window));
					else
						checkbox_enable_move_by_law.try_unhover(sf::Mouse::getPosition(properties_window));

				}

				if (main_event.type == sf::Event::MouseButtonPressed)
				{

					const size_t PARAM_COUNT = 3;
					Event_args* args_arr[PARAM_COUNT]{};

					Button_texture_change_event_args button_move_args(Button_event_args::CLICK, texture_button_move_pressed);
					args_arr[0] = &button_move_args;
					if (button_move.try_click(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


					Button_texture_change_event_args button_rotate_args(Button_event_args::CLICK, texture_button_rotate_pressed);
					args_arr[0] = &button_rotate_args;
					if (button_rotate.try_click(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


					Button_texture_change_event_args button_scale_args(Button_event_args::CLICK, texture_button_scale_pressed);
					args_arr[0] = &button_scale_args;
					if (button_scale.try_click(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


					Button_texture_change_event_args button_color_args(Button_event_args::CLICK, texture_button_color_pressed);
					args_arr[0] = &button_color_args;
					if (button_color.try_click(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;



					if (textbox_X.try_click())
						break;

					if (textbox_Y.try_click())
						break;

					if (textbox_Z.try_click())
						break;



					if (checkbox_enable_trace.is_checked())
					{
						Checkbox_texture_change_event_args checkbox_trace_args(Checkbox_event_args::CHECK, texture_checkbox_general);
						args_arr[0] = &checkbox_trace_args;
						if (checkbox_enable_trace.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}
					else
					{
						Checkbox_texture_change_event_args checkbox_trace_args(Checkbox_event_args::CHECK, texture_checkbox_checked_general);
						args_arr[0] = &checkbox_trace_args;
						if (checkbox_enable_trace.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}

					if (checkbox_enable_move_by_law.is_checked())
					{
						Checkbox_texture_change_event_args checkbox_move_by_law_args(Checkbox_event_args::CHECK, texture_checkbox_general);
						args_arr[0] = &checkbox_move_by_law_args;
						if (checkbox_enable_move_by_law.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}
					else
					{
						Checkbox_texture_change_event_args checkbox_move_by_law_args(Checkbox_event_args::CHECK, texture_checkbox_checked_general);
						args_arr[0] = &checkbox_move_by_law_args;
						if (checkbox_enable_move_by_law.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}

				}

				if (main_event.type == sf::Event::MouseButtonReleased)
				{

					const size_t PARAM_COUNT = 3;
					Event_args* args_arr[PARAM_COUNT]{};

					Button_texture_change_event_args button_move_args(Button_event_args::RELEASE, texture_button_move);
					args_arr[0] = &button_move_args;
					if (button_move.try_release(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


					Button_texture_change_event_args button_rotate_args(Button_event_args::RELEASE, texture_button_rotate);
					args_arr[0] = &button_rotate_args;
					if (button_rotate.try_release(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


					Button_texture_change_event_args button_scale_args(Button_event_args::RELEASE, texture_button_scale);
					args_arr[0] = &button_scale_args;
					if (button_scale.try_release(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;


					Button_texture_change_event_args button_color_args(Button_event_args::RELEASE, texture_button_color);
					args_arr[0] = &button_color_args;
					if (button_color.try_release(args_arr, PARAM_COUNT))
						break;
					else
						args_arr[0] = args_arr[1] = args_arr[2] = nullptr;



					if (textbox_X.try_release())
						break;
					if (textbox_Y.try_release())
						break;
					if (textbox_Z.try_release())
						break;

				}

				if (main_event.type == sf::Event::KeyPressed)
				{

					if (textbox_X.is_active())
					{
						enter_symbol(textbox_X, main_event.key.code);
						break;
					}
					if (textbox_Y.is_active())
					{
						enter_symbol(textbox_Y, main_event.key.code);
						break;
					}
					if (textbox_Z.is_active())
					{
						enter_symbol(textbox_Z, main_event.key.code);
						break;
					}

				}



			}



			properties_window.clear(sf::Color(153, 153, 153));

			properties_window.draw(textbox_X);
			properties_window.draw(textbox_Y);
			properties_window.draw(textbox_Z);
			properties_window.draw(label_X);
			properties_window.draw(label_Y);
			properties_window.draw(label_Z);
			properties_window.draw(button_move);
			properties_window.draw(button_rotate);
			properties_window.draw(button_scale);
			properties_window.draw(button_color);
			properties_window.draw(checkbox_enable_trace);
			properties_window.draw(checkbox_enable_move_by_law);

			properties_window.display();





			main_window.clear();
			main_window.draw(main_scene);

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

	}

	return 0;

}