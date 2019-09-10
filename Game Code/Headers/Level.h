#pragma once

//Library Includes
#include <SFML/Graphics.hpp>

//Project Includes
#include "Shape.h"


class Level
{

public:

	Level();

	virtual void Draw(sf::RenderTarget& _target);
	virtual void Update(sf::Time _frameTime);
	void loadLevel(int _levelToLoad);
	void ReloadLevel();
	int GetCurrentLevel();

	void loadBullet(sf::String _shapeToFire);
	void spawnBullet(sf::String _shapeToFire);
	bool deleteShape(Shape* _toDelete);

private:

	int m_currentLevel;
	GameObject* m_player;
	sf::Sprite m_background;
	std::vector<GameObject*> m_drawSpriteList;
	std::vector<GameObject*> m_updateList;
	std::vector<std::pair<GameObject*, GameObject*> > m_collisionList;
	float m_timer;
	float m_timeBetweenSpawns;
	bool m_pendingBullet;
	sf::String m_bulletToSpawn;
};
