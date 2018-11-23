#pragma once

//Project Includes
#include "MovingObject.h"

class Shape : public MovingObject
{

public:

	Shape();

	void setCurrentShape(int _newShape);
	int getCurrentShape();
	
private:

	int m_currentShape; //1 = circle; 2 = square; 3 = triangle; 4 = star
	

};