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
	bool isSpaceDown;
};