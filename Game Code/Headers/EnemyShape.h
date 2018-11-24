#pragma once

//Project Includes
#include "Shape.h"

class EnemyShape : public Shape
{

public:

	EnemyShape();

	//Overriding Methods
	void Update(sf::Time _frameTime);
	void Collide(GameObject& _collider);

private:

};