#include "GameManager.h"
#include "Snake.h"
#include <SFML/Graphics.hpp>
GameManager* GameManager::m_Instance = nullptr;

GameManager* GameManager::GetInstance()
{
    if (m_Instance == nullptr)
    {
        m_Instance = new GameManager();
    }
    return m_Instance;
}

void GameManager::InitGameManager()
{



	std::mt19937 gen;
	 c = new sf::Clock();

	gen.seed(time(nullptr));
	found = false;

	snake = new Snake();
	

	food = new Food(snake->snakeBody, gen, found);
	window =   new sf::RenderWindow(sf::VideoMode(800, 600), "Snake");
	
	v = window->getDefaultView();
	v.setCenter(0, 0);

	window->setView(v);


	gameover = false;

	


}

void GameManager::GameLoop()
{
	std::mt19937 gen;

	while (window->isOpen())
	{
		float deltaTime = c->restart().asSeconds();
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window->pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window->close();
			if (event.type == sf::Event::KeyPressed) {
				snake->Input(event);
			}
		}

		window->clear(sf::Color::Black);
		if (gameover) {

		}
		else {
			
			gameover = snake->Update(gen, deltaTime, food);
			snake->draw(*window, food);

		}

		window->display();
	}
}

