#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "GameManager.h"
class Snake 
{public:
	sf::RectangleShape* shape;
	float time_between_move;
	float current_timer_between_move;
	std::vector<sf::Vector2f> snakeBody;
	sf::Vector2f* snakeDirection;
	Snake();
	bool Update(std::mt19937 gen, float deltaTime, Food* food);
	void draw(sf::RenderWindow& window, Food* food) const;

	void Input(sf::Event event);

};