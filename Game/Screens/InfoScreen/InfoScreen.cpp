#include "InfoScreen.h"

InfoScreen::InfoScreen(int w, int h, int ofx, int ofy, HANDLE* conHandlePointer) : Screen(w, h, conHandlePointer) {
	offsetX = ofx;
	offsetY = ofy;
}