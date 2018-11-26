//Project Includes
#include "../Headers/Player.h"
#include "../../Framework/Headers/AssetManager.h"
#include "../Headers/NiceShape.h"

Player::Player()
	: SpriteObject()
	, m_shapeKey()
	, m_shapeKeyDown()
{
	m_sprite.setTexture(AssetManager::GetTexture("resources/graphics/player.png"));
	m_sprite.setScale(0.75f, 0.75f);
	m_shapeKey.push_back("Circle");
	m_shapeKeyDown.push_back(false);
	m_shapeKey.push_back("Triangle");
	m_shapeKeyDown.push_back(false);
	m_shapeKey.push_back("Square");
	m_shapeKeyDown.push_back(false);
	m_shapeKey.push_back("Star");
	m_shapeKeyDown.push_back(false);
}

void Player::Update(sf::Time _frameTime)
{
	for (int i = 0; i < m_shapeKey.size(); ++i)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !m_shapeKeyDown[i] && m_shapeKey[i] == "Circle")
		{
			m_shapeKeyDown[i] = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
			fire();
		}
		else
		{
			m_shapeKeyDown[i] = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !m_shapeKeyDown[i] && m_shapeKey[i] == "Triangle")
		{
			m_shapeKeyDown[i] = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
			fire();
		}
		else
		{
			m_shapeKeyDown[i] = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !m_shapeKeyDown[i] && m_shapeKey[i] == "Square")
		{
			m_shapeKeyDown[i] = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
			fire();
		}
		else
		{
			m_shapeKeyDown[i] = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && !m_shapeKeyDown[i] && m_shapeKey[i] == "Star")
		{
			m_shapeKeyDown[i] = sf::Keyboard::isKeyPressed(sf::Keyboard::F);
			fire();
		}
		else
		{
			m_shapeKeyDown[i] = sf::Keyboard::isKeyPressed(sf::Keyboard::F);
		}
	}
	
}


void Player::fire()
{
	
}