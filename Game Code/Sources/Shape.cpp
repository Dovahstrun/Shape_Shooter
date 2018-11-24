#include "../Headers/Shape.h"
#include "../../Framework/Headers/AssetManager.h"

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

void Shape::setCurrentShape(int _newShape)
{
	m_currentShape = _newShape;
}

int Shape::getCurrentShape()
{
	return m_currentShape;
}

void Shape::setThisShape(sf::String _newShape)
{
	
}

sf::String Shape::getThisShape(int _vectorPos)
{
	return m_thisShape[_vectorPos];
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