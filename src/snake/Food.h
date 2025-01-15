#pragma once
#include <SFML/Graphics.hpp>

class Food
{
public:
	sf::Vector2f foodPosition;


	Food(std::vector<sf::Vector2f> snakeBody, std::mt19937 gen, bool found);

	void draw(sf::RenderWindow& window, sf::RectangleShape& shape) const;

};

