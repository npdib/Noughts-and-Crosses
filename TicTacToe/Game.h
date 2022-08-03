#pragma once

#include "Symbol.h"
#include <vector>
#include<iostream>
#include<sstream>


class Game
{
private:

	sf::RenderWindow* window;

	sf::RectangleShape rect1;
	sf::RectangleShape rect2;
	sf::RectangleShape rect3;
	sf::RectangleShape rect4;

	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePos;

	sf::RectangleShape highlight;

	bool mouseHeld;
	bool nought = true;

	int boardSize;
	int boardLineThickness;
	int windowWidth;
	int windowHeight;
	int cellSize;
	int leftPadding;
	int topPadding;

	int xSection = 0;
	int ySection = 0;

	int board[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};

	std::vector<Symbol> symbols;

	// Private Functions

	void initWindow();
	void initVariables();
	void initBoard();

	void getSection();
	void sectionHighlight();

	bool gameOver = false;

public:

	// Constructors and Destructors
	Game();
	virtual ~Game();

	sf::Event sfmlEvent;

	// Functions

	void run();

	void pollEvents();

	void updateMousePos();
	void updateBoard();
	int checkForWin();
	void update();


	void renderBoard(sf::RenderTarget* target);
	void renderHighlight(sf::RenderTarget* target);
	void renderSymbols(sf::RenderTarget* target);
	void render();

};

