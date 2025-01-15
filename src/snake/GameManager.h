#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include "Food.h"
class Snake;
class GameManager
{
public :
	bool found;
	Snake* snake;
	bool gameover;
	sf::Clock* c;
	Food* food;

	sf::View v;
	sf::RenderWindow* window;

	static GameManager* m_Instance;
	static GameManager* GetInstance();
	void InitGameManager();
	void GameLoop();
};

