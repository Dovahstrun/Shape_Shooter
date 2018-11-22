//Library Includes
#include <iostream>
#include <fstream>

//Project Includes

#include "../Headers/Level.h"
#include "../../Framework/Headers/AssetManager.h"
#include "../Headers/Player.h"

Level::Level()
	: m_currentLevel(0)
	, m_player(nullptr)
	, m_background()
	, m_drawSpriteList()
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

	m_player->SetPosition(200, 500);
	
	m_drawSpriteList.push_back(m_player);

	
}

void Level::ReloadLevel()
{
	loadLevel(m_currentLevel);
}

int Level::GetCurrentLevel()
{
	return m_currentLevel;
}