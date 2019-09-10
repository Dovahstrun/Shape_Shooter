//Project Includes
#include "../Headers/NiceShape.h"
#include "../../Framework/Headers/AssetManager.h"

//Library Includes
#include <cstdlib>

NiceShape::NiceShape()
	: Shape()
{
	m_sprite.setTexture(AssetManager::GetTexture("resources/graphics/" + m_currentShape + ".png"));
	m_sprite.setScale(0.75f, 0.75f);
}

void NiceShape::Update(sf::Time _frameTime)
{
	m_velocity.x = 400;
	MovingObject::Update(_frameTime);
}
