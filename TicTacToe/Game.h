#pragma once

#include "Symbol.h"
#include <vector>
#include<iostream>



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

	sf::Font font;
	
	sf::Text playerPrompt;
	sf::Text winText;

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

	int win;

	std::vector<Symbol> symbols;

	// Private Functions

	void initWindow();
	void initVariables(sf::Font font);
	void initBoard();
	void initText();

	void getSection();
	void sectionHighlight();

	bool gameOver = false;

public:

	// Constructors and Destructors
	Game(sf::Font font);
	virtual ~Game();

	sf::Event sfmlEvent;

	// Functions

	void run();

	void pollEvents();

	void updateMousePos();
	void updateBoard();
	void updatePrompt();
	void updateGameEndText();
	int checkForWin();
	void update();


	void renderBoard(sf::RenderTarget* target);
	void renderPrompt(sf::RenderTarget& target);
	void renderGameEndText(sf::RenderTarget& target);
	void renderHighlight(sf::RenderTarget* target);
	void renderSymbols(sf::RenderTarget* target);
	void render();

};
