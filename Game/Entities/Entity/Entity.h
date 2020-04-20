#pragma once
#include <string>
#include <vector>
#include <iostream>

class Entity
{
public:
	int x = 0, y = 0;

private:
	int width, height;
	std::vector<std::string> map;

public:
	void setTexture(std::vector<std::string>);
	int getWidth();
	int getHeight();
	std::vector<std::string> getMap();
};

