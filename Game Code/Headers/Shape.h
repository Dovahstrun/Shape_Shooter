#pragma once

//Project Includes
#include "MovingObject.h"

class Shape : public MovingObject
{

public:

	Shape();

	void setCurrentShape(int _newShape);
	int getCurrentShape();
	void setThisShape(sf::String _newShape);
	sf::String getThisShape(int _vectorPos);
	virtual int getShapeX();
	void setShapeX(int _newX);
	virtual int getShapeY();
	
protected:

	int m_currentShape; //1 = circle; 2 = square; 3 = triangle; 4 = star
	int m_ShapeX;
	int m_ShapeY;
	
	std::vector<sf::String> m_thisShape;
};