//Project Includes
#include "../Headers/EnemyShape.h"
#include "../../Framework/Headers/AssetManager.h"
#include "../Headers/Player.h"
#include <cstdlib>

EnemyShape::EnemyShape()
	: Shape()
{
	m_sprite.setTexture(AssetManager::GetTexture("resources/graphics/enemy_" + m_currentShape + ".png"));
	m_sprite.setScale(0.75f, 0.75f);
}


void EnemyShape::Update(sf::Time _frameTime) 
{
	m_velocity.x = -400;
	MovingObject::Update(_frameTime);
}

void EnemyShape::Collide(GameObject & _collider)
{
	//Only do something if thing touched was player

	//We take the generic refernce to a game object passed in
	//We get the address for the game objet
	//We attempt to treat that address as if it is for a player
	//If successful, it IS a player and address s stored in castPlayer
	//If not successful, it is NOT a player and nullptr is stored in castPlayer
	Player* castPlayer = dynamic_cast<Player*>(&_collider);

	//Only do the thing if player is not null
	if (castPlayer != nullptr)
	{
		//Do something based on type of pickup
		//OnPickup(*castPlayer);

		//Disappear
		m_active = false;
	}


	//Do something based on type of pickup
	//Disappear
}