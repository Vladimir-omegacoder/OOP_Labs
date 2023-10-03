#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"



int main()
{

    Rectangle rect(Point{ 10, 30 }, 200, 100);

    rect.Draw();

    Triangle tr(Point{ 4, 2 }, Point{ 6, 8 }, Point{ 10, 3 });

    tr.Draw();

    Circle circle(Point{ 31, 82 }, 5.4);

    circle.Draw();

}

