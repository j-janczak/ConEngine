#include "Hero.hpp"

Hero::Hero()
{
	WORD f = FG_GREEN;
	WORD f1 = FG_BLACK;
	WORD b = BG_BLUE;
	WORD b1 = BG_GREEN;
	WORD b2 = BG_GRAY;

	Sprite::TxCharMap texture = {
		"   _ __",
		"‹‹ÕÕ‹‹",
		"ﬂ00000ﬂ"
	};

	Sprite::TxFGMap foreground = {
		{f, f, f, f, f, f, f},
		{f, f, f1, f1, f1, f, f},
		{f, f1, f1, f1, f1, f1, f}
	};

	Sprite::TxBGMap background = {
		{b, b, b, b, b, b, b},
		{b, b, b1, b1, b1, b, b},
		{b, b, b, b, b, b, b},
	};

	Sprite::TxAlphaMap alpha = {
		{1, 1, 1, 1, 1, 1, 1},
		{1, 1, 0, 0, 0, 1, 1},
		{1, 1, 1, 1, 1, 1, 1}
	};

	setTexture(texture, foreground, background, alpha);
}
