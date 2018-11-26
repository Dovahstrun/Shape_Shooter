#pragma once

#include "../../Framework/Headers/SpriteObject.h"

class Player : public SpriteObject
{

public:

	Player();

	//Overriding Methods
	void Update(sf::Time _frameTime);

	void fire();

private:
	std::vector<sf::String> m_shapeKey;
	std::vector<bool> m_shapeKeyDown;
};