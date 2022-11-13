#include "Parallax.h"

void initializeParallax()
{
	parallax.rec.width = GetScreenWidth();
	parallax.rec.height = GetScreenHeight() / 8 * 3;
	parallax.rec.y = GetScreenHeight() / 8 * 6 + 20;
	parallax.rec.x = GetScreenWidth() * 0;
}