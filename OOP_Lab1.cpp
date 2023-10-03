#include <iostream>
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"



int main()
{

    Rectangle rectangle     (Point{ 10, 30 }, 200, 100);
    Triangle  triangle      (Point{ 4, 2 }, Point{ 6, 8 }, Point{ 10, 3 });
    Circle    circle        (Point{ 31, 82 }, 5.4f);

    size_t shapes_size = 3;

    Shape** shapes = new Shape*[shapes_size]{ &rectangle, &triangle, &circle };



    for (size_t i = 0; i < shapes_size; ++i)
    {
        shapes[i]->Draw();
    }

    return 0;

}

