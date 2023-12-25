#pragma once
#include <list>
#include "SFML/Graphics.hpp"






class EventArgs
{

public:

	EventArgs() = default;

	virtual ~EventArgs() = default;

};




class Control : public sf::Drawable
{

public:

	Control() = default;

	virtual ~Control() = default;

};