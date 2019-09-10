//Project Includes
#include "../Headers/Shape.h"
#include "../../Framework/Headers/AssetManager.h"
#include "../Headers/Level.h"

Shape::Shape()
	: MovingObject()
	, m_currentShape()
	, m_ShapeX()
	, m_ShapeY()
	, m_thisShape()
{
	m_thisShape.push_back("Circle");
	m_thisShape.push_back("Square");
	m_thisShape.push_back("Triangle");
	m_thisShape.push_back("Star");
}


void Shape::setThisShape(sf::String _newShape)
{
	m_currentShape = _newShape;
}

sf::String Shape::getThisShape()
{
	return m_currentShape;
}

int Shape::getShapeX()
{
	return m_ShapeX;
}

void Shape::setShapeX(int _newX)
{
	m_ShapeX = _newX;
}

int Shape::getShapeY()
{
	return m_ShapeY;
}