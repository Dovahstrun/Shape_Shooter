//Project Includes
#include "../Headers/Player.h"
#include "../../Framework/Headers/AssetManager.h"

Player::Player()
	: SpriteObject()
{
	m_sprite.setTexture(AssetManager::GetTexture("resources/graphics/player.png"));
	m_sprite.setScale(0.75f, 0.75f);
}

void Player::Update(sf::Time _frameTime)
{
}

void Player::fire()
{

}