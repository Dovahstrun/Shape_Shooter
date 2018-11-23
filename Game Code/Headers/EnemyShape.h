#pragma once

//Project Includes
#include "MovingObject.h"

class EnemyShape : public MovingObject
{

public:

	EnemyShape();

	void setCurrentEShape(int _newShape);
	int getCurrentEShape();

	//Overriding Methods
	void Update(sf::Time _frameTime);
	void Collide(GameObject& _collider);

private:

	int m_currentEShape; //1 = circle; 2 = square; 3 = triangle; 4 = star

};