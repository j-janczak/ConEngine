#pragma once
#include <ctime>
#include <windows.h>
#include <iostream>
#include "Screens/MainScreen/MainScreen.hpp"
#include "Screens/GameScreen/GameScreen.hpp"
#include "Screens/InfoScreen/InfoScreen.hpp"
#include "Entities/Hero/Hero.hpp"

class Game
{
private:
	HANDLE conHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	MainScreen mainScreen;
	GameScreen gameScreen;
	InfoScreen infoScreen;
	Hero hero;
	Sprite tank, man;
	void gameLoop();

public:
	Game(int, int);
	void engineLoop();
};
