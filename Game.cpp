#include "Game.h"


void RunGame()
{
	scenesSwitch();
}

void Update()
{
	framesCounter++;
	hasCollided();
	loseCondition();
	playerMovement();
	playerInput();
	moveObstacle();
	checkPlay();
	checkCredits();
	checkQuit();
}

void Drawing()
{
	BeginDrawing();

	ClearBackground(RAYWHITE);
	//---------------------------------------------------------------------------
	DrawText(TextFormat("LIVES: " "%i", car.lives), GetScreenWidth() - MeasureText(TextFormat("LIVES: " "%i", car.lives), 20), 2, 20, BLACK);//LIVES DRAWING
	DrawText("Version 0.1", 2, 2, 20, BLACK);//VERSION DRAWING
	DrawRectangleRec(parallax.rec, GREEN);//PARALLAX DRAWING
	DrawRectangleRec(car.rec, BLUE);//CAR DRAWING
	DrawRectangleRec(obstacle.rec, RED);//OBSTACLE DRAWING

	//---------------------------------------------------------------------------
	EndDrawing();

}

void play()
{


}

void hasCollided()
{
	if (((framesCounter / 240) % 2) == 1)
	{
		car.canCollide = true;
		framesCounter = 0;
	}

	if (CheckCollisionRecs(car.rec, obstacle.rec) && car.canCollide == true)
	{
		car.canCollide = false;
		car.lives--;
	}
}

void loseCondition()
{
	if (car.lives <= 0 && car.canCollide == true)
	{
		menu = MenuScenes::MainMenu;
	}
}