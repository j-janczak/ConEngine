#include "InfoScreen.hpp"

InfoScreen::InfoScreen(int w, int h, int ofx, int ofy, HANDLE* conHandlePointer) : Screen(w, h, conHandlePointer) {
	offsetX = ofx;
	offsetY = ofy;
}

void InfoScreen::drawText(int x, int y, std::string text) {
	for (int ix = 0; ix < text.length(); ix++) {
		if (x + ix > width) break;
		if (x + ix < 0) continue;

		buffer[y][x + ix].Char.UnicodeChar = text[ix];
	}
}