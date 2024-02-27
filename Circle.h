#pragma once
#include "Figure.h"

class Circle: public Figure
{
private:

	sf::CircleShape circle;

public:

	Circle(const Circle& cir);

	Circle(float radius);

	Circle(float radius, sf::Color color);

	sf::FloatRect get_global_bounds() const;

	void set_position(float x, float y);

	void set_ñolor(sf::Color color);

	sf::Color get_now_color();



	void move(float x, float y);

	void scaling(sf::Vector2f a);

	void draw(sf::RenderWindow& window) const;



	//void set_memento(Memento& memento) const;

	//void get_memento(const Memento& memento);


	//void Foo()
	//{

		//Figure* ptr = nullptr;

		//if (Circle* circle_ptr = dynamic_cast<Circle*>(ptr))
		//{
		//	circle_ptr->circle;
		//}
		//else if (Square* circle_ptr = dynamic_cast<Square*>(ptr))
		//{

		//}
		//else if (Composite* circle_ptr = dynamic_cast<Composite*>(ptr))
		//{
		//	
		//}

	//}
};

