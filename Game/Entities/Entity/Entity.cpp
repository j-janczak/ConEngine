#include "Entity.hpp"

void Entity::setTexture(TxCharMap m, TxFGMap fArgs, TxFGMap bArgs, TxAlphaMap btM) {
	textureMap = m;
	foregroundMap = fArgs;
	backgroundMap = bArgs;
	bgTransparentMap = btM;

	width = m[0].length();
	height = m.size();
}

int Entity::getWidth() {
	return width;
}

int Entity::getHeight() {
	return height;
}

Entity::TxCharMap Entity::getTextureMap() {
	return textureMap;
}

Entity::TxFGMap Entity::getForegroundMap() {
	return foregroundMap;
}

Entity::TxFGMap Entity::getBackgroundMap() {
	return backgroundMap;
}

Entity::TxAlphaMap Entity::getBgTransparentMap() {
	return bgTransparentMap;
}