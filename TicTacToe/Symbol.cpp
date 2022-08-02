#include "Symbol.h"

Symbol::Symbol(float i, float j, const bool type, const int cellSize, const int lineThickness, const int leftBuffer, const int topBuffer)
{
	this->type = type;

	if (this->type)
	{
		this->circle.setRadius(0.4 * cellSize);
		this->circle.setPosition(sf::Vector2f(static_cast<float>(leftBuffer + j * (cellSize + lineThickness) + 0.1 * cellSize), static_cast<float>(topBuffer + i * (cellSize + lineThickness) + 0.1 * cellSize)));
	}

	




}

Symbol::~Symbol()
{
}

void Symbol::render(sf::RenderTarget* target)
{
	if (this->type)
		target->draw(this->circle);

}
