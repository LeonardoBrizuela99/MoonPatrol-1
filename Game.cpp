#include "Game.h"

bool pause = true;

void RunGame(/*Texture2D& background,*/ Texture2D& foreground)
{
	scenesSwitch(/*background,*/ foreground);
}

void Update()
{
	if (IsKeyPressed('P') || IsKeyPressed('p') || IsKeyPressed(KEY_ESCAPE))
	{

		pause = !pause;

	}
	
	if (pause==true)
	{
		framesCounter++;
		moveParallax();
		/*hasCollided();*/
		loseCondition();
		playerMovement();
		playerInput();
		moveObstacle();
		playerCollition(car, obstacle);
		CollitionSpaceship(car, spaceShip);
		MoveSpaceShip(/*spaceShip*/);

	}
		

}

void Drawing(/*Texture2D& background,*/ Texture2D& foreground) 
{
	BeginDrawing();

	ClearBackground(RAYWHITE);
	//---------------------------------------------------------------------------
 	drawParallax(/*background,*/ foreground);
	DrawText(TextFormat("LIVES:%i", car.lives), GetScreenWidth() - MeasureText(TextFormat("LIVES:%i", car.lives), 20), 2, 20, BLACK);//LIVES DRAWING
	DrawText("Version 0.1", 2, 2, 20, BLACK);//VERSION DRAWING
	DrawText(TextFormat("Points:%4i",car.points), 230,2, 20, BLACK);//VERSION DRAWING
	//DrawRectangleRec(foreGround.rec, GREEN);//PARALLAX DRAWING
	DrawRectangleRec(car.rec, BLUE);//CAR DRAWING
	DrawRectangleRec(obstacle.rec, RED);//OBSTACLE DRAWING
	if (spaceShip.isDeath==false)
	{
		DrawRectangleRec(spaceShip.pos, RED);//OBSTACLE DRAWING
	}

	if (car.bulletActive == true)
	{
		DrawRectangle(static_cast<int>(car.bullet.x),
			static_cast<int>(car.bullet.y),
			static_cast<int>(car.bullet.width),
			static_cast<int>(car.bullet.height),
			RED);
	}

	//---------------------------------------------------------------------------
	EndDrawing();

}

void UpdateMenu()
{
	checkPlay();
	checkCredits();
	checkQuit();
}




//void hasCollided()
//{
//	if (((framesCounter / 240) % 2) == 1)
//	{
//		car.canCollide = true;
//		framesCounter = 0;
//	}
//
//	if (CheckCollisionRecs(car.rec, obstacle.rec) && car.canCollide == true)
//	{
//		car.canCollide = false;
//		
//	}
//}

void initializeAll()
{
	framesCounter = 0;

	initializeParallax();
	initializeObstacle();
	initializeCar();
	initializeSpaceShip();
	initializeTexts();
}

void loseCondition()
{
	if (car.lives <= 0 && car.canCollide == true)
	{
		menu = MenuScenes::MainMenu;
		initializeAll();
	}
}