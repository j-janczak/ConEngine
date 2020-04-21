#include "GameScreen.hpp"

GameScreen::GameScreen(int w, int h, int ofx, int ofy, HANDLE* conHandlePointer) : Screen(w, h, conHandlePointer) {
	offsetX = ofx;
	offsetY = ofy;
	ScreenBackground = Entity::BG_CYAN;
}
