#include "Car.h"
#include <iostream>
void initializeCar()
{
	car.rec.x = GetScreenWidth() / 4.0f * 2.0f;
	car.rec.y = GetScreenHeight() / 8.0f * 6.0f;
	car.rec.width = 50;
	car.rec.height = 25;
	car.speed.x = 200;
	car.speed.y = 200;
	car.maxJump = 500;
	car.lives = 4;
	car.startingPoint.y = GetScreenHeight() / 8.0f * 6.0f;
	car.canCollide = true;
	car.isJumping = true;
	car.points = 0;

	car.bulletActive = false;
	car.bullet.x = car.rec.x;
	car.bullet.x = car.rec.y;
	car.bullet.width = 10;
	car.bullet.height = 10;

	carPlayer2.rec.x = GetScreenWidth() / 4.0f * 2.0f;
	carPlayer2.rec.y = GetScreenHeight() / 8.0f* 6.0f;
	carPlayer2.rec.width = 50;
	carPlayer2.rec.height = 25;
	carPlayer2.speed.x = 200;
	carPlayer2.speed.y = 200;
	carPlayer2.maxJump = 500;
	carPlayer2.lives = 4;
	carPlayer2.startingPoint.y = GetScreenHeight() / 8.0f* 6.0f;
	carPlayer2.canCollide = true;
	carPlayer2.isJumping = true;
	carPlayer2.points = 0;
	  
	carPlayer2.bulletActive = false;
	carPlayer2.bullet.x = car.rec.x;
	carPlayer2.bullet.x = car.rec.y;
	carPlayer2.bullet.width = 10;
	carPlayer2.bullet.height = 10;

}

void playerInput()
{
	if (IsKeyPressed(KEY_UP))
	{
		if (car.bulletActive == false)
		{
			car.bullet.x = car.rec.x + 25;
		}

		car.bulletActive = true;

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

	if (IsKeyPressed(KEY_W))
	{
		if (carPlayer2.bulletActive == false)
		{
			carPlayer2.bullet.x = carPlayer2.rec.x + 25;
		}

		carPlayer2.bulletActive = true;		

	}
	if (IsKeyDown(KEY_ENTER) && !carPlayer2.isJumping)
	{
		carPlayer2.speed.y = -600;
		carPlayer2.isJumping = true;
	}
	if (IsKeyDown(KEY_A))
	{
		carPlayer2.speed.x = -200;
		 
	}
	else if (IsKeyDown(KEY_D))
	{
		carPlayer2.speed.x = 200;

	}
	else if (!carPlayer2.isJumping)
	{
		carPlayer2.speed.x = 0;
	}

}

void playerMovement()
{
	car.rec.x += car.speed.x * GetFrameTime();
	car.rec.y += car.speed.y * GetFrameTime();

	carPlayer2.rec.x += carPlayer2.speed.x * GetFrameTime();
	carPlayer2.rec.y += carPlayer2.speed.y * GetFrameTime();

	if (car.bulletActive == true)
	{
		car.bullet.y -=800*GetFrameTime();
	}

	if (car.bullet.y <= 0)
	{

		car.bulletActive = false;
		car.bullet.x = car.rec.x + 25;
		car.bullet.y = car.rec.y+60*GetFrameTime();
	}	
	if (car.isJumping)
	{	
		car.speed.y += 1500* GetFrameTime();
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
	if (car.rec.x > GetScreenWidth() -car.rec.width)
	{								 
		car.rec.x = GetScreenWidth() -car.rec.width;
	}





	if (carPlayer2.bulletActive == true)
	{
		carPlayer2.bullet.y -= 800 * GetFrameTime();
	}

	if (carPlayer2.bullet.y <= 0)
	{

		carPlayer2.bulletActive = false;
		carPlayer2.bullet.x = carPlayer2.rec.x + 25;
		carPlayer2.bullet.y = carPlayer2.rec.y + 60 * GetFrameTime();
	}
	if (carPlayer2.isJumping)
	{
		carPlayer2.speed.y += 1500 * GetFrameTime();
	}
	if (carPlayer2.rec.y > GetScreenHeight() / 8 * 6)
	{
		carPlayer2.speed.y = 0;
		carPlayer2.isJumping = false;
	}

	if (carPlayer2.rec.x < 0)
	{
		carPlayer2.rec.x = 0;
	}
	if (carPlayer2.rec.x > GetScreenWidth() - carPlayer2.rec.width)
	{
		carPlayer2.rec.x = GetScreenWidth() - carPlayer2.rec.width;
	}

	
}

void playerCollition(Car& car, Obstacle& osbtacle)
{
	if (CheckCollisionRecs(car.rec,obstacle.rec))
	{
		car.lives--;
		initializeObstacle();
		
	} 
	else if(car.isJumping==true&& obstacle.collition==false&&obstacle.rec.x<=car.rec.x && obstacle.rec.y <= car.rec.y)
	{
		car.points += 20;
	}
}

//bool bulletCar()
//{
//	return car.bulletActive = true;
//}
