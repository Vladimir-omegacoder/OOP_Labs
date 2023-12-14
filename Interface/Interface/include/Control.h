#pragma once
#include <list>
#include "SFML/Graphics.hpp"



#ifdef CONTROLS_FONT
#define _CONTROL_FONT = CONTROLS_FONT
#else
#define _CONTROL_FONT = "calibri.tff"
#endif





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