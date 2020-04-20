#include "MainScreen.h"

MainScreen::MainScreen(int w, int h, HANDLE* conHandlePointer) : Screen(w, h, conHandlePointer) {

}

void MainScreen::scale(Screen screen) {
	for (int y = screen.offsetY; y < screen.offsetY + screen.height; y++) {
		for (int x = screen.offsetX; x < screen.offsetX + screen.width; x++)
			buffer[y][x] = screen.buffer[y - screen.offsetY][x - screen.offsetX];
	}
}

void MainScreen::drawBuffer() {
    COORD dwBufferSize = { width, height };
    COORD dwBufferCoord = { 0, 0 };
    SMALL_RECT rcRegion = { 0, 0, width - 1, height - 1 };

    CHAR_INFO* tmp_buffer = new CHAR_INFO[height * width];
    int i = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            tmp_buffer[i] = buffer[y][x];
            i++;
        }
    }

    WriteConsoleOutput(*conHandle, tmp_buffer, dwBufferSize, dwBufferCoord, &rcRegion);

    delete[] tmp_buffer;
}