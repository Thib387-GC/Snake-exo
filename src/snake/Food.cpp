#include <random>
#include "Food.h"


Food::Food(std::vector<sf::Vector2f> snakeBody , std::mt19937 gen , bool found)
{

	do {
		found = false;
		sf::Vector2f tmpPosition((int)(gen() % 23) - 12, (int)(gen() % 17) - 8);
		if (std::find(snakeBody.begin(), snakeBody.end(), tmpPosition) != snakeBody.end()) {
			found = true;
		}
		foodPosition = tmpPosition;
	} while (found);


}

void Food::draw(sf::RenderWindow& window, sf::RectangleShape& shape) const {
	shape.setPosition(foodPosition * shape.getSize().x);
	shape.setFillColor(sf::Color::Red);
	window.draw(shape);
}