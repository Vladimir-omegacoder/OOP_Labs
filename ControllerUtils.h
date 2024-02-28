#pragma once
#include "Memento.h"
#include "Controller.h"


class ControllerUtils
{
private:

	ControllerMemeto memento;

public:

	ControllerUtils()
	{

	}


	void save_state(const Controller & controller)
	{
		memento.set_state(controller.get_instance()._figures(), controller.get_instance()._actve(), /*controller.buffer*/ controller.get_instance()._save_figures(), controller.get_instance()._befor_activ_color());
	}

	void load_state(Controller& controller)
	{
		for (auto& i : controller._figures())
		{
			delete i;
		}

		controller._figures().resize(memento.get_figures().size());

		for (int i = 0; i < memento.get_figures().size(); i++)
		{

			if (Circle* circle_ptr = dynamic_cast<Circle*>(memento.get_figures()[i]))
			{
				controller._figures()[i]= new Circle(*circle_ptr);
			}
			else if (Square* square_ptr = dynamic_cast<Square*>(memento.get_figures()[i]))
			{
				controller._figures()[i] = new Square(*square_ptr);
			}
			else if (Triangle* triangle_ptr = dynamic_cast<Triangle*>(memento.get_figures()[i]))
			{
				controller._figures()[i] = new Triangle(*triangle_ptr);
			}
			else if (Composite* composite_ptr = dynamic_cast<Composite*>(memento.get_figures()[i]))
			{
				controller._figures()[i] = new Composite(*composite_ptr);
			}
		}


		if (memento.get_actve() > -1)
		{
			controller._actve() = controller._figures()[memento.get_actve()];
		}
		else
		{
			controller._actve() = nullptr;
		}


		for (auto& i : controller._save_figures())
		{
			delete i.second;
		}
		controller._save_figures().clear();


		for (auto& it : memento.get_save_figures())
		{
			if (Circle* circle_ptr = dynamic_cast<Circle*>(it.second))
			{
				controller._save_figures().emplace(it.first, new Circle(*circle_ptr));
			}
			else if (Square* square_ptr = dynamic_cast<Square*>(it.second))
			{
				controller._save_figures().emplace(it.first, new Square(*square_ptr));
			}
			else if (Triangle* triangle_ptr = dynamic_cast<Triangle*>(it.second))
			{
				controller._save_figures().emplace(it.first, new Triangle(*triangle_ptr));
			}
			else if (Composite* composite_ptr = dynamic_cast<Composite*>(it.second))
			{
				controller._save_figures().emplace(it.first, new Composite(*composite_ptr));
			}
		}



		//memento.clear_save_figures();

		//for (auto& it : controller.save_figures)
		//{
		//	memento.add_save_figures(it.first, it.second);
		//}




		//if (Circle* circle_ptr = dynamic_cast<Circle*>(memento.get_buffer()))
		//{
		//	controller.buffer = new Circle(*circle_ptr);
		//}
		//else if (Square* square_ptr = dynamic_cast<Square*>(memento.get_buffer()))
		//{
		//	controller.buffer = new Square(*square_ptr);
		//}
		//else if (Triangle* triangle_ptr = dynamic_cast<Triangle*>(memento.get_buffer()))
		//{
		//	controller.buffer = new Triangle(*triangle_ptr);
		//}
		//else if (Composite* composite_ptr = dynamic_cast<Composite*>(memento.get_buffer()))
		//{
		//	controller.buffer = new Composite(*composite_ptr);
		//}



		controller._befor_activ_color() = memento.get_befor_activ_color();
	}












	//void save_in_file(std::fstream& file, const Controller& controller)
	//{
	//	this->save_state(controller);
	//	file << memento;
	//	//file.write((char*)&memento, sizeof(ControllerMemeto));
	//}

	//void load_in_file(std::fstream& file, Controller& controller)
	//{
	//	//file.read((char*)&memento, sizeof(ControllerMemeto));
	//	file >> memento;
	//	this->load_state(controller);
	//}

};

