#pragma once
#include <raylib.h>

struct Obstacle
{
	Rectangle rec;
	bool collition = false;
	float speed;
};
extern Obstacle obstacle;

void initializeObstacle();
void moveObstacle();