#pragma once

//Library Includes
#include <SFML/Graphics.hpp>

//Project Includes
#include "../../Framework/Headers/GameObject.h"

class Level
{

public:

	Level();

	virtual void Draw(sf::RenderTarget& _target);
	virtual void Update(sf::Time _frameTime);
	void loadLevel(int _levelToLoad);
	void ReloadLevel();
	int GetCurrentLevel();

private:

	int m_currentLevel;
	GameObject* m_player;
	sf::Sprite m_background;
	std::vector<GameObject*> m_drawSpriteList;
	std::vector<GameObject*> m_updateList;
};
