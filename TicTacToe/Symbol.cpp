#include "Symbol.h"

Symbol::Symbol(float i, float j, const bool type, const int cellSize, const int lineThickness, const int leftBuffer, const int topBuffer)
{
	this->type = type;

	if (this->type)
	{
		this->circle.setRadius(static_cast<float>(0.3 * cellSize));
		this->circle.setPosition(sf::Vector2f(static_cast<float>(leftBuffer + j * (cellSize + lineThickness) + 0.2 * cellSize), static_cast<float>(topBuffer + i * (cellSize + lineThickness) + 0.2 * cellSize)));
		this->circle.setFillColor(sf::Color::Transparent);
		this->circle.setOutlineThickness(6.f);
		this->circle.setOutlineColor(sf::Color(50,50,255));
	}
	else
	{
		this->cross1.setSize(sf::Vector2f(static_cast<float>(0.8 * cellSize), 6.f));
		this->cross1.setOrigin(sf::Vector2f(static_cast<float>(0.4 * cellSize), 3.f));
		this->cross1.setPosition(sf::Vector2f(static_cast<float>(leftBuffer + j * (cellSize + lineThickness) + 0.5 * cellSize), static_cast<float>(topBuffer + i * (cellSize + lineThickness) + 0.5 * cellSize)));
		this->cross1.setRotation(45.f);
		this->cross1.setFillColor(sf::Color(160,32,240));

		this->cross2.setSize(sf::Vector2f(static_cast<float>(0.8 * cellSize), 6.f));
		this->cross2.setOrigin(sf::Vector2f(static_cast<float>(0.4 * cellSize), 3.f));
		this->cross2.setPosition(sf::Vector2f(static_cast<float>(leftBuffer + j * (cellSize + lineThickness) + 0.5 * cellSize), static_cast<float>(topBuffer + i * (cellSize + lineThickness) + 0.5 * cellSize)));
		this->cross2.setRotation(-45.f);
		this->cross2.setFillColor(sf::Color(160, 32, 240));
	}
	
}

Symbol::~Symbol()
{
}

void Symbol::render(sf::RenderTarget* target)
{
	if (this->type)
		target->draw(this->circle);
	else
	{
		target->draw(this->cross1);
		target->draw(this->cross2);

	}

}
