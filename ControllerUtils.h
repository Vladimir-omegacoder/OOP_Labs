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
		memento.set_state(controller.figures, controller.actve, controller.buffer, controller.befor_activ_color);
	}

	void load_state(Controller& controller)
	{
		for (auto& i : controller.figures)
		{
			delete i;
		}

		controller.figures.resize(memento.get_figures().size());

		for (int i = 0; i < memento.get_figures().size(); i++)
		{

			if (Circle* circle_ptr = dynamic_cast<Circle*>(memento.get_figures()[i]))
			{
				controller.figures[i]= new Circle(*circle_ptr);
			}
			else if (Square* square_ptr = dynamic_cast<Square*>(memento.get_figures()[i]))
			{
				controller.figures[i] = new Square(*square_ptr);
			}
			else if (Triangle* triangle_ptr = dynamic_cast<Triangle*>(memento.get_figures()[i]))
			{
				controller.figures[i] = new Triangle(*triangle_ptr);
			}
			else if (Composite* composite_ptr = dynamic_cast<Composite*>(memento.get_figures()[i]))
			{
				controller.figures[i] = new Composite(*composite_ptr);
			}
		}



		controller.actve = controller.figures[memento.get_actve()];



		if (Circle* circle_ptr = dynamic_cast<Circle*>(memento.get_buffer()))
		{
			controller.buffer = new Circle(*circle_ptr);
		}
		else if (Square* square_ptr = dynamic_cast<Square*>(memento.get_buffer()))
		{
			controller.buffer = new Square(*square_ptr);
		}
		else if (Triangle* triangle_ptr = dynamic_cast<Triangle*>(memento.get_buffer()))
		{
			controller.buffer = new Triangle(*triangle_ptr);
		}
		else if (Composite* composite_ptr = dynamic_cast<Composite*>(memento.get_buffer()))
		{
			controller.buffer = new Composite(*composite_ptr);
		}



		controller.befor_activ_color = memento.get_befor_activ_color();
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

