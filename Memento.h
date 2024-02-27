#pragma once
#include "Figure.h"
#include <vector>



class Memento
{
public:

	virtual ~Memento() {};

	virtual const std::vector<Figure*>& get_figures() = 0;
	virtual int get_actve() = 0;
	virtual Figure* get_buffer() = 0;
	virtual sf::Color get_befor_activ_color() = 0;



	virtual void set_state(const std::vector<Figure*>& fig, const Figure* act, const Figure* buf, const sf::Color& col) = 0;
};




class ControllerMemeto: public Memento
{
private:

	std::vector<Figure*> figures;

	int actve = -1;

	Figure* buffer = nullptr;

	sf::Color befor_activ_color;

public:

	ControllerMemeto()
	{

	}

	ControllerMemeto(std::vector<Figure*> fig, Figure* act, Figure* buf, sf::Color col):figures(fig.size()), befor_activ_color(col)
	{

		if (Circle* circle_ptr = dynamic_cast<Circle*>(buf))
		{
			buffer = new Circle(*circle_ptr);
		}
		else if (Square* square_ptr = dynamic_cast<Square*>(buf))
		{
			buffer = new Square(*square_ptr);
		}
		else if (Triangle* triangle_ptr = dynamic_cast<Triangle*>(buf))
		{
			buffer = new Triangle(*triangle_ptr);
		}
		else if (Composite* composite_ptr = dynamic_cast<Composite*>(buf))
		{
			buffer = new Composite(*composite_ptr);
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

	Figure* get_buffer()
	{
		return buffer;
	}

	sf::Color get_befor_activ_color()
	{
		return befor_activ_color;
	}




	void set_state(const std::vector<Figure*>& fig, const Figure* act, const Figure* buf, const sf::Color& col)
	{
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


		if (const Circle* circle_ptr = dynamic_cast<const Circle*>(buf))
		{
			buffer = new Circle(*circle_ptr);
		}
		else if (const Square* square_ptr = dynamic_cast<const Square*>(buf))
		{
			buffer = new Square(*square_ptr);
		}
		else if (const Triangle* triangle_ptr = dynamic_cast<const Triangle*>(buf))
		{
			buffer = new Triangle(*triangle_ptr);
		}
		else if (const Composite* composite_ptr = dynamic_cast<const Composite*>(buf))
		{
			buffer = new Composite(*composite_ptr);
		}

		befor_activ_color = col;
	}



	//friend std::ostream& operator << (std::ostream& out, const ControllerMemeto mem);

	//friend std::istream& operator >> (std::istream& in, ControllerMemeto mem);


	~ControllerMemeto()
	{
		delete buffer;

		for (Figure*& f : figures)
		{
			delete f;
		}
	}

};



//std::ostream& operator << (std::ostream& out, const ControllerMemeto mem)
//{
//	int size = mem.figures.size();
//
//	out.write((char*)&size, sizeof(int));
//	//out << mem.figures.size();
//
//	for (const auto& ptr : mem.figures)
//	{
//		out.write((char*)&*ptr, sizeof(Figure));
//	}
//
//	out.write((char*)&mem.actve, sizeof(int));
//	//out << mem.actve;
//	out.write((char*)&mem.befor_activ_color, sizeof(sf::Color));
//
//	if (mem.buffer)
//	{
//		out.write((char*)&*mem.buffer, sizeof(Figure));
//	}
//
//	return out;
//}
//
//
//
//std::istream& operator >> (std::istream& in, ControllerMemeto mem)
//{
//	for (auto& i : mem.figures)
//	{
//		delete i;
//	}
//
//	int size;
//
//	in.read((char*)&size, sizeof(int));
//	//in >> size;
//
//	mem.figures.resize(size);
//
//	for (int i = 0; i < size; i++)
//	{	
//		in.read((char*)&mem.figures[i], sizeof(Figure));
//	}
//
//	in.read((char*)&mem.actve, sizeof(int));
//	//in >> mem.actve;
//	
//	in.read((char*)&mem.befor_activ_color, sizeof(sf::Color));
//
//	in.read((char*)&mem.buffer, sizeof(Figure));
//
//	return in;
//}