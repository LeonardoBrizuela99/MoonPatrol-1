#include "Car.h"
#include <iostream>

void initializeCar()
{
	car.rec.x = GetScreenWidth() / 4 * 2;
	car.rec.y = GetScreenHeight() / 8 * 6;
	car.rec.width = 50;
	car.rec.height = 25;
	car.speed.x = 200;
	car.speed.y = 200;
	car.maxJump = 500;
	car.lives = 4;
	car.startingPoint.y = GetScreenHeight() / 8 * 6;
	car.canCollide = true;
	car.isJumping = true;

	car.bulletActive = false;
	car.bullet.x = car.rec.x;
	car.bullet.x = car.rec.y;
	car.bullet.width = 10;
	car.bullet.height = 10;


}

void playerInput()
{
	if (IsKeyPressed(KEY_ENTER))
	{
		bulletCar();
	}
	if (IsKeyDown(KEY_SPACE) && !car.isJumping)
	{
		car.speed.y = -600;
		car.isJumping = true;
	}
	if (IsKeyDown(KEY_LEFT))
	{
		car.speed.x = -200;
		 
	}
	else if (IsKeyDown(KEY_RIGHT))
	{
		car.speed.x = 200;

	}
	else if (!car.isJumping)
	{
		car.speed.x = 0;
	}

}

void playerMovement()
{
	car.rec.x += car.speed.x * GetFrameTime();
	car.rec.y += car.speed.y * GetFrameTime();

	if (car.isJumping)
	{
		car.speed.y += 1500 * GetFrameTime();
	}

	if (car.rec.y > GetScreenHeight() / 8 * 6)
	{
		car.speed.y = 0;
		car.isJumping = false;
	}

	if (car.rec.x < 0)
	{
		car.rec.x = 0;
	}
	if (car.rec.x > GetScreenWidth() - car.rec.width)
	{
		car.rec.x = GetScreenWidth() - car.rec.width;
	}
	if (car.bulletActive == true)
	{
		car.bullet.y -= 400 * GetFrameTime();
	}

	if (car.bullet.y <= 0)
	{

		car.bulletActive = false;
		car.bullet.x =car.rec.x+25;
		car.bullet.y = car.rec.y-10;
	}
}

void playerCollition(Car& car, Obstacle& osbtacle)
{
	if (CheckCollisionRecs(car.rec,obstacle.rec))
	{
		car.lives--;
		initializeObstacle();
		
	}
}

bool bulletCar()
{
	return car.bulletActive = true;
}
