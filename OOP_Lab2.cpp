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

	Rectangle rect(Vector2f(140, 100), Vector2f(50, 50));

	rect.rotate(45);

	std::cout << rect << '\n';

	std::cout << "Rect values: ";
	std::cin >> rect;

	std::cout << "Entered rect:\n";
	std::cout << rect << '\n';

}

