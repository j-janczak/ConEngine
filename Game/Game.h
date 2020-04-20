#pragma once
#include <ctime>
#include <windows.h>
#include <iostream>
#include "Screens/MainScreen/MainScreen.h"
#include "Screens/GameScreen/GameScreen.h"
#include "Screens/InfoScreen/InfoScreen.h"
#include "Entities/Hero/Hero.h"

class Game
{
private:
	HANDLE conHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	MainScreen mainScreen;
	GameScreen gameScreen;
	InfoScreen infoScreen;
	Hero hero;
	void gameLoop();

public:
	Game(int, int);
	void engineLoop();
};
