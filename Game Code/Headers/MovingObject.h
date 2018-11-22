#pragma once

// Project Includes
#include "../../Framework/Headers/SpriteObject.h"

class MovingObject : public SpriteObject
{

public:

	MovingObject();

	// Overriding Methods
	void Update(sf::Time _frameTime);

protected:

	sf::Vector2f m_velocity; // pixels per second
	sf::Vector2f m_oldPosition; //The previous position that will allow it to jump back when it collides with something
};