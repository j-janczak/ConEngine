#pragma once
#include "../Screen/Screen.hpp"

class MainScreen :public Screen
{
public:
	MainScreen(int, int, HANDLE*);
	void scale(Screen);
	void drawBuffer();
};

