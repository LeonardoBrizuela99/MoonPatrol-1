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
	int points;
};
extern Car car, carPlayer2;
//extern Car carPlayer2;


void initializeCar();
void playerInput();
void playerMovement();
void playerCollition(Car& car, Obstacle& osbtacle);
void player2Collition(Car& carPlayer2, Obstacle& osbtacle);

//bool bulletCar();
