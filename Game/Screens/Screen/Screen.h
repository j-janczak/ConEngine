#pragma once
#include <windows.h>
#include "../../Entities/Entity/Entity.h"

class Screen
{
protected:
    HANDLE* conHandle;

public:
    int width, height;
    int offsetX = 0, offsetY = 0;
    std::vector<std::vector<CHAR_INFO>> buffer;

    Screen(int, int, HANDLE*);
    void setChar(int, int, char, WORD);
    void draw(Entity);
    void clear(WORD);

    typedef enum FG_COLORS
    {
        FG_BLACK = 0,
        FG_BLUE = 1,
        FG_GREEN = 2,
        FG_CYAN = 3,
        FG_RED = 4,
        FG_MAGENTA = 5,
        FG_BROWN = 6,
        FG_LIGHTGRAY = 7,
        FG_GRAY = 8,
        FG_LIGHTBLUE = 9,
        FG_LIGHTGREEN = 10,
        FG_LIGHTCYAN = 11,
        FG_LIGHTRED = 12,
        FG_LIGHTMAGENTA = 13,
        FG_YELLOW = 14,
        FG_WHITE = 15
    }FG_COLORS;

    typedef enum BG_COLORS
    {
        BG_NAVYBLUE = 16,
        BG_GREEN = 32,
        BG_TEAL = 48,
        BG_MAROON = 64,
        BG_PURPLE = 80,
        BG_OLIVE = 96,
        BG_SILVER = 112,
        BG_GRAY = 128,
        BG_BLUE = 144,
        BG_LIME = 160,
        BG_CYAN = 176,
        BG_RED = 192,
        BG_MAGENTA = 208,
        BG_YELLOW = 224,
        BG_WHITE = 240
    }BG_COLORS; //https://stackoverflow.com/a/49929936/4829799 <3
};

