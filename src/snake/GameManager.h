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
	sf::RenderWindow window=sf::RenderWindow(sf::VideoMode(800, 600), "Snake");

	static GameManager* m_Instance;
	static GameManager* GetInstance();
	void InitGameManager(sf::RenderWindow* window);
	void GameLoop(sf::RenderWindow* window);
	void Input(sf::Event event);
};

