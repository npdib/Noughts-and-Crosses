#include "Game.h"

// Private Functions

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Tic Tac Toe", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
}

void Game::initVariables()
{
	this->mouseHeld = false;
	this->boardSize = 400;
	this->boardLineThickness = 5;
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

void Game::getSection()
{
	// Find which section of the board the mouse is in

	if (this->mousePos.x > this->leftPadding && this->mousePos.x < (this->leftPadding + this->cellSize))
		this->xSection = 1;
	else if (this->mousePos.x > (this->leftPadding + this->cellSize + this->boardLineThickness) && this->mousePos.x < (this->leftPadding + 2 * this->cellSize + this->boardLineThickness))
		this->xSection = 2;
	else if (this->mousePos.x > (this->leftPadding + 2 * this->cellSize + 2 * this->boardLineThickness) && this->mousePos.x < (this->leftPadding + 3 * this->cellSize + 2 * this->boardLineThickness))
		this->xSection = 3;
	else
		this->xSection = 0;

	if (this->mousePos.y > this->topPadding && this->mousePos.y < (this->topPadding + this->cellSize))
		this->ySection = 1;
	else if (this->mousePos.y > (this->topPadding + this->cellSize + this->boardLineThickness) && this->mousePos.y < (this->topPadding + 2 * this->cellSize + this->boardLineThickness))
		this->ySection = 2;
	else if (this->mousePos.y > (this->topPadding + 2 * this->cellSize + 2 * this->boardLineThickness) && this->mousePos.y < (this->topPadding + 3 * this->cellSize + 2 * this->boardLineThickness))
		this->ySection = 3;
	else
		this->ySection = 0;

	//std::cout << this->ySection << ", " << this->xSection << "\n";

}

void Game::sectionHighlight()
{

	this->highlight.setSize(sf::Vector2f(this->cellSize, this->cellSize));
	this->highlight.setPosition( (this->leftPadding + (this->xSection - 1) * this->cellSize + (this->xSection - 1) * this->boardLineThickness), (this->topPadding + (this->ySection - 1) * this->cellSize + (this->ySection - 1) * this->boardLineThickness));
	this->highlight.setFillColor(sf::Color::Transparent);
	this->highlight.setOutlineThickness(this->boardLineThickness);
	this->highlight.setOutlineColor(sf::Color::Yellow);

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

void Game::updateMousePos()
{
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePos = this->window->mapPixelToCoords(this->mousePosWindow);

	//std::cout << "Mouse pos:\t " << this->mousePos.x << ", " << this->mousePos.y << "\n";

}

void Game::updateBoard()
{

	this->getSection();

	if (this->xSection != 0 && this->ySection != 0)
	{

		
			

		this->sectionHighlight();

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!this->mouseHeld)
			{
				this->mouseHeld = true;

				if (this->board[this->ySection - 1][this->xSection - 1] == 0)
				{
					Symbol symbol(static_cast<float>(this->ySection - 1), static_cast<float>(this->xSection - 1), this->nought, this->cellSize, this->boardLineThickness, this->leftPadding, this->topPadding);
					this->symbols.push_back(symbol);
					this->nought = !this->nought;
					if (this->nought)
						this->board[this->ySection - 1][this->xSection - 1] = 1;
					else
						this->board[this->ySection - 1][this->xSection - 1] = -1;

					for (size_t i = 0; i < 3; i++)
					{
						for (size_t j = 0; j < 3; j++)
						{
							std::cout << board[i][j];
						}
						std::cout << "\n";
					}
				}
			}
		}
		else
		{
			this->mouseHeld = false;
		}

	}

}

void Game::update()
{

	this->updateBoard();
	this->updateMousePos();
	

	this->pollEvents();	

}

void Game::renderBoard(sf::RenderTarget* target)
{
	target->draw(this->rect1);
	target->draw(this->rect2);
	target->draw(this->rect3);
	target->draw(this->rect4);
	
}

void Game::renderHighlight(sf::RenderTarget* target)
{
	target->draw(this->highlight);
}

void Game::renderSymbols(sf::RenderTarget* target)
{
	for (auto& s : this->symbols)
	{
		s.render(target);
	}
}

void Game::render()
{
	this->window->clear();

	// Render everything

	this->renderBoard(this->window);

	if (this->xSection != 0 && this->ySection != 0)
	{
		this->renderHighlight(this->window);
	}

	this->renderSymbols(this->window);
	
	this->window->display();
}
