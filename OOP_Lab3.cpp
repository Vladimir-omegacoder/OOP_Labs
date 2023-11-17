#include <iostream>
#include "Convex.h"



int main()
{

    Convex convex(5);
    convex[0] = Vector2f(10, 10);
    convex[1] = Vector2f(30, 20);
    convex[2] = Vector2f(45, 20);
    convex[3] = Vector2f(25, 15);
    convex[4] = Vector2f(15, 15);

    Convex temp(3);
    temp[0] = Vector2f(40, 20);
    temp[1] = Vector2f(60, 40);
    temp[2] = Vector2f(70, 30);

    std::cout << convex << '\n';

    convex(1, 2) = temp;

    std::cout << convex << '\n';

}


