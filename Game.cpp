#include "Game.h"


void RunGame(Texture2D& background, Texture2D& foreground)
{
	scenesSwitch(background, foreground);
}

void Update()
{
	framesCounter++;
	moveParallax();
	hasCollided();
	loseCondition();
	playerMovement();
	playerInput();
	moveObstacle();
}

void Drawing(Texture2D& background, Texture2D& foreground) 
{
	BeginDrawing();

	ClearBackground(RAYWHITE);
	//---------------------------------------------------------------------------
 	drawParallax(background, foreground);
	DrawText(TextFormat("LIVES: " "%i", car.lives), GetScreenWidth() - MeasureText(TextFormat("LIVES: " "%i", car.lives), 20), 2, 20, BLACK);//LIVES DRAWING
	DrawText("Version 0.1", 2, 2, 20, BLACK);//VERSION DRAWING
	//DrawRectangleRec(foreGround.rec, GREEN);//PARALLAX DRAWING
	DrawRectangleRec(car.rec, BLUE);//CAR DRAWING
	DrawRectangleRec(obstacle.rec, RED);//OBSTACLE DRAWING

	//---------------------------------------------------------------------------
	EndDrawing();

}

void UpdateMenu()
{
	checkPlay();
	checkCredits();
	checkQuit();
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

void initializeAll()
{
	framesCounter = 0;

	initializeParallax();
	initializeObstacle();
	initializeCar();
	initializeTexts();
}

void loseCondition()
{
	if (car.lives <= 0 && car.canCollide == true)
	{
		menu = MenuScenes::MainMenu;
	}
}