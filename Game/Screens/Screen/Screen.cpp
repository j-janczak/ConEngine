#include <iostream>
#include <windows.h>
#include "Screen.hpp"

Screen::Screen(int w, int h, HANDLE* conHandlePointer) : camera(w, h){
    conHandle = conHandlePointer;
    width = w;
    height = h;

    CHAR_INFO def;
    def.Char.UnicodeChar = ' ';
    def.Attributes = Entity::BG_WHITE;

    for (int y = 0; y < height; y++) {
        std::vector<CHAR_INFO> row;
        for (int x = 0; x < width; x++) row.push_back(def);
        buffer.push_back(row);
    }
}

void Screen::setChar(int x, int y, char ch, WORD attr) {
    buffer[y][x].Char.UnicodeChar = ch;
    buffer[y][x].Attributes = attr;
}

void Screen::draw(Entity entity) {
    Entity::TxCharMap entityTX = entity.getTextureMap();
    Entity::TxFGMap entityFG = entity.getForegroundMap();
    Entity::TxBGMap entityBG = entity.getBackgroundMap();
    Entity::TxAlphaMap entityBGT = entity.getBgTransparentMap();

    int yi = 0;
    for (int y = 0; y < entity.getHeight(); y++) {
        int xi = 0;
        int placeY = camera.calculateY(entity.y, yi);
        yi++;

        if (placeY >= height) break;
        if (placeY < 0) continue;

        for (int x = 0; x < entity.getWidth(); x++) {
            int placeX = camera.calculateX(entity.x, xi);
            xi++;

            if (placeX >= width) break;
            if (placeX < 0) continue;

            WORD blockAttr = entityBGT[y][x] ? entityFG[y][x] | ScreenBackground : entityFG[y][x] | entityBG[y][x];
            setChar(placeX, placeY, entityTX[y][x], blockAttr);
        }
    }
}

void Screen::clear(WORD color) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            setChar(x, y, ' ', color);
        }
    }
}