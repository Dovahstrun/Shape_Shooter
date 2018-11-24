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
}


void Level::loadLevel(int _levelToLoad)
{

	///Cleanup the old level

	//TODO: Delete any data already in the level
	

	//Clear out the lists


	///Setup everything

	//Set current level
	m_currentLevel = _levelToLoad;


	//Set up all the game objects
	Player* player = new Player();
	m_player = player;
	player->SetPosition(200, 550);
	m_drawSpriteList.push_back(player);
	m_updateList.push_back(player);

	NiceShape* shape = new NiceShape();
	shape->SetPosition(700, 550);
	m_drawSpriteList.push_back(shape);
	m_updateList.push_back(shape);

	EnemyShape* eShape = new EnemyShape();
	eShape->SetPosition(1400, 550);
	m_drawSpriteList.push_back(eShape);
	m_updateList.push_back(eShape);

	
}

void Level::ReloadLevel()
{
	loadLevel(m_currentLevel);
}

int Level::GetCurrentLevel()
{
	return m_currentLevel;
}