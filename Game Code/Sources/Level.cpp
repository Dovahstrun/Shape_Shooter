//Library Includes
#include <iostream>
#include <fstream>

//Project Includes

#include "../Headers/Level.h"
#include "../../Framework/Headers/AssetManager.h"

Level::Level()
	: m_cellSize(64)
	, m_currentLevel(0)
	, m_background()
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
	for (int y = 0; y < m_background.size(); ++y)
	{
		for (int x = 0; x < m_background[y].size(); ++x)
		{
			_target.draw(m_background[y][x]);
		}
	}


	///Game Objects
	

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
	m_background.clear();


	///Setup everything

	//Set current level
	m_currentLevel = _levelToLoad;

	//Set up all the game objects
	//Open our file for reading
	std::ifstream inFile;
	std::string fileName = "levels/Level" + std::to_string(m_currentLevel) + ".txt";
	inFile.open(fileName);

	//Make sure the file was opened
	if (!inFile)
	{
		std::cerr << "Unable to open file " + fileName;
		exit(1); //Call system to stop program with error	
	}

	//Set the starting x and y coords used to position level objects
	int x = 0;
	int y = 0;

	//Create the first row in our grid
	m_background.push_back(std::vector<sf::Sprite>());

	//Reading each character one by one from the file...
	char ch;
	//Each time, try to read the next character, execute body of loop
	while (inFile >> std::noskipws >> ch)//the noskipws means we will include the white space (spaces)
	{
		//Perform actions based on what character was read in
		if (ch == ' ')
		{
			++x;
		}
		else if (ch == '\n')
		{
			++y;
			x = 0;

			//Create a new row in our grid
			m_background.push_back(std::vector<sf::Sprite>());
		}
		else
		{
			//Create background sprite (this is going to be some object/empty space, so we need a background)
			m_background[y].push_back(sf::Sprite(AssetManager::GetTexture("graphics/ground.png")));
			m_background[y][x].setPosition(x*m_cellSize, y*m_cellSize);

			if (ch == '-')
			{

			}
			else
			{
				std::cerr << "Unrecognised character in level file: " << ch;
			}
		}
		
	}

	//Close the file now that we're done
	inFile.close();

	//Close the file now that we're done
	
}

void Level::ReloadLevel()
{
	loadLevel(m_currentLevel);
}

int Level::GetCurrentLevel()
{
	return m_currentLevel;
}

int Level::getCellSize()
{
	return m_cellSize;
}
