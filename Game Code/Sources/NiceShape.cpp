//Project Includes
#include "../Headers/NiceShape.h"
#include "../../Framework/Headers/AssetManager.h"

//Library Includes
#include <cstdlib>

NiceShape::NiceShape()
	: Shape()
{
	m_sprite.setTexture(AssetManager::GetTexture("resources/graphics/" + getThisShape(rand() % 4) + ".png"));
	m_sprite.setScale(0.75f, 0.75f);
}