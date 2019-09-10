//Library Includes
#include <iostream>
#include <fstream>

//Project Includes
#include "../Headers/Level.h"
#include "../../Framework/Headers/AssetManager.h"
#include "../Headers/Player.h"
#include "../Headers/NiceShape.h"
#include "../Headers/EnemyShape.h"

Level::Level()
	: m_currentLevel(0)
	, m_player(nullptr)
	, m_background()
	, m_drawSpriteList()
	, m_updateList()
	, m_collisionList()
	, m_timer(0.0f)
	, m_timeBetweenSpawns(3.0f)
	, m_pendingBullet(false)
	, m_bulletToSpawn()
{
	loadLevel(1);
}

void Level::Draw(sf::RenderTarget & _target)
{
	///Camera

	//Create and update camera
	sf::View camera = _target.getDefaultView();
	
	//TODO: Adjust camera as needed


	//Draw game world to the camera
	_target.setView(camera);


	///Background


	///Game Objects
	for (int i = 0; i < m_drawSpriteList.size(); ++i)
	{
		if (m_drawSpriteList[i]->isActive())
		{
			m_drawSpriteList[i]->Draw(_target);
		}
	}

	///UI
	// Draw UI to the window
	_target.setView(_target.getDefaultView());


	//TODO: Draw UI objects


}


void Level::Update(sf::Time _frameTime)
{
	//Update
	for (int i = 0; i < m_updateList.size(); ++i)
	{
		if (m_updateList[i]->isActive())
		{
			m_updateList[i]->Update(_frameTime);
		}
	}


	// -----------------------------------------------
	// Collision Section
	// -----------------------------------------------

	for (int i = 0; i < m_collisionList.size(); ++i)
	{
		GameObject* handler = m_collisionList[i].first;
		GameObject* collider = m_collisionList[i].second;


		if (handler->isActive() && collider->isActive())
		{
			if (handler->GetBounds().intersects(collider->GetBounds()))
			{
				handler->Collide(*collider);
			}
		}
	}

	//Spawning enemy shapes
	m_timer += _frameTime.asSeconds();
	if (m_timer > m_timeBetweenSpawns)
	{
		EnemyShape* eShape = new EnemyShape();
		eShape->SetPosition(1400, 550);
		m_drawSpriteList.push_back(eShape);
		m_updateList.push_back(eShape);
		m_timer = 0;
	}

	if (m_pendingBullet)
	{
		spawnBullet(m_bulletToSpawn);
	}
}


void Level::loadLevel(int _levelToLoad)
{

	///Cleanup the old level

	//Delete any data already in the level
	for (int i = 0; i < m_updateList.size(); ++i)
	{
		delete m_updateList[i];
	}

	//Clear out the lists
	m_updateList.clear();
	m_drawSpriteList.clear();
	m_collisionList.clear();

	///Setup everything

	//Set current level
	m_currentLevel = _levelToLoad;


	//Set up all the game objects
	
	EnemyShape* eShape = new EnemyShape();
	eShape->SetPosition(1400, 550);
	m_drawSpriteList.push_back(eShape);
	m_updateList.push_back(eShape);

	Player* player = new Player();
	m_player = player;
	player->SetPosition(200, 550);
	m_drawSpriteList.push_back(player);
	m_collisionList.push_back(std::make_pair(player, eShape));
	m_updateList.push_back(player);
}

void Level::ReloadLevel()
{
	loadLevel(m_currentLevel);
}

int Level::GetCurrentLevel()
{
	return m_currentLevel;
}

void Level::loadBullet(sf::String _shapeToFire)
{
	m_bulletToSpawn = _shapeToFire;
}

void Level::spawnBullet(sf::String _shapeToFire)
{
	NiceShape* shape = new NiceShape();
	shape->setThisShape(_shapeToFire);
	shape->SetPosition(700, 550);
	m_drawSpriteList.push_back(shape);
	m_updateList.push_back(shape);
}

bool Level::deleteShape(Shape * _toDelete)
{
	return false;
}
