#pragma once
#include "Regular.h"



class Triangle : public Regular
{

public:

	Triangle(float side_length) : Regular(side_length, 3) {}

};