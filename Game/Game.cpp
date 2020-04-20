#include <ctime>
#include <string>
#include <windows.h>
#include <conio.h>
#include "Game.h"

Game::Game(int w, int h) : 
	mainScreen(w, h, &conHandle), 
	gameScreen(w - 2, h - 6, 1, 1, &conHandle),
	infoScreen(w - 2, 3, 1, h - 4, &conHandle){

	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(conHandle, &cci);
	cci.bVisible = false;
	SetConsoleCursorInfo(conHandle, &cci);

	SetConsoleTitleA("Haha! its a game");
}

void Game::engineLoop() {
	COORD c;
	c.X = 0;
	c.Y = 0;
	SetConsoleCursorPosition(conHandle, c);

	gameLoop();
}

void Game::gameLoop() {
	if (_kbhit() != 0) {
		char key = _getch();

		if (key == 'a') hero.x--;
		else if (key == 'd') hero.x++;
		else if (key == 'w') hero.y--;
		else if (key == 's') hero.y++;
	}

	gameScreen.clear(Screen::BG_BLUE);
	infoScreen.clear(Screen::BG_BLUE);

	gameScreen.draw(hero);

	mainScreen.scale(gameScreen);
	mainScreen.scale(infoScreen);
	mainScreen.drawBuffer();
}
