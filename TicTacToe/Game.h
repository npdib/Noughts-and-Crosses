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

	// Private Functions

	void initWindow();

public:

	// Constructors and Destructors
	Game();
	virtual ~Game();

	sf::Event sfmlEvent;

	// Functions

	void run();

	void pollEvents();

	void update();
	void render();

};

