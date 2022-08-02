#include "Game.h"


void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Tic Tac Toe", sf::Style::Close | sf::Style::Titlebar);
}

Game::Game()
{
	this->initWindow();
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

void Game::render()
{
	this->window->clear();

	// Render everything
	
	this->window->display();
}
