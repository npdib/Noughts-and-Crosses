#include "Game.h"
#define _WIN32_WINNT 0x0500
#include <windows.h>

#include "Garamond.h"

int main()
{

	//HWND hWnd = GetConsoleWindow();
	//ShowWindow(hWnd, SW_HIDE);

	sf::Font font;
	font.loadFromMemory(&Garamond_ttf, Garamond_ttf_len);

	Game game(font);

	game.run();

	// End of application
	return 0;
}