#include "../Headers/Shape.h"
#include "../../Framework/Headers/AssetManager.h"

Shape::Shape()
	: MovingObject()
	, m_currentShape()
	, m_ShapeX()
	, m_ShapeY()
{
	
}

void Shape::setCurrentShape(int _newShape)
{
	m_currentShape = _newShape;
}

int Shape::getCurrentShape()
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