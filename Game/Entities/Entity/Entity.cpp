#include "Entity.h"

void Entity::setTexture(std::vector<std::string> m) {
	map = m;
	width = map[0].length();
	height = map.size();
}

int Entity::getWidth() {
	return width;
}

int Entity::getHeight() {
	return height;
}

std::vector<std::string> Entity::getMap() {
	return map;
}