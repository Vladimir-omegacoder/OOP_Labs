#include <iostream>
#include "Vector.h"
#include "Transform.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Convex.h"






void print_matrix(const Transform& tr)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << tr[i * 3 + j] << ' ';
		}

		std::cout << '\n';
	}
}


int main()
{

	Circle circle(50, Vector2f(40, 100));

	circle.rotate(45);

	std::cout << circle << '\n';

	std::cout << "Enter circle values: ";
	std::cin >> circle;

	std::cout << "Entered circle:\n";
	std::cout << circle << '\n';

}

