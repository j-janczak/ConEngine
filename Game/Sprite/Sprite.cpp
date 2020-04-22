#include "Sprite.hpp"

void Sprite::setTexture(TxCharMap m, TxFGMap fArgs, TxFGMap bArgs, TxAlphaMap btM) {
	textureMap = m;
	foregroundMap = fArgs;
	backgroundMap = bArgs;
	bgAlphaMap = btM;

	width = m[0].length();
	height = m.size();
}

void Sprite::loadTexture(std::string file) {
	std::string filePath = "game_data/" + file + ".cedat";
	std::fstream textureFile;
	textureFile.open(filePath.c_str(), std::ios::in);
	
	int textureSizeStage = 0;
	int textureWidth = 0;
	int textureHeight = 0;

	int charMapStage = 0;
	TxCharMap tmpCharMap;

	int fgMapStage = 0;
	TxFGMap tmpFGMap;

	int bgMapStage = 0;
	TxBGMap tmpBGMap;

	int alphaMapStage = 0;
	TxAlphaMap tmpAlphaMap;

	std::string line;
	while (getline(textureFile, line)) {
		if (line == "textureSize:") {
			textureSizeStage = 1;
			continue;
		}
		else if (line == "charMap:") {
			charMapStage = 1;
			continue;
		}
		else if (line == "fgMap:") {
			fgMapStage = 1;
			continue;
		}
		else if (line == "bgMap:") {
			bgMapStage = 1;
			continue;
		}
		else if (line == "alphaMap:") {
			alphaMapStage = 1;
			continue;
		}

		if (textureSizeStage) {
			if (textureSizeStage == 1) textureWidth = atoi(line.c_str());
			else if (textureSizeStage == 2) textureHeight = atoi(line.c_str());
			textureSizeStage++;
			if (textureSizeStage > 2) textureSizeStage = 0;
		}
		else if (charMapStage) {
			tmpCharMap.push_back(line);
			charMapStage++;
			if (charMapStage > textureHeight) charMapStage = 0;
		}
		else if (fgMapStage) {
			loadTextureArrayParse(fgMapStage, line, &tmpFGMap);
			fgMapStage++;
			if (fgMapStage > textureHeight) fgMapStage = 0;
		}
		else if (bgMapStage) {
			loadTextureArrayParse(bgMapStage, line, &tmpBGMap);
			bgMapStage++;
			if (bgMapStage > textureHeight) bgMapStage = 0;
		}
		else if (alphaMapStage) {
			loadTextureArrayParse(alphaMapStage, line, &tmpAlphaMap);
			alphaMapStage++;
			if (alphaMapStage > textureHeight) alphaMapStage = 0;
		}
	}
	textureFile.close();

	setTexture(tmpCharMap, tmpFGMap, tmpBGMap, tmpAlphaMap);
}

void Sprite::loadTextureArrayParse(int stage, std::string line, Sprite::TxMapAny* tmpArray) {
	tmpArray->push_back(std::vector<int>());
	char* lineChar = new char[line.size() + 1];			//Creating an char array that stores lines
	strcpy(lineChar, line.c_str());						//Copy line string to char table

	char* arrg = strtok(lineChar, ",");					//Get first color parametr
	while (arrg != NULL) {
		(*tmpArray)[stage - 1].push_back(atoi(arrg));
		arrg = strtok(NULL, ",");
	}

	delete[] lineChar;
	delete[] arrg;
}

int Sprite::getWidth() {
	return width;
}

int Sprite::getHeight() {
	return height;
}

Sprite::TxCharMap Sprite::getTextureMap() {
	return textureMap;
}

Sprite::TxFGMap Sprite::getForegroundMap() {
	return foregroundMap;
}

Sprite::TxFGMap Sprite::getBackgroundMap() {
	return backgroundMap;
}

Sprite::TxAlphaMap Sprite::getBgAlphaMap() {
	return bgAlphaMap;
}