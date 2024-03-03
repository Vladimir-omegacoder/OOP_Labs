#pragma once
#include "Figure.h"
#include "Circle.h"
#include <vector>
#include <fstream>



class Memento
{
public:

	virtual ~Memento() {};

	virtual const std::vector<Figure*>& get_figures() = 0;
	virtual const std::map<std::string, Figure*>& get_save_figures() = 0;
	virtual int get_actve() = 0;
	virtual sf::Color get_befor_activ_color() = 0;


	virtual void set_state(const std::vector<Figure*>& fig, const Figure* act, const std::map<std::string, Figure*>& s_fig, const sf::Color& col) = 0;
};




class ControllerMemeto: public Memento
{
private:

	std::vector<Figure*> figures;

	int actve = -1;

	std::map<std::string, Figure*> save_figures;

	sf::Color befor_activ_color;

public:

	ControllerMemeto()
	{

	}

	ControllerMemeto(std::vector<Figure*> fig, Figure* act, std::map<std::string, Figure*>& s_fig, sf::Color col) :figures(fig.size()), befor_activ_color(col)
	{

		//if (Circle* circle_ptr = dynamic_cast<Circle*>(buf))
		//{
		//	buffer = new Circle(*circle_ptr);
		//}
		//else if (Square* square_ptr = dynamic_cast<Square*>(buf))
		//{
		//	buffer = new Square(*square_ptr);
		//}
		//else if (Triangle* triangle_ptr = dynamic_cast<Triangle*>(buf))
		//{
		//	buffer = new Triangle(*triangle_ptr);
		//}
		//else if (Composite* composite_ptr = dynamic_cast<Composite*>(buf))
		//{
		//	buffer = new Composite(*composite_ptr);
		//}


		for (auto& i : save_figures)
		{
			delete i.second;
		}
		save_figures.clear();

		//this->clear_save_figures();


		for (auto& it : s_fig)
		{
			if (Circle* circle_ptr = dynamic_cast<Circle*>(it.second))
			{
				save_figures.emplace(it.first, new Circle(*circle_ptr));
			}
			else if (Square* square_ptr = dynamic_cast<Square*>(it.second))
			{
				save_figures.emplace(it.first, new Square(*square_ptr));
			}
			else if (Triangle* triangle_ptr = dynamic_cast<Triangle*>(it.second))
			{
				save_figures.emplace(it.first, new Triangle(*triangle_ptr));
			}
			else if (Composite* composite_ptr = dynamic_cast<Composite*>(it.second))
			{
				save_figures.emplace(it.first, new Composite(*composite_ptr));
			}
		}



		for (int i = 0; i < fig.size(); i++)
		{
			if (fig[i] == act)
			{
				actve = i;
			}


			if (Circle* circle_ptr = dynamic_cast<Circle*>(fig[i]))
			{
				figures.push_back(new Circle(*circle_ptr));
			}
			else if (Square* square_ptr = dynamic_cast<Square*>(fig[i]))
			{
				figures.push_back(new Square(*square_ptr));
			}
			else if (Triangle* triangle_ptr = dynamic_cast<Triangle*>(fig[i]))
			{
				figures.push_back(new Triangle(*triangle_ptr));
			}
			else if (Composite* composite_ptr = dynamic_cast<Composite*>(fig[i]))
			{
				figures.push_back(new Composite(*composite_ptr));
			}
		}
	}




	const std::vector<Figure*>& get_figures() override
	{
		return figures;
	}

	int get_actve()
	{
		return actve;
	}

	const std::map<std::string, Figure*>& get_save_figures()
	{
		return save_figures;
	}

	sf::Color get_befor_activ_color()
	{
		return befor_activ_color;
	}




	void set_state(const std::vector<Figure*>& fig, const Figure* act, const std::map<std::string, Figure*>& s_fig, const sf::Color& col)
	{
		for (auto& i : figures)
		{
			delete i;
		}

		figures.resize(fig.size());


		for (int i = 0; i < fig.size(); i++)
		{
			if (fig[i] == act)
			{
				actve = i;
			}

			if (Circle* circle_ptr = dynamic_cast<Circle*>(fig[i]))
			{
				figures[i] = new Circle(*circle_ptr);
			}
			else if (Square* square_ptr = dynamic_cast<Square*>(fig[i]))
			{
				figures[i] = new Square(*square_ptr);
			}
			else if (Triangle* triangle_ptr = dynamic_cast<Triangle*>(fig[i]))
			{
				figures[i] = new Triangle(*triangle_ptr);
			}
			else if (Composite* composite_ptr = dynamic_cast<Composite*>(fig[i]))
			{
				figures[i] = new Composite(*composite_ptr);
			}
		}


		for (auto& i : save_figures)
		{
			delete i.second;
		}
		save_figures.clear();


		for (auto& it : s_fig)
		{
			if (Circle* circle_ptr = dynamic_cast<Circle*>(it.second))
			{
				save_figures.emplace(it.first, new Circle(*circle_ptr));
			}
			else if (Square* square_ptr = dynamic_cast<Square*>(it.second))
			{
				save_figures.emplace(it.first, new Square(*square_ptr));
			}
			else if (Triangle* triangle_ptr = dynamic_cast<Triangle*>(it.second))
			{
				save_figures.emplace(it.first, new Triangle(*triangle_ptr));
			}
			else if (Composite* composite_ptr = dynamic_cast<Composite*>(it.second))
			{
				save_figures.emplace(it.first, new Composite(*composite_ptr));
			}
		}

		befor_activ_color = col;
	}



