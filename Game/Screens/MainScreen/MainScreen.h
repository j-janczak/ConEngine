#pragma once
#include "../Screen/Screen.h"

class MainScreen :public Screen
{
public:
	MainScreen(int, int, HANDLE*);
	void scale(Screen);
	void drawBuffer();
};

