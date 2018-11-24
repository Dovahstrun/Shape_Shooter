//Project Includes
#include "../Headers/NiceShape.h"
#include "../../Framework/Headers/AssetManager.h"

//Library Includes
#include <cstdlib>

NiceShape::NiceShape()
	: Shape()
{
	setCurrentShape((rand() % 4) + 1);
	m_currentShape = getCurrentShape();
	if (m_currentShape == 1)
	{
		m_sprite.setTexture(AssetManager::GetTexture("resources/graphics/circle.png"));
	}
	else if (m_currentShape == 2)
	{
		m_sprite.setTexture(AssetManager::GetTexture("resources/graphics/square.png"));
	}
	else if (m_currentShape == 3)
	{
		m_sprite.setTexture(AssetManager::GetTexture("resources/graphics/triangle.png"));
	}
	else if (m_currentShape == 4)
	{
		m_sprite.setTexture(AssetManager::GetTexture("resources/graphics/star.png"));
	}
	m_sprite.setScale(0.75f, 0.75f);
}