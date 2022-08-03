#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>


class Symbol
{
private:

	bool type;

	sf::CircleShape circle;

	sf::RectangleShape cross1;
	sf::RectangleShape cross2;



public:
	Symbol(float i, float j, const bool type, const int cellSize, const int lineThickness, const int leftBuffer, const int topBuffer);
	virtual ~Symbol();

	void render(sf::RenderTarget* target);
};

