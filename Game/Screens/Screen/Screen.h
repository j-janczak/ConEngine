#pragma once
#include <windows.h>
#include "../../Entities/Entity/Entity.h"

class Screen
{
protected:
    HANDLE* conHandle;
    WORD Screenbackground;

public:
    int width, height;
    int offsetX = 0, offsetY = 0;
    std::vector<std::vector<CHAR_INFO>> buffer;

    Screen(int, int, HANDLE*);
    void setChar(int, int, char, WORD);
    void draw(Entity);
    void clear(WORD);
};

