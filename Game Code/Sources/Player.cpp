//Project Includes
#include "../Headers/Player.h"
#include "../../Framework/Headers/AssetManager.h"
#include "../Headers/Shape.h"

Player::Player()
	: SpriteObject()
	, isSpaceDown(false)
{
	m_sprite.setTexture(AssetManager::GetTexture("resources/graphics/player.png"));
	m_sprite.setScale(0.75f, 0.75f);
}

void Player::Update(sf::Time _frameTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !isSpaceDown)
	{
		isSpaceDown = true;
		fire();
	}
	else
	{
		isSpaceDown = false;
	}
}


void Player::fire()
{
	
}