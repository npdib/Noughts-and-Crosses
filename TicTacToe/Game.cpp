#include "Game.h"

// Private Functions

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Tic Tac Toe", sf::Style::Close | sf::Style::Titlebar);
}

void Game::initVariables()
{
	this->boardSize = 500;
	this->boardLineThickness = 20;
	this->windowWidth = this->window->getSize().x;
	this->windowHeight = this->window->getSize().y;
	this->cellSize = (this->boardSize - 2 * (this->boardLineThickness)) / 3;
	this->leftPadding = (this->windowWidth - this->boardSize) / 2;
	this->topPadding = (this->windowHeight - this->boardSize) / 2;
}

void Game::initBoard()
{

	this->rect1.setSize(sf::Vector2f(boardLineThickness, boardSize));
	this->rect1.setPosition(this->leftPadding + this->cellSize, this->topPadding);

	this->rect2.setSize(sf::Vector2f(boardLineThickness, boardSize));
	this->rect2.setPosition(this->leftPadding + 2 * this->cellSize + this->boardLineThickness, this->topPadding);

	this->rect3.setSize(sf::Vector2f(boardSize, boardLineThickness));
	this->rect3.setPosition(this->leftPadding, this->topPadding + this->cellSize);

	this->rect4.setSize(sf::Vector2f(boardSize, boardLineThickness));
	this->rect4.setPosition(this->leftPadding, this->topPadding + 2 * this->cellSize + this->boardLineThickness);

}

//Constructors and Destructors

Game::Game()
{
	this->initWindow();
	this->initVariables();
	this->initBoard();
}

Game::~Game()
{
	delete this->window;
}

// Functions

void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

void Game::pollEvents()
{

	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
				this->window->close();
		}
	}
}

void Game::update()
{

	this->pollEvents();	

}

void Game::renderBoard(sf::RenderTarget* target)
{
	target->draw(this->rect1);
	target->draw(this->rect2);
	target->draw(this->rect3);
	target->draw(this->rect4);
	
}

void Game::render()
{
	this->window->clear();

	// Render everything

	this->renderBoard(this->window);
	
	this->window->display();
}
