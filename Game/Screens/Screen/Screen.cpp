#include <iostream>
#include <windows.h>
#include "Screen.h"

Screen::Screen(int w, int h, HANDLE* conHandlePointer){
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
    int yi = 0;
    Entity::TxCharMap entityTX = entity.getTextureMap();
    Entity::TxFGMap entityFG = entity.getForegroundMap();
    Entity::TxBGMap entityBG = entity.getBackgroundMap();
    Entity::TxAlphaMap entityBGT = entity.getBgTransparentMap();

    for (int y = 0; y < entity.getHeight(); y++) {
        int xi = 0;
        for (int x = 0; x < entity.getWidth(); x++) {
            WORD blockAttr = (entityBGT[y][x] == 1) ? entityFG[y][x] | Screenbackground : entityFG[y][x] | entityBG[y][x];
            setChar(entity.x + xi, entity.y + yi, entityTX[y][x], blockAttr);
            xi++;
        }
        yi++;
    }
}

void Screen::clear(WORD color) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            setChar(x, y, ' ', color);
        }
    }
}