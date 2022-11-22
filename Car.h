#pragma once
#include <raylib.h>
#include "Obstacle.h"

struct Car
{
	bool bulletActive = false;
	Rectangle rec;
	Rectangle bullet;
	Vector2 speed;
	Vector2 startingPoint;
	bool isJumping;
	bool canCollide;
	int lives;
	float maxJump;
};
extern Car car;

void initializeCar();
void playerInput();
void playerMovement();
void playerCollition(Car& car, Obstacle& osbtacle);
bool bulletCar();
