#include <ctime>
#include <stdio.h>
#include "Game\Game.h"

int main()
{
    SetConsoleOutputCP(852);

    Game game(120, 29);

    while (1) {
        std::clock_t start = std::clock();
        game.engineLoop();
        std::clock_t end = std::clock();
        printf("x FPS");
        Sleep(16.6666 - (end - start));
    }

    return 0;
}