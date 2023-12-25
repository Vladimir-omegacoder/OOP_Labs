#pragma once
#include <list>
#include "SFML/Graphics.hpp"






class Event_args
{

public:

	Event_args() = default;

	virtual ~Event_args() = default;

};




class Control : public sf::Drawable
{

public:

	Control() = default;

	virtual ~Control() = default;

};