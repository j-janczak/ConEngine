#include "Hero.h"

Hero::Hero()
{
	WORD f = FG_GREEN;
	WORD f1 = FG_BLACK;
	WORD b = BG_BLUE;

	Entity::TxCharMap texture = {
		"   _ __",
		"‹‹€€€‹‹",
		"ﬂ00000ﬂ"
	};

	Entity::TxFGMap foreground = {
		{f, f, f, f, f, f, f},
		{f, f, f, f, f, f, f},
		{f, f1, f1, f1, f1, f1, f}
	};

	Entity::TxBGMap background = {
		{b, b, b, b, b, b, b},
		{b, b, b, b, b, b, b},
		{b, b, b, b, b, b, b},
	};

	Entity::TxAlphaMap alpha = {
		{1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1}
	};

	setTexture(texture, foreground, background, alpha);
}
