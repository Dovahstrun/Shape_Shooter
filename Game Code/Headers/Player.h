#pragma once

#include "../../Framework/Headers/SpriteObject.h"
#include "Level.h"

class Player : public SpriteObject
{

public:

	Player();

	//Overriding Methods
	void Update(sf::Time _frameTime);

private:

	void fire(sf::String _shape);

private:
	std::vector<sf::String> m_shapeKey;
	std::vector<bool> m_shapeKeyDown;
	Level* m_level;
};