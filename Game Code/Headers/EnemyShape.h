#pragma once

//Project Includes
#include "MovingObject.h"

class EnemyShape : public MovingObject
{

public:

	EnemyShape();

	//Overriding Methods
	void Collide(GameObject& _collider);

private:



};