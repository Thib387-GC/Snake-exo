#include "GameManager.h"
#include "Snake.h"
GameManager* GameManager::m_Instance = nullptr;

GameManager* GameManager::GetInstance()
{
    if (m_Instance == nullptr)
    {
        m_Instance = new GameManager();
    }
    return m_Instance;
}

void GameManager::InitGameManager(sf::RenderWindow* window)
{
	std::mt19937 gen;
	 c = new sf::Clock();

	gen.seed(time(nullptr));
	found = false;


	snake = new Snake();


	food = new Food(snake->snakeBody, gen, found);

	
	v = window->getDefaultView();
	v.setCenter(0, 0);

	window->setView(v);


	gameover = false;

	


}

void GameManager::GameLoop(sf::RenderWindow* window)
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
				Input(event);
			}
		}

		window->clear(sf::Color::Black);
		if (gameover) {

		}
		else {
			
			snake->Update(gen, deltaTime);
			window->draw(*snake);
		}

		window->display();
	}
}

void GameManager::Input(sf::Event event)
{
	if (event.key.scancode == sf::Keyboard::Scancode::Left) {
		*snake->snakeDirection = sf::Vector2f(-1, 0);
	}
	if (event.key.scancode == sf::Keyboard::Scancode::Right) {
		*snake->snakeDirection = sf::Vector2f(1, 0);
	}
	if (event.key.scancode == sf::Keyboard::Scancode::Up) {
		*snake->snakeDirection = sf::Vector2f(0, -1);
	}
	if (event.key.scancode == sf::Keyboard::Scancode::Down) {
		*snake->snakeDirection = sf::Vector2f(0, 1);
	}
}
