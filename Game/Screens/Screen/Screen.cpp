#include <iostream>
#include <windows.h>
#include "Screen.h"

Screen::Screen(int w, int h, HANDLE* conHandlePointer){
    conHandle = conHandlePointer;
    width = w;
    height = h;

    CHAR_INFO def;
    def.Char.UnicodeChar = ' ';
    def.Attributes = BG_WHITE;

    for (int y = 0; y < height; y++) {
        std::vector<CHAR_INFO> row;
        for (int x = 0; x < width; x++) row.push_back(def);
        buffer.push_back(row);
    }
}

void Screen::setChar(int x, int y, char ch, WORD attr) {
    buffer[y][x].Char.AsciiChar = ch;
    buffer[y][x].Attributes = attr;
}

void Screen::draw(Entity entity) {
    int yi = 0;
    for (int y = 0; y < entity.getHeight(); y++) {
        int xi = 0;
        for (int x = 0; x < entity.getWidth(); x++) {
            setChar(entity.x + xi, entity.y + yi, entity.getMap()[y][x], FG_LIGHTGRAY | BG_BLUE);
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