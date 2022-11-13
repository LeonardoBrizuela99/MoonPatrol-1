#pragma once
#include <raylib.h>

struct Obstacle
{
	Rectangle rec;
	float speed;
};
extern Obstacle obstacle;

void initializeObstacle();
void moveObstacle();