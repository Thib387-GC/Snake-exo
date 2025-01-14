#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include "Food.h"
#include "GameManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");

	GameManager* gameManager =new GameManager();
	gameManager->GetInstance();
	gameManager->InitGameManager(&window);
	gameManager->GameLoop(&window);

	return 0;
}
