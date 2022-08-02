#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>


class Game
{
private:

	sf::RenderWindow* window;

	sf::RectangleShape rect1;
	sf::RectangleShape rect2;
	sf::RectangleShape rect3;
	sf::RectangleShape rect4;

	int boardSize;
	int boardLineThickness;
	int windowWidth;
	int windowHeight;
	int cellSize;
	int leftPadding;
	int topPadding;

	// Private Functions

	void initWindow();
	void initVariables();
	void initBoard();

public:

	// Constructors and Destructors
	Game();
	virtual ~Game();

	sf::Event sfmlEvent;

	// Functions

	void run();

	void pollEvents();

	void update();


	void renderBoard(sf::RenderTarget* target);
	void render();

};

