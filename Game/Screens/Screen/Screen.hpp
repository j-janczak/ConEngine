#pragma once
#include <windows.h>
#include "../../Entities/Entity/Entity.hpp"
#include "../../Sprite/Sprite.hpp"
#include "../../Camera/Camera.hpp"

class Screen
{
protected:
    HANDLE* conHandle;
    WORD ScreenBackground;

public:
    int width, height;
    int offsetX = 0, offsetY = 0;
    Camera camera;
    std::vector<std::vector<CHAR_INFO>> buffer;

    Screen(int, int, HANDLE*);
    void setChar(int, int, char, WORD);
    void draw(Entity);
    void draw(Sprite, int, int);
    void clear(WORD);
};

