#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"



int main()
{

    Rectangle rect(Point{ 10, 30 }, 200, 100);

    rect.Draw();
    std::cout << '\n';

    Triangle tr(Point{ 4, 2 }, Point{ 6, 8 }, Point{ 10, 3 });

    std::cout << tr.Area() << '\n';

}

