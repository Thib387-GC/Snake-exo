#include "Snake.h"

Snake::Snake() {
	shape = new sf::RectangleShape(sf::Vector2f(32, 32));

	time_between_move = 0.5f;
	current_timer_between_move = 0.f;

	snakeBody.push_back(sf::Vector2f(0, 0));
	snakeDirection = new sf::Vector2f(0, 0);
}

void Snake::Update(std::mt19937 gen , float deltaTime)
{
	if (current_timer_between_move <= 0) {
		if (snakeDirection->x != 0 || snakeDirection->y != 0) {
			sf::Vector2f nextPosition = snakeBody[0] + *snakeDirection;
			if (std::find(snakeBody.begin(), snakeBody.end(), nextPosition) == snakeBody.end()) {
				if (nextPosition == GameManager::GetInstance()->food->foodPosition) {
					do {
						GameManager::GetInstance()->found = false;
						sf::Vector2f tmpPosition((int)(gen() % 23) - 12, (int)(gen() % 17) - 8);
						if (std::find(snakeBody.begin(), snakeBody.end(), tmpPosition) != snakeBody.end() && nextPosition != tmpPosition) {
							GameManager::GetInstance()->found = true;
						}
						GameManager::GetInstance()->food->foodPosition = tmpPosition;
					} while (GameManager::GetInstance()->found);
					snakeBody.push_back(snakeBody[snakeBody.size() - 1]);
				}
				for (int i = snakeBody.size() - 1; i > 0; --i) {
					snakeBody[i] = snakeBody[i - 1];
				}
				snakeBody[0] = nextPosition;
			}
			else {
				GameManager::GetInstance()->gameover = true;
			}

		}
		current_timer_between_move += (time_between_move - 0.01f * snakeBody.size() < 0.06f) ? 0.06f : (time_between_move - 0.01f * snakeBody.size());
	}
	else {
		current_timer_between_move -= deltaTime;
	}

}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (sf::Vector2f p :snakeBody) {
		shape->setPosition(p * shape->getSize().x);
		shape->setFillColor(sf::Color::Green);
		target.draw(*shape);

	}

	shape->setPosition(GameManager::GetInstance()->food->foodPosition * shape->getSize().x);
	shape->setFillColor(sf::Color::Red);
	target.draw(*shape);
}
