#include "Geometric.h"



const Geometric Geometric::line(Line(250, 5));
const Geometric Geometric::rectangle(Rectangle(sf::Vector2f(200, 100)));
const Geometric Geometric::circle(Circle(100));
const Geometric Geometric::triangle(Regular::triangle(200));
const Geometric Geometric::square(Regular::square(200));
const Geometric Geometric::pentagon(Regular::pentagon(200));
const Geometric Geometric::hexagon(Regular::hexagon(200));
