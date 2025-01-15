#include "Snake.h"
Snake::Snake() {
	shape = new sf::RectangleShape(sf::Vector2f(32, 32));

	time_between_move = 0.5f;
	current_timer_between_move = 0.f;

	snakeBody.push_back(sf::Vector2f(0, 0));
	snakeDirection = new sf::Vector2f(0, 0);
}

bool Snake::Update(std::mt19937 gen, float deltaTime, Food* food)
{
	GameManager* gameManager;
	gameManager = gameManager->GetInstance();

	if (current_timer_between_move <= 0) {
		if (snakeDirection->x != 0 || snakeDirection->y != 0) {
			sf::Vector2f nextPosition = snakeBody[0] + *snakeDirection;
			if (std::find(snakeBody.begin(), snakeBody.end(), nextPosition) == snakeBody.end()) {
				if (nextPosition == food->foodPosition) {
					do {
						sf::Vector2f tmpPosition((int)(gen() % 23) - 12, (int)(gen() % 17) - 8);
						if (std::find(snakeBody.begin(), snakeBody.end(), tmpPosition) == snakeBody.end() && nextPosition != tmpPosition) {
							gameManager->found = false;
							food->foodPosition = tmpPosition;
						}
						else {
							gameManager->found = true;
						}
					} while (gameManager->found);
					snakeBody.push_back(snakeBody[snakeBody.size() - 1]);
				}

				for (int i = snakeBody.size() - 1; i > 0; --i) {
					snakeBody[i] = snakeBody[i - 1];
				}
				snakeBody[0] = nextPosition;
			}
			else {
				return true;
			}

		}
		current_timer_between_move += (time_between_move - 0.01f * snakeBody.size() < 0.06f) ? 0.06f : (time_between_move - 0.01f * snakeBody.size());
	}
	else {
		current_timer_between_move -= deltaTime;
	}
	return false;
}

void Snake::draw(sf::RenderWindow& window, Food* food) const {
	for (sf::Vector2f p : snakeBody) {
		shape->setPosition(p * shape->getSize().x);
		shape->setFillColor(sf::Color::Green);
		window.draw(*shape);
	}

	food->draw(window, *shape);
}

void Snake::Input(sf::Event event)
{
	if (event.key.scancode == sf::Keyboard::Scancode::Left) {
		*snakeDirection = sf::Vector2f(-1, 0);
	}
	if (event.key.scancode == sf::Keyboard::Scancode::Right) {
		*snakeDirection = sf::Vector2f(1, 0);
	}
	if (event.key.scancode == sf::Keyboard::Scancode::Up) {
		*snakeDirection = sf::Vector2f(0, -1);
	}
	if (event.key.scancode == sf::Keyboard::Scancode::Down) {
		*snakeDirection = sf::Vector2f(0, 1);
	}
}
