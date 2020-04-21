#pragma once
#include <iostream>
#include "../Screen/Screen.hpp"

class InfoScreen :public Screen
{
public:
	InfoScreen(int, int, int, int, HANDLE*);
	void drawText(int, int, std::string);
};

