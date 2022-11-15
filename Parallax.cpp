#include "Parallax.h"

void initializeParallax()
{
	backGround[0].size.x = 1024;
	backGround[0].size.y = 689;
	backGround[0].pos.y = 0;
	backGround[0].pos.x = 0;

	backGround[1].size.x = 1024;
	backGround[1].size.y = 689;
	backGround[1].pos.y = 0;
	backGround[1].pos.x = backGround[1].size.x;

	foreGround[0].size.x = 1074;
	foreGround[0].size.y = 495;
	foreGround[0].pos.y = 405;
	foreGround[0].pos.x = -100;

	foreGround[1].size.x = 1074;
	foreGround[1].size.y = 495;
	foreGround[1].pos.y = 405;
	foreGround[1].pos.x = foreGround[1].size.x - 200;

	scrollingBack = 0.5f;
	scrollingMid = 2.0f;
}

void moveParallax()
{

	backGround[0].pos.x -= scrollingBack;
	backGround[1].pos.x -= scrollingBack;

	foreGround[0].pos.x -= scrollingMid;
	foreGround[1].pos.x -= scrollingMid;


	if (backGround[0].pos.x <= 0 - backGround[0].size.x)
	{
		backGround[0].pos.x = backGround[1].size.x;
		

	}
	if (backGround[1].pos.x <= 0 - backGround[1].size.x)
	{
		backGround[1].pos.x = backGround[0].size.x;

	}
	
	if (foreGround[0].pos.x <= 0 - foreGround[0].size.x)
	{
		foreGround[0].pos.x = foreGround[1].size.x-200;
		

	}
	if (foreGround[0].pos.x <= 0 - foreGround[1].size.x)
	{
		foreGround[1].pos.x = foreGround[0].size.x - 200;

	}
	
}

void drawParallax(Texture2D& background, Texture2D& foreground)
{
	DrawTexture(background, backGround[0].pos.x, backGround[0].pos.y, WHITE);
	DrawTexture(background, backGround[1].pos.x, backGround[1].pos.y, WHITE);

	DrawTexture(foreground, foreGround[0].pos.x, foreGround[0].pos.y, WHITE);
	DrawTexture(foreground, foreGround[1].pos.x, foreGround[1].pos.y, WHITE); 
}
