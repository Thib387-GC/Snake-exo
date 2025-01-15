#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>
#include "Food.h"
#include "GameManager.h"

int main()
{

	GameManager* gameManager =new GameManager();
	gameManager->GetInstance();
	gameManager->InitGameManager();
	gameManager->GameLoop();

	return 0;
}
