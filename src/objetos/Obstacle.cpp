#include "Obstacle.h"

void initializeObstacle()
{
	obstacle.rec.width = 60;
	obstacle.rec.height = 50;
	obstacle.rec.y = GetScreenHeight() / 8 * 6 - 10;
	obstacle.rec.x = GetScreenWidth() + obstacle.rec.width;
}

void moveObstacle()
{
	obstacle.rec.x -= GetFrameTime() * 300;

	if (obstacle.rec.x < GetScreenWidth() *0 - 400)
	{
		obstacle.rec.x = GetScreenWidth() + obstacle.rec.width;
	}
}