	bool write_to_file(std::string& file_name)
	{
		std::ofstream file(file_name, std::ios::binary);

		if (!file.is_open())
		{
			std::cout << "Error\n\n";
			return false;
		}

		int size_figures = figures.size();
		char shape_type;


		file.write((char*)&(size_figures), sizeof(int));

		for (const auto& f : figures)
		{
			if (Circle* circle_ptr = dynamic_cast<Circle*>(f))
			{
				shape_type = 'C';
			}
			else if (Square* square_ptr = dynamic_cast<Square*>(f))
			{
				shape_type = 'S';
			}
			else if (Triangle* triangle_ptr = dynamic_cast<Triangle*>(f))
			{
				shape_type = 'T';
			}
			else if (Composite* composite_ptr = dynamic_cast<Composite*>(f))
			{
				shape_type = 'K';
			}


			file.write((char*)&shape_type, sizeof(char));

			f->write_to_file(file);
		}

		file.write((char*)&(actve), sizeof(int));



		int size_save_figures = save_figures.size();

		file.write((char*)&(size_save_figures), sizeof(int));


		for (const auto& f : save_figures)
		{
			file.write((char*)&f.first, sizeof(std::string));

			if (Circle* circle_ptr = dynamic_cast<Circle*>(f.second))
			{
				shape_type = 'C';
			}
			else if (Square* square_ptr = dynamic_cast<Square*>(f.second))
			{
				shape_type = 'S';
			}
			else if (Triangle* triangle_ptr = dynamic_cast<Triangle*>(f.second))
			{
				shape_type = 'T';
			}
			else if (Composite* composite_ptr = dynamic_cast<Composite*>(f.second))
			{
				shape_type = 'K';
			}


			file.write((char*)&shape_type, sizeof(char));

			f.second->write_to_file(file);
		}

		file.write((char*)&befor_activ_color, sizeof(sf::Color));

		file.close();
		return true;
	}



	bool read_from_file(std::string& file_name)
	{
		std::ifstream file(file_name, std::ios::binary);

		if (!file.is_open())
		{
			std::cout << "Error\n\n";
			return false;
		}

		Figure* fig = new Circle(3);
		int size_figures;
		char shape_type;


		file.read((char*)&(size_figures), sizeof(int));

		for (auto& f : figures)
		{
			delete f;
		}

		figures.resize(size_figures);

		for (int i = 0; i < size_figures; i++)
		{
			file.read((char*)&shape_type, sizeof(char));

			if (shape_type == 'C')
			{
				figures[i] = new Circle(3);
				figures[i]->read_from_file(file);
			}
			else if (shape_type == 'T')
			{
				figures[i] = new Triangle(3);
				figures[i]->read_from_file(file);
			}
			else if (shape_type == 'S')
			{
				figures[i] = new Square(3);
				figures[i]->read_from_file(file);
			}
			else if (shape_type == 'K')
			{
				figures[i] = new Composite();
				figures[i]->read_from_file(file);
			}
		}

		file.read((char*)&(actve), sizeof(int));

		int size_save_figures;
		file.read((char*)&(size_save_figures), sizeof(int));

		for (auto& f : save_figures)
		{
			delete f.second;
		}

		save_figures.clear();

		for (int i = 0; i < size_save_figures; i++)
		{
			std::string name;

			file.read((char*)&name, sizeof(std::string));
			file.read((char*)&shape_type, sizeof(char));


			if (shape_type == 'C')
			{
				save_figures.emplace(name, new Circle(3));
				save_figures[name]->read_from_file(file);
			}
			else if (shape_type == 'T')
			{
				save_figures.emplace(name, new Triangle(3));
				save_figures[name]->read_from_file(file);
			}
			else if (shape_type == 'S')
			{
				save_figures.emplace(name, new Square(3));
				save_figures[name]->read_from_file(file);
			}
			else if (shape_type == 'K')
			{
				save_figures.emplace(name, new Composite());
				save_figures[name]->read_from_file(file);
			}
		}


		file.read((char*)&befor_activ_color, sizeof(sf::Color));

		file.close();
		return true;
	}


	~ControllerMemeto()
	{
		//delete buffer;

		for (auto& i : save_figures)
		{
			delete i.second;
		}

		for (Figure*& f : figures)
		{
			delete f;
		}
	}

};