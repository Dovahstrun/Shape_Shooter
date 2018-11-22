#pragma once

//Project Includes
#include "MovingObject.h"
#include <SFML/Graphics.hpp>

class Shape : public MovingObject
{

public:

	Shape();
	
private:

	int currentShape;

};