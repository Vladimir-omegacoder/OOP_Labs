#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Interface/Controls.h"
#include "gui_app_config/Scene.h"





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

#define BUTTON_AGGREGATE			"resources/button/button_aggregate/button_aggregate.png"
#define BUTTON_AGGREGATE_PRESSED	"resources/button/button_aggregate/button_aggregate_pressed.png"

#define BUTTON_PROPERTIES			"resources/button/button_properties/button_properties.png"
#define BUTTON_PROPERTIES_PRESSED	"resources/button/button_properties/button_properties_pressed.png"

#define BUTTON_COPY					"resources/button/button_copy/button_copy.png"
#define BUTTON_COPY_PRESSED			"resources/button/button_copy/button_copy_pressed.png"

#define BUTTON_PASTE				"resources/button/button_paste/button_paste.png"
#define BUTTON_PASTE_PRESSED		"resources/button/button_paste/button_paste_pressed.png"

#define BUTTON_SAVE					"resources/button/button_save/button_save.png"
#define BUTTON_SAVE_PRESSED			"resources/button/button_save/button_save_pressed.png"

#define BUTTON_LOAD					"resources/button/button_load/button_load.png"
#define BUTTON_LOAD_PRESSED			"resources/button/button_load/button_load_pressed.png"



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

	if (character == 56)
	{
		if (textbox.get_text().getString().getSize() == 0)
		{
			sf::String temp = textbox.get_text().getString();
			temp += (char)45;
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

	sf::Vector2u MAIN_WINDOW_SIZE = sf::Vector2u(800, 600);
	sf::Vector2u PROPERTIES_WINDOW_SIZE = sf::Vector2u(350, 500);

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
			b = a + sf::Vector2f(background.getLocalBounds().getSize().x * background.getScale().x,
				background.getLocalBounds().getSize().y * background.getScale().y);

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



	sf::Vector2f GLOBAL_SCALE{ MAIN_WINDOW_SIZE.x / 800.f, MAIN_WINDOW_SIZE.y / 600.f };

	sf::Font general_font;
	general_font.loadFromFile(FONT_GENERAL);

	// Creating top panel
	sf::Texture texture_top_panel;
	texture_top_panel.loadFromFile(TOP_PANEL_TEXTURE);
	Control_panel top_panel;
	top_panel.background.setTexture(texture_top_panel, true);
	top_panel.background.setScale(1 * GLOBAL_SCALE.x, 6 / 8.f * GLOBAL_SCALE.y);



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
		texture_button_aggregate, texture_button_aggregate_pressed,
		texture_button_properties, texture_button_properties_pressed,
		texture_button_copy, texture_button_copy_pressed,
		texture_button_paste, texture_button_paste_pressed,
		texture_button_save, texture_button_save_pressed,
		texture_button_load, texture_button_load_pressed;

	{
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

		texture_button_aggregate.loadFromFile(BUTTON_AGGREGATE);
		texture_button_aggregate_pressed.loadFromFile(BUTTON_AGGREGATE_PRESSED);

		texture_button_properties.loadFromFile(BUTTON_PROPERTIES);
		texture_button_properties_pressed.loadFromFile(BUTTON_PROPERTIES_PRESSED);

		texture_button_copy.loadFromFile(BUTTON_COPY);
		texture_button_copy_pressed.loadFromFile(BUTTON_COPY_PRESSED);

		texture_button_paste.loadFromFile(BUTTON_PASTE);
		texture_button_paste_pressed.loadFromFile(BUTTON_PASTE_PRESSED);

		texture_button_save.loadFromFile(BUTTON_SAVE);
		texture_button_save_pressed.loadFromFile(BUTTON_SAVE_PRESSED);

		texture_button_load.loadFromFile(BUTTON_LOAD);
		texture_button_load_pressed.loadFromFile(BUTTON_LOAD_PRESSED);

	}



	// Creating buttons for top panel
	Button button_line,
		button_rectangle,
		button_circle,
		button_triangle,
		button_square,
		button_pentagon,
		button_hexagon,
		button_delete,
		button_aggregate,
		button_properties,
		button_copy,
		button_paste,
		button_save,
		button_load;

	const sf::Vector2f b_size = sf::Vector2f(45, 45);
	const sf::Vector2f b_spacing = sf::Vector2f(8, 8);

	// Applying loaded textures to the buttons
	{

		button_line.get_graphics().setTexture(texture_button_line);
		button_line.get_graphics().setScale(b_size.x / texture_button_line.getSize().x * GLOBAL_SCALE.x,
			b_size.y / texture_button_line.getSize().y * GLOBAL_SCALE.y);

		button_rectangle.get_graphics().setTexture(texture_button_rectangle);
		button_rectangle.get_graphics().setScale(b_size.x / texture_button_rectangle.getSize().x * GLOBAL_SCALE.x,
			b_size.y / texture_button_rectangle.getSize().y * GLOBAL_SCALE.y);

		button_circle.get_graphics().setTexture(texture_button_circle);
		button_circle.get_graphics().setScale(b_size.x / texture_button_circle.getSize().x * GLOBAL_SCALE.x,
			b_size.y / texture_button_circle.getSize().y * GLOBAL_SCALE.y);

		button_triangle.get_graphics().setTexture(texture_button_triangle);
		button_triangle.get_graphics().setScale(b_size.x / texture_button_triangle.getSize().x * GLOBAL_SCALE.x,
			b_size.y / texture_button_triangle.getSize().y * GLOBAL_SCALE.y);

		button_square.get_graphics().setTexture(texture_button_square);
		button_square.get_graphics().setScale(b_size.x / texture_button_square.getSize().x * GLOBAL_SCALE.x,
			b_size.y / texture_button_square.getSize().y * GLOBAL_SCALE.y);

		button_pentagon.get_graphics().setTexture(texture_button_pentagon);
		button_pentagon.get_graphics().setScale(b_size.x / texture_button_pentagon.getSize().x * GLOBAL_SCALE.x,
			b_size.y / texture_button_pentagon.getSize().y * GLOBAL_SCALE.y);

		button_hexagon.get_graphics().setTexture(texture_button_hexagon);
		button_hexagon.get_graphics().setScale(b_size.x / texture_button_hexagon.getSize().x * GLOBAL_SCALE.x,
			b_size.y / texture_button_hexagon.getSize().y * GLOBAL_SCALE.y);

		button_delete.get_graphics().setTexture(texture_button_delete);
		button_delete.get_graphics().setScale(b_size.x / texture_button_delete.getSize().x * GLOBAL_SCALE.x,
			b_size.y / texture_button_delete.getSize().y * GLOBAL_SCALE.y);

		button_aggregate.get_graphics().setTexture(texture_button_aggregate);
		button_aggregate.get_graphics().setScale(b_size.x / texture_button_aggregate.getSize().x * GLOBAL_SCALE.x,
			b_size.y / texture_button_aggregate.getSize().y * GLOBAL_SCALE.y);

		button_properties.get_graphics().setTexture(texture_button_properties);
		button_properties.get_graphics().setScale(b_size.x / texture_button_properties.getSize().x * GLOBAL_SCALE.x,
			b_size.y / texture_button_properties.getSize().y * GLOBAL_SCALE.y);

		button_copy.get_graphics().setTexture(texture_button_copy);
		button_copy.get_graphics().setScale(b_size.x / texture_button_copy.getSize().x * GLOBAL_SCALE.x,
			b_size.y / texture_button_copy.getSize().y * GLOBAL_SCALE.y);

		button_paste.get_graphics().setTexture(texture_button_paste);
		button_paste.get_graphics().setScale(b_size.x / texture_button_paste.getSize().x * GLOBAL_SCALE.x,
			b_size.y / texture_button_paste.getSize().y * GLOBAL_SCALE.y);

		button_save.get_graphics().setTexture(texture_button_save);
		button_save.get_graphics().setScale(b_size.x / texture_button_save.getSize().x * GLOBAL_SCALE.x,
			b_size.y / texture_button_save.getSize().y * GLOBAL_SCALE.y);

		button_load.get_graphics().setTexture(texture_button_load);
		button_load.get_graphics().setScale(b_size.x / texture_button_load.getSize().x * GLOBAL_SCALE.x,
			b_size.y / texture_button_load.getSize().y * GLOBAL_SCALE.y);

	}

	// Aligning buttons on the panel
	{

		float padding1 = 25;
		float padding2 = padding1 + 25;

		button_line.get_graphics().setPosition((4 * (b_spacing.x + b_size.x) + b_spacing.x + padding1) * GLOBAL_SCALE.x, b_spacing.y * GLOBAL_SCALE.y);
		button_rectangle.get_graphics().setPosition((5 * (b_spacing.x + b_size.x) + b_spacing.x + padding1) * GLOBAL_SCALE.x, b_spacing.y * GLOBAL_SCALE.y);
		button_circle.get_graphics().setPosition((6 * (b_spacing.x + b_size.x) + b_spacing.x + padding1) * GLOBAL_SCALE.x, b_spacing.y * GLOBAL_SCALE.y);
		button_triangle.get_graphics().setPosition((7 * (b_spacing.x + b_size.x) + b_spacing.x + padding1) * GLOBAL_SCALE.x, b_spacing.y * GLOBAL_SCALE.y);
		button_square.get_graphics().setPosition((8 * (b_spacing.x + b_size.x) + b_spacing.x + padding1) * GLOBAL_SCALE.x, b_spacing.y * GLOBAL_SCALE.y);
		button_pentagon.get_graphics().setPosition((9 * (b_spacing.x + b_size.x) + b_spacing.x + padding1) * GLOBAL_SCALE.x, b_spacing.y * GLOBAL_SCALE.y);
		button_hexagon.get_graphics().setPosition((10 * (b_spacing.x + b_size.x) + b_spacing.x + padding1) * GLOBAL_SCALE.x, b_spacing .y* GLOBAL_SCALE.y);
		button_properties.get_graphics().setPosition((11 * (b_spacing.x + b_size.x) + b_spacing.x + padding2) * GLOBAL_SCALE.x, b_spacing.y * GLOBAL_SCALE.y);
		button_aggregate.get_graphics().setPosition((12 * (b_spacing.x + b_size.x) + b_spacing.x + padding2) * GLOBAL_SCALE.x, b_spacing.y * GLOBAL_SCALE.y);
		button_delete.get_graphics().setPosition((13 * (b_spacing.x + b_size.x) + b_spacing.x + padding2) * GLOBAL_SCALE.x, b_spacing.y * GLOBAL_SCALE.y);
		button_copy.get_graphics().setPosition((2 * (b_spacing.x + b_size.x) + b_spacing.x) * GLOBAL_SCALE.x, b_spacing.y * GLOBAL_SCALE.y);
		button_paste.get_graphics().setPosition((3 * (b_spacing.x + b_size.x) + b_spacing.x) * GLOBAL_SCALE.x, b_spacing.y * GLOBAL_SCALE.y);
		button_save.get_graphics().setPosition((0 * (b_spacing.x + b_size.x) + b_spacing.x) * GLOBAL_SCALE.x, b_spacing.y * GLOBAL_SCALE.y);
		button_load.get_graphics().setPosition((1 * (b_spacing.x + b_size.x) + b_spacing.x) * GLOBAL_SCALE.x, b_spacing.y * GLOBAL_SCALE.y);

	}


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

	{

		button_line.add_event_handler(press, Button_event_args::CLICK);
		button_rectangle.add_event_handler(press, Button_event_args::CLICK);
		button_circle.add_event_handler(press, Button_event_args::CLICK);
		button_triangle.add_event_handler(press, Button_event_args::CLICK);
		button_square.add_event_handler(press, Button_event_args::CLICK);
		button_pentagon.add_event_handler(press, Button_event_args::CLICK);
		button_hexagon.add_event_handler(press, Button_event_args::CLICK);
		button_properties.add_event_handler(press, Button_event_args::CLICK);
		button_aggregate.add_event_handler(press, Button_event_args::CLICK);
		button_delete.add_event_handler(press, Button_event_args::CLICK);
		button_copy.add_event_handler(press, Button_event_args::CLICK);
		button_paste.add_event_handler(press, Button_event_args::CLICK);
		button_save.add_event_handler(press, Button_event_args::CLICK);
		button_load.add_event_handler(press, Button_event_args::CLICK);

		button_line.add_event_handler(release, Button_event_args::RELEASE);
		button_rectangle.add_event_handler(release, Button_event_args::RELEASE);
		button_circle.add_event_handler(release, Button_event_args::RELEASE);
		button_triangle.add_event_handler(release, Button_event_args::RELEASE);
		button_square.add_event_handler(release, Button_event_args::RELEASE);
		button_pentagon.add_event_handler(release, Button_event_args::RELEASE);
		button_hexagon.add_event_handler(release, Button_event_args::RELEASE);
		button_properties.add_event_handler(release, Button_event_args::RELEASE);
		button_aggregate.add_event_handler(release, Button_event_args::RELEASE);
		button_delete.add_event_handler(release, Button_event_args::RELEASE);
		button_copy.add_event_handler(release, Button_event_args::RELEASE);
		button_paste.add_event_handler(release, Button_event_args::RELEASE);
		button_save.add_event_handler(release, Button_event_args::RELEASE);
		button_load.add_event_handler(release, Button_event_args::RELEASE);

	}





	// Creating properties window
	sf::RenderWindow properties_window(sf::VideoMode(PROPERTIES_WINDOW_SIZE.x, PROPERTIES_WINDOW_SIZE.y), "Properties");
	properties_window.close();

	// Attaching opening properties window to the properties button
	class Button_open_properties_window_event_args : public Button_event_args
	{

	public:

		sf::RenderWindow& window;
		sf::Vector2u window_size;

		Button_open_properties_window_event_args(Event_type event_type, sf::RenderWindow& window, const sf::Vector2u& size) :
			Button_event_args(event_type), window(window), window_size(size) {}

	};

	void(*open_properties_window)(Button*, Event_args*) = [](Button* button, Event_args* args)
		{
			if (auto open_window_args = dynamic_cast<Button_open_properties_window_event_args*>(args))
			{
				open_window_args->window.create(sf::VideoMode(open_window_args->window_size.x, open_window_args->window_size.y), "Properties");
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
	{
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
	}



	// Loading textures for properties window buttons
	sf::Texture texture_button_move, texture_button_move_pressed,
		texture_button_rotate, texture_button_rotate_pressed,
		texture_button_scale, texture_button_scale_pressed,
		texture_button_color, texture_button_color_pressed;

	{
		texture_button_move.loadFromFile(BUTTON_MOVE);
		texture_button_move_pressed.loadFromFile(BUTTON_MOVE_PRESSED);

		texture_button_rotate.loadFromFile(BUTTON_ROTATE);
		texture_button_rotate_pressed.loadFromFile(BUTTON_ROTATE_PRESSED);

		texture_button_scale.loadFromFile(BUTTON_SCALE);
		texture_button_scale_pressed.loadFromFile(BUTTON_SCALE_PRESSED);

		texture_button_color.loadFromFile(BUTTON_COLOR);
		texture_button_color_pressed.loadFromFile(BUTTON_COLOR_PRESSED);
	}



	// Creating buttons for properties window
	Button button_move, button_rotate, button_scale, button_color;

	{
		button_move.get_graphics().setTexture(texture_button_move);
		button_rotate.get_graphics().setTexture(texture_button_rotate);
		button_scale.get_graphics().setTexture(texture_button_scale);
		button_color.get_graphics().setTexture(texture_button_color);

		button_move.get_graphics().setPosition(20, 220);
		button_rotate.get_graphics().setPosition(180, 220);
		button_scale.get_graphics().setPosition(20, 330);
		button_color.get_graphics().setPosition(180, 330);
	}


	// Adding animation for properties window buttons
	{
		button_move.add_event_handler(press, Button_event_args::CLICK);
		button_rotate.add_event_handler(press, Button_event_args::CLICK);
		button_scale.add_event_handler(press, Button_event_args::CLICK);
		button_color.add_event_handler(press, Button_event_args::CLICK);

		button_move.add_event_handler(release, Button_event_args::RELEASE);
		button_rotate.add_event_handler(release, Button_event_args::RELEASE);
		button_scale.add_event_handler(release, Button_event_args::RELEASE);
		button_color.add_event_handler(release, Button_event_args::RELEASE);
	}



	// Creating buttons for properties window
	Checkbox checkbox_enable_trace, checkbox_enable_move_by_law;

	sf::Texture texture_checkbox_general, texture_checkbox_checked_general;
	texture_checkbox_general.loadFromFile(CHECKBOX_GENERAL);
	texture_checkbox_checked_general.loadFromFile(CHECKBOX_CHECKED_GENERAL);

	{
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
	}


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

	Scene& main_scene = *Scene::get_instance();
	main_scene.set_scene_size(sf::Vector2u(MAIN_WINDOW_SIZE.x,
		MAIN_WINDOW_SIZE.y - top_panel.background.getLocalBounds().height * top_panel.background.getScale().y));
	main_scene.get_backgruond().setTexture(main_scene_texture);
	main_scene.get_backgruond().setScale(GLOBAL_SCALE);

	class Scene_create_actor_event_args : public Button_event_args 
	{

	public:

		Scene& scene;
		Scene::Actor&& actor;

		Scene_create_actor_event_args(Event_type event_type, Scene& scene, Scene::Actor&& actor) :
			Button_event_args(event_type), scene(scene), actor(std::move(actor)) {}

	};

	void(*create_actor)(Button*, Event_args*) = [](Button* button, Event_args* args)
		{

			if (auto action_args = dynamic_cast<Scene_create_actor_event_args*>(args))
			{
				action_args->scene.add_actor(std::move(action_args->actor));
			}

		};

	button_line.add_event_handler(create_actor, Button_event_args::CLICK);
	button_rectangle.add_event_handler(create_actor, Button_event_args::CLICK);
	button_circle.add_event_handler(create_actor, Button_event_args::CLICK);
	button_triangle.add_event_handler(create_actor, Button_event_args::CLICK);
	button_square.add_event_handler(create_actor, Button_event_args::CLICK);
	button_pentagon.add_event_handler(create_actor, Button_event_args::CLICK);
	button_hexagon.add_event_handler(create_actor, Button_event_args::CLICK);


	class Scene_action_actor_event_args : public Button_event_args
	{

	public:

		Scene& scene;

		Scene_action_actor_event_args(Event_type event_type, Scene& scene) :
			Button_event_args(event_type), scene(scene) {}

	};

	void(*delete_actor)(Button*, Event_args*) = [](Button* button, Event_args* args)
		{

			if (auto action_args = dynamic_cast<Scene_action_actor_event_args*>(args))
			{
				action_args->scene.remove_selected_actors();
			}

		};

	button_delete.add_event_handler(delete_actor, Button_event_args::CLICK);


	class Move_actor_event_args : public Scene_action_actor_event_args
	{

	public:

		const sf::Vector2f offset;
		const sf::Vector2u scene_size;

		Move_actor_event_args(Event_type event_type, Scene& scene, const sf::Vector2f offset, const sf::Vector2u scene_size) :
			Scene_action_actor_event_args(event_type, scene), offset(offset), scene_size(scene_size) {}

	};

	class Rotate_actor_event_args : public Scene_action_actor_event_args
	{

	public:

		const float angle;

		Rotate_actor_event_args(Event_type event_type, Scene& scene, float angle) :
			Scene_action_actor_event_args(event_type, scene), angle(angle) {}

	};

	class Scale_actor_event_args : public Scene_action_actor_event_args
	{

	public:

		const sf::Vector2f factor;

		Scale_actor_event_args(Event_type event_type, Scene& scene, sf::Vector2f factor) :
			Scene_action_actor_event_args(event_type, scene), factor(factor) {}

	};

	class Color_actor_event_args : public Scene_action_actor_event_args
	{

	public:

		const sf::Color color;

		Color_actor_event_args(Event_type event_type, Scene& scene, sf::Color color) :
			Scene_action_actor_event_args(event_type, scene), color(color) {}

	};


	void(*move_actor)(Button*, Event_args*) = [](Button* button, Event_args* args)
		{

			if (auto action_args = dynamic_cast<Move_actor_event_args*>(args))
			{

				for (auto& i : action_args->scene.get_selection())
				{

					//sf::FloatRect shape_bounds = action_args->scene.get_selected_actor()->operator->()->get_global_bounds();
					sf::FloatRect shape_bounds = (*i)->get_global_bounds();
					shape_bounds.left *= action_args->scene.get_backgruond().getScale().x;
					shape_bounds.top *= action_args->scene.get_backgruond().getScale().y;
					shape_bounds.width *= action_args->scene.get_backgruond().getScale().x;
					shape_bounds.height *= action_args->scene.get_backgruond().getScale().y;
					if (shape_bounds.left + action_args->offset.x < 0
						|| shape_bounds.left + shape_bounds.width + action_args->offset.x > action_args->scene_size.x
						|| shape_bounds.top + action_args->offset.y < 0
						|| shape_bounds.top + shape_bounds.height + action_args->offset.y > action_args->scene_size.y + 80)
					{
						return;
					}

					//action_args->scene.get_selected_actor()->operator->()->move(action_args->offset);
					(*i)->move(action_args->offset);

				}

			}

		};

	button_move.add_event_handler(move_actor, Button_event_args::CLICK);

	void(*rotate_actor)(Button*, Event_args*) = [](Button* button, Event_args* args)
		{

			if (auto action_args = dynamic_cast<Rotate_actor_event_args*>(args))
			{
				if (action_args->angle == 0)
				{
					return;
				}

				for (auto& i : action_args->scene.get_selection())
				{
					(*i)->rotate(action_args->angle);
				}

				//action_args->scene.get_selected_actor()->operator->()->rotate(action_args->angle);
			}

		};

	button_rotate.add_event_handler(rotate_actor, Button_event_args::CLICK);

	void(*scale_actor)(Button*, Event_args*) = [](Button* button, Event_args* args)
		{

			if (auto action_args = dynamic_cast<Scale_actor_event_args*>(args))
			{
				if (action_args->factor == sf::Vector2f(0, 0))
				{
					return;
				}

				for (auto& i : action_args->scene.get_selection())
				{
					(*i)->scale(action_args->factor);
				}

				//action_args->scene.get_selected_actor()->operator->()->scale(action_args->factor);
			}

		};

	button_scale.add_event_handler(scale_actor, Button_event_args::CLICK);

	void(*color_actor)(Button*, Event_args*) = [](Button* button, Event_args* args)
		{

			if (auto action_args = dynamic_cast<Color_actor_event_args*>(args))
			{
				for (auto& i : action_args->scene.get_selection())
				{
					(*i)->set_fill_color(action_args->color);
				}

				//action_args->scene.get_selected_actor()->operator->()->set_fill_color(action_args->color);
			}

		};

	button_color.add_event_handler(color_actor, Button_event_args::CLICK);


	void(*aggregate_selected)(Button*, Event_args*) = [](Button* button, Event_args* args)
		{

			if (auto action_args = dynamic_cast<Scene_action_actor_event_args*>(args))
			{
				action_args->scene.aggregate_selected();
			}

		};

	button_aggregate.add_event_handler(aggregate_selected, Button_event_args::CLICK);


	void(*copy_selected)(Button*, Event_args*) = [](Button* button, Event_args* args)
		{

			if (auto action_args = dynamic_cast<Scene_action_actor_event_args*>(args))
			{
				action_args->scene.selection_to_buffer();
			}

		};

	button_copy.add_event_handler(copy_selected, Button_event_args::CLICK);


	void(*paste_selected)(Button*, Event_args*) = [](Button* button, Event_args* args)
		{

			if (auto action_args = dynamic_cast<Scene_action_actor_event_args*>(args))
			{
				action_args->scene.buffer_to_scene();
			}

		};

	button_paste.add_event_handler(paste_selected, Button_event_args::CLICK);

	Scene_utils utils;

	class Memento_event_args : public Scene_action_actor_event_args
	{

	public:

		Scene_utils& utils;
		const char* filename;

		Memento_event_args(Event_type event_type, Scene& scene, Scene_utils& utils, const char* filename) : 
			Scene_action_actor_event_args(event_type, scene), utils(utils), filename(filename) {}

	};
	
	void(*save_scene)(Button*, Event_args*) = [](Button* button, Event_args* args)
		{

			if (auto action_args = dynamic_cast<Memento_event_args*>(args))
			{
				std::cout << "SAVED.\n";
			}

		};

	button_save.add_event_handler(save_scene, Button_event_args::CLICK);


	void(*load_scene)(Button*, Event_args*) = [](Button* button, Event_args* args)
		{

			if (auto action_args = dynamic_cast<Memento_event_args*>(args))
			{
				std::cout << "LOADED.\n";
			}

		};

	button_load.add_event_handler(load_scene, Button_event_args::CLICK);




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

						if (!button_aggregate.is_hovered())
							button_aggregate.try_hover(sf::Mouse::getPosition(main_window));
						else
							button_aggregate.try_unhover(sf::Mouse::getPosition(main_window));

						if (!button_copy.is_hovered())
							button_copy.try_hover(sf::Mouse::getPosition(main_window));
						else
							button_copy.try_unhover(sf::Mouse::getPosition(main_window));

						if (!button_paste.is_hovered())
							button_paste.try_hover(sf::Mouse::getPosition(main_window));
						else
							button_paste.try_unhover(sf::Mouse::getPosition(main_window));

						if (!button_save.is_hovered())
							button_save.try_hover(sf::Mouse::getPosition(main_window));
						else
							button_save.try_unhover(sf::Mouse::getPosition(main_window));

						if (!button_load.is_hovered())
							button_load.try_hover(sf::Mouse::getPosition(main_window));
						else
							button_load.try_unhover(sf::Mouse::getPosition(main_window));


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

						{
							Button_texture_change_event_args button_propeties_args0(Button_event_args::CLICK, texture_button_properties_pressed);
							Button_open_properties_window_event_args button_propeties_args1(Button_event_args::CLICK, properties_window, PROPERTIES_WINDOW_SIZE);
							args_arr[0] = &button_propeties_args0;
							args_arr[1] = &button_propeties_args1;
							if (button_properties.try_click(args_arr, PARAM_COUNT))
								break;
							else
								args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
						}


						{
							Button_texture_change_event_args button_delete_args(Button_event_args::CLICK, texture_button_delete_pressed);
							Scene_action_actor_event_args delete_action_args(Button_event_args::CLICK, main_scene);
							args_arr[0] = &button_delete_args;
							args_arr[1] = &delete_action_args;
							if (button_delete.try_click(args_arr, PARAM_COUNT))
								break;
							else
								args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
						}


						{
							Button_texture_change_event_args button_aggregate_args(Button_event_args::CLICK, texture_button_aggregate_pressed);
							Scene_action_actor_event_args aggregate_action_args(Button_event_args::CLICK, main_scene);
							args_arr[0] = &button_aggregate_args;
							args_arr[1] = &aggregate_action_args;
							if (button_aggregate.try_click(args_arr, PARAM_COUNT))
								break;
							else
								args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
						}


						{
							Button_texture_change_event_args button_copy_args(Button_event_args::CLICK, texture_button_copy_pressed);
							Scene_action_actor_event_args copy_action_args(Button_event_args::CLICK, main_scene);
							args_arr[0] = &button_copy_args;
							args_arr[1] = &copy_action_args;
							if (button_copy.try_click(args_arr, PARAM_COUNT))
								break;
							else
								args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
						}

						{
							Button_texture_change_event_args button_paste_args(Button_event_args::CLICK, texture_button_paste_pressed);
							Scene_action_actor_event_args paste_action_args(Button_event_args::CLICK, main_scene);
							args_arr[0] = &button_paste_args;
							args_arr[1] = &paste_action_args;
							if (button_paste.try_click(args_arr, PARAM_COUNT))
								break;
							else
								args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
						}

						{
							Button_texture_change_event_args button_save_args(Button_event_args::CLICK, texture_button_save_pressed);
							Scene_action_actor_event_args save_action_args(Button_event_args::CLICK, main_scene);
							args_arr[0] = &button_save_args;
							args_arr[1] = &save_action_args;
							if (button_save.try_click(args_arr, PARAM_COUNT))
								break;
							else
								args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
						}

						{
							Button_texture_change_event_args button_load_args(Button_event_args::CLICK, texture_button_load_pressed);
							Scene_action_actor_event_args load_action_args(Button_event_args::CLICK, main_scene);
							args_arr[0] = &button_load_args;
							args_arr[1] = &load_action_args;
							if (button_load.try_click(args_arr, PARAM_COUNT))
								break;
							else
								args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
						}



						{
							Button_texture_change_event_args button_line_args(Button_event_args::CLICK, texture_button_line_pressed);
							Shape* line = new Line(100, 5);
							line->set_origin(50, 2.5);
							line->move(400, 360);
							line->set_fill_color(sf::Color::Black);
							Scene::Actor line_actor(line);
							Scene_create_actor_event_args line_create_args(Button_event_args::CLICK, main_scene, std::move(line_actor));
							args_arr[0] = &button_line_args;
							args_arr[1] = &line_create_args;
							if (button_line.try_click(args_arr, PARAM_COUNT))
								break;
							else
								args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
						}


						{
							Button_texture_change_event_args button_rectangle_args(Button_event_args::CLICK, texture_button_rectangle_pressed);
							Shape* rectangle = new Rectangle(sf::Vector2f(200, 100));
							rectangle->set_origin(100, 50);
							rectangle->move(400, 360);
							rectangle->set_fill_color(sf::Color::Black);
							Scene::Actor rectangle_actor(rectangle);
							Scene_create_actor_event_args rectangle_create_args(Button_event_args::CLICK, main_scene, std::move(rectangle_actor));
							args_arr[0] = &button_rectangle_args;
							args_arr[1] = &rectangle_create_args;
							if (button_rectangle.try_click(args_arr, PARAM_COUNT))
								break;
							else
								args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
						}


						{
							Button_texture_change_event_args button_circle_args(Button_event_args::CLICK, texture_button_circle_pressed);
							Shape* circle = new Circle(50);
							circle->set_origin(50, 50);
							circle->move(400, 360);
							circle->set_fill_color(sf::Color::Black);
							Scene::Actor circle_actor(circle);
							Scene_create_actor_event_args circle_create_args(Button_event_args::CLICK, main_scene, std::move(circle_actor));
							args_arr[0] = &button_circle_args;
							args_arr[1] = &circle_create_args;
							if (button_circle.try_click(args_arr, PARAM_COUNT))
								break;
							else
								args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
						}


						{
							Button_texture_change_event_args button_triangle_args(Button_event_args::CLICK, texture_button_triangle_pressed);
							Shape* triangle = new Regular(50, 3);
							triangle->set_origin(50, 50);
							triangle->move(400, 360);
							triangle->set_fill_color(sf::Color::Black);
							Scene::Actor triangle_actor(triangle);
							Scene_create_actor_event_args triangle_create_args(Button_event_args::CLICK, main_scene, std::move(triangle_actor));
							args_arr[0] = &button_triangle_args;
							args_arr[1] = &triangle_create_args;
							if (button_triangle.try_click(args_arr, PARAM_COUNT))
								break;
							else
								args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
						}


						{
							Button_texture_change_event_args button_square_args(Button_event_args::CLICK, texture_button_square_pressed);
							Shape* square = new Regular(50, 4);
							square->set_origin(50, 50);
							square->move(400, 360);
							square->rotate(45);
							square->set_fill_color(sf::Color::Black);
							Scene::Actor square_actor(square);
							Scene_create_actor_event_args square_create_args(Button_event_args::CLICK, main_scene, std::move(square_actor));
							args_arr[0] = &button_square_args;
							args_arr[1] = &square_create_args;
							if (button_square.try_click(args_arr, PARAM_COUNT))
								break;
							else
								args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
						}


						{
							Button_texture_change_event_args button_pentagon_args(Button_event_args::CLICK, texture_button_pentagon_pressed);
							Shape* pentagon = new Regular(50, 5);
							pentagon->set_origin(50, 50);
							pentagon->move(400, 360);
							pentagon->set_fill_color(sf::Color::Black);
							Scene::Actor pentagon_actor(pentagon);
							Scene_create_actor_event_args pentagon_create_args(Button_event_args::CLICK, main_scene, std::move(pentagon_actor));
							args_arr[0] = &button_pentagon_args;
							args_arr[1] = &pentagon_create_args;
							if (button_pentagon.try_click(args_arr, PARAM_COUNT))
								break;
							else
								args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
						}


						{
							Button_texture_change_event_args button_hexagon_args(Button_event_args::CLICK, texture_button_hexagon_pressed);
							Shape* hexagon = new Regular(50, 6);
							hexagon->set_origin(50, 50);
							hexagon->move(400, 360);
							hexagon->set_fill_color(sf::Color::Black);
							Scene::Actor hexagon_actor(hexagon);
							Scene_create_actor_event_args hexagon_create_args(Button_event_args::CLICK, main_scene, std::move(hexagon_actor));
							args_arr[0] = &button_hexagon_args;
							args_arr[1] = &hexagon_create_args;
							if (button_hexagon.try_click(args_arr, PARAM_COUNT))
								break;
							else
								args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
						}



					}

					main_scene.try_select_actor(sf::Mouse::getPosition(main_window), sf::Keyboard::isKeyPressed(sf::Keyboard::LControl));

				}

				if (main_event.type == sf::Event::MouseButtonReleased)
				{

					const size_t PARAM_COUNT = 3;
					Event_args* args_arr[PARAM_COUNT]{};

					{
						Button_texture_change_event_args button_properties_args(Button_event_args::RELEASE, texture_button_properties);
						args_arr[0] = &button_properties_args;
						if (button_properties.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}


					{
						Button_texture_change_event_args button_delete_args(Button_event_args::RELEASE, texture_button_delete);
						args_arr[0] = &button_delete_args;
						if (button_delete.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}


					{
						Button_texture_change_event_args button_aggregate_args(Button_event_args::RELEASE, texture_button_aggregate);
						args_arr[0] = &button_aggregate_args;
						if (button_aggregate.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}


					{
						Button_texture_change_event_args button_copy_args(Button_event_args::RELEASE, texture_button_copy);
						args_arr[0] = &button_copy_args;
						if (button_copy.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}

					{
						Button_texture_change_event_args button_paste_args(Button_event_args::RELEASE, texture_button_paste);
						args_arr[0] = &button_paste_args;
						if (button_paste.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}

					{
						Button_texture_change_event_args button_save_args(Button_event_args::RELEASE, texture_button_save);
						args_arr[0] = &button_save_args;
						if (button_save.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}

					{
						Button_texture_change_event_args button_load_args(Button_event_args::RELEASE, texture_button_load);
						args_arr[0] = &button_load_args;
						if (button_load.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}



					{
						Button_texture_change_event_args button_line_args(Button_event_args::RELEASE, texture_button_line);
						args_arr[0] = &button_line_args;
						if (button_line.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}


					{
						Button_texture_change_event_args button_rectangle_args(Button_event_args::RELEASE, texture_button_rectangle);
						args_arr[0] = &button_rectangle_args;
						if (button_rectangle.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}


					{
						Button_texture_change_event_args button_circle_args(Button_event_args::RELEASE, texture_button_circle);
						args_arr[0] = &button_circle_args;
						if (button_circle.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}


					{
						Button_texture_change_event_args button_triangle_args(Button_event_args::RELEASE, texture_button_triangle);
						args_arr[0] = &button_triangle_args;
						if (button_triangle.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}


					{
						Button_texture_change_event_args button_square_args(Button_event_args::RELEASE, texture_button_square);
						args_arr[0] = &button_square_args;
						if (button_square.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}


					{
						Button_texture_change_event_args button_pentagon_args(Button_event_args::RELEASE, texture_button_pentagon);
						args_arr[0] = &button_pentagon_args;
						if (button_pentagon.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}


					{
						Button_texture_change_event_args button_hexagon_args(Button_event_args::RELEASE, texture_button_hexagon);
						args_arr[0] = &button_hexagon_args;
						if (button_hexagon.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}



				}

				if (main_event.type == sf::Event::KeyPressed)
				{

					if (main_event.key.code == sf::Keyboard::C && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
					{

						main_scene.selection_to_buffer();

					}

					if (main_event.key.code == sf::Keyboard::V && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
					{

						main_scene.buffer_to_scene();

					}

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
					sf::Vector3f input;
					std::string input_x = (std::string)textbox_X.get_text().getString();
					std::string input_y = (std::string)textbox_Y.get_text().getString();
					std::string input_z = (std::string)textbox_Z.get_text().getString();
					if (input_x != "" && input_x != "-")
					{
						input.x = std::stof(input_x);
					}
					if (input_y != "" && input_x != "-")
					{
						input.y = std::stof(input_y);
					}
					if (input_z != "" && input_x != "-")
					{
						input.z = std::stof(input_z);
					}

					{
						Button_texture_change_event_args button_move_args(Button_event_args::CLICK, texture_button_move_pressed);
						Move_actor_event_args action_move_args(Button_event_args::CLICK, main_scene, sf::Vector2f(input.x, input.y), main_scene.get_scene_size());
						args_arr[0] = &button_move_args;
						args_arr[1] = &action_move_args;
						if (button_move.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}


					{
						Button_texture_change_event_args button_rotate_args(Button_event_args::CLICK, texture_button_rotate_pressed);
						Rotate_actor_event_args action_rotate_args(Button_event_args::CLICK, main_scene, input.x);
						args_arr[0] = &button_rotate_args;
						args_arr[1] = &action_rotate_args;
						if (button_rotate.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}


					{
						Button_texture_change_event_args button_scale_args(Button_event_args::CLICK, texture_button_scale_pressed);
						Scale_actor_event_args action_scale_args(Button_event_args::CLICK, main_scene, sf::Vector2f(input.x, input.y));
						args_arr[0] = &button_scale_args;
						args_arr[1] = &action_scale_args;
						if (button_scale.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}


					{
						Button_texture_change_event_args button_color_args(Button_event_args::CLICK, texture_button_color_pressed);
						input.x = (int)abs(input.x) % 256;
						input.y = (int)abs(input.y) % 256;
						input.z = (int)abs(input.z) % 256;
						Color_actor_event_args action_color_args(Button_event_args::CLICK, main_scene, sf::Color(input.x, input.y, input.z));
						args_arr[0] = &button_color_args;
						args_arr[1] = &action_color_args;
						if (button_color.try_click(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}



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

					{
						Button_texture_change_event_args button_move_args(Button_event_args::RELEASE, texture_button_move);
						args_arr[0] = &button_move_args;
						if (button_move.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}


					{
						Button_texture_change_event_args button_rotate_args(Button_event_args::RELEASE, texture_button_rotate);
						args_arr[0] = &button_rotate_args;
						if (button_rotate.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}


					{
						Button_texture_change_event_args button_scale_args(Button_event_args::RELEASE, texture_button_scale);
						args_arr[0] = &button_scale_args;
						if (button_scale.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}


					{
						Button_texture_change_event_args button_color_args(Button_event_args::RELEASE, texture_button_color);
						args_arr[0] = &button_color_args;
						if (button_color.try_release(args_arr, PARAM_COUNT))
							break;
						else
							args_arr[0] = args_arr[1] = args_arr[2] = nullptr;
					}



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


			if (checkbox_enable_move_by_law.is_checked())
			{

				for (auto& i : main_scene.get_selection())
				{
					sf::FloatRect bounds = (*i)->get_global_bounds();
					float temp = top_panel.background.getGlobalBounds().height;
					if ((bounds.top + bounds.height) * GLOBAL_SCALE.y < main_scene.get_scene_size().y + top_panel.background.getGlobalBounds().height)
					{
						(*i)->move(0, 10);
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
			main_window.draw(button_aggregate);
			main_window.draw(button_properties);
			main_window.draw(button_copy);
			main_window.draw(button_paste);
			main_window.draw(button_save);
			main_window.draw(button_load);

			main_window.display();

		}

	}

	return 0;

}