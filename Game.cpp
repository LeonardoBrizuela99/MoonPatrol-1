#include "Game.h"
#include <iostream>

bool pause = true;

void RunGame(Texture2D& background,Texture2D& foreground)
{
	scenesSwitch(background, foreground);
}

void Update()
{
	backMenu();
	if (IsKeyPressed('P') || IsKeyPressed('p') || IsKeyPressed(KEY_ESCAPE))
	{

		pause = !pause;

	}
	
	if (car.lives!=0)
	{
		
		if (pause == true)
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
	else
	{
		loseText();
	}
	
		

}

//void UpdateMultiPlayer()
//{
//	backMenu();
//	if (IsKeyPressed('P') || IsKeyPressed('p') || IsKeyPressed(KEY_ESCAPE))
//	{
//
//		pause = !pause;
//
//	}
//
//	if (car.lives != 0||carPlayer2.lives!=0)
//	{
//
//		if (pause == true)
//		{
//			framesCounter++;
//			moveParallax();
//			loseCondition();
//			playerMovement();
//			playerInput();
//			moveObstacle();
//			playerCollition(car, obstacle);
//			/*player2Collition(carPlayer2, obstacle);*/
//			CollitionSpaceship(car, spaceShip);
//			/*CollitionSpaceshipPlayer2(carPlayer2, spaceShip);*/
//			MoveSpaceShip();
//
//		}
//	}
//	else
//	{
//		loseText();
//		
//	}
//}

void Drawing(Texture2D& background, Texture2D& foreground) 
{
	BeginDrawing();

	ClearBackground(DARKBLUE);
	//---------------------------------------------------------------------------
	
 	drawParallax(background, foreground);
	DrawText(TextFormat("LIVES:%i", car.lives), GetScreenWidth() - MeasureText(TextFormat("LIVES:%i", car.lives), 20), 2, 20, WHITE);//LIVES DRAWING
	DrawText("Version 0.2", 2, 2, 20, WHITE);//VERSION DRAWING
	//DrawText(TextFormat("Points:%4i",car.points), 230,2, 20, WHITE);//VERSION DRAWING
	//DrawRectangleRec(foreGround.rec, GREEN);//PARALLAX DRAWING
	DrawRectangleRec(car.rec, BLUE);//CAR DRAWING
	DrawRectangleRec(obstacle.rec, RED);//OBSTACLE DRAWING
	//if (spaceShip.isDeath==false)
	//{
	//	DrawRectangleRec(spaceShip.pos, RED);//OBSTACLE DRAWING
	//}

	if (car.bulletActive == true)
	{
		DrawRectangle(static_cast<int>(car.bullet.x),
			static_cast<int>(car.bullet.y),
			static_cast<int>(car.bullet.width),
			static_cast<int>(car.bullet.height),
			RED);
	}

	loseText();

	//---------------------------------------------------------------------------
	EndDrawing();

}
//void DrawingMultiplayer(Texture2D& background,Texture2D& foreground)
//{
//	BeginDrawing();
//
//	ClearBackground(DARKBLUE);
//	//---------------------------------------------------------------------------
//	if (menu == MenuScenes::Credits)
//	{
//		CreditsWindow();
//	}
//
//	drawParallax(background, foreground);
//	//DrawText(TextFormat("LIVES:%i", car.lives), GetScreenWidth() - MeasureText(TextFormat("LIVES:%i", car.lives), 20), 2, 20, WHITE);//LIVES DRAWING
//	DrawText(TextFormat("LIVES:%i", carPlayer2.lives), GetScreenWidth() - MeasureText(TextFormat("LIVES:%i", carPlayer2.lives), 20), 2, 20, WHITE);//LIVES DRAWING
//	DrawText("Version 0.1", 2, 2, 20, WHITE);//VERSION DRAWING
//	DrawText(TextFormat("Points:%4i", car.points), 230, 2, 20, WHITE);//VERSION DRAWING
//	//DrawText(TextFormat("Points:%4i", carPlayer2.points), 200, 2, 20, WHITE);//VERSION DRAWING
//	//DrawRectangleRec(foreGround.rec, GREEN);//PARALLAX DRAWING
//	DrawRectangleRec(car.rec, BLUE);//CAR DRAWING
//	DrawRectangleRec(carPlayer2.rec, GREEN);//CAR DRAWING
//	DrawRectangleRec(obstacle.rec, RED);//OBSTACLE DRAWING
//	
//	if (spaceShip.isDeath == false)
//	{
//		DrawRectangleRec(spaceShip.pos, RED);//OBSTACLE DRAWING
//	}
//
//	if (car.bulletActive == true)
//	{
//		DrawRectangle(static_cast<int>(car.bullet.x),
//			static_cast<int>(car.bullet.y),
//			static_cast<int>(car.bullet.width),
//			static_cast<int>(car.bullet.height),
//			RED);
//	}
//
//	if (carPlayer2.bulletActive == true)
//	{
//		DrawRectangle(static_cast<int>(carPlayer2.bullet.x),
//			static_cast<int>(carPlayer2.bullet.y),
//			static_cast<int>(carPlayer2.bullet.width),
//			static_cast<int>(carPlayer2.bullet.height),
//			BLUE);
//	}
//	loseText();
//
//
//
//	//---------------------------------------------------------------------------
//	EndDrawing();
//
//}

void UpdateMenu()
{
	checkPlay();
	/*checkMultiPlayer();*/
	checkCredits();
	checkQuit();
}

void backMenu()
{
	if (IsKeyDown(KEY_E))
	{
		menu=MenuScenes::MainMenu;
			
	}
}

void loseText()
{

	if (car.lives == 0/*|| carPlayer2.lives == 0*/)
	{
		DrawText("GAME OVER", GetScreenWidth() / 2-150, GetScreenHeight() / 2-200, 50, BLACK);//VERSION DRAWING
		DrawText("(E) Exit", GetScreenWidth() / 2+125, GetScreenHeight() / 2-100, 25, BLACK);//VERSION DRAWING
		DrawText("(R) Restart", GetScreenWidth() / 2-150, GetScreenHeight() / 2-100, 25, BLACK);//VERSION DRAWING

		if (IsKeyDown(KEY_R))
		{
			initializeAll();
		}
	}

	//if (carPlayer2.lives == 0)
	//{
	//	DrawText("GAME OVER", GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 200, 50, BLACK);//VERSION DRAWING
	//	DrawText("(E) Exit", GetScreenWidth() / 2 + 125, GetScreenHeight() / 2 - 100, 25, BLACK);//VERSION DRAWING
	//	DrawText("(R) Restart", GetScreenWidth() / 2 - 150, GetScreenHeight() / 2 - 100, 25, BLACK);//VERSION DRAWING

	//	if (IsKeyDown(KEY_R))
	//	{
	//		initializeAll();
	//	}
	//}

	
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

void CreditsWindow()
{
	BeginDrawing();
	ClearBackground(BEIGE);
	DrawText("Fork: Felipe Berazain", GetScreenWidth()/2-260, GetScreenHeight() / 2 - 200, 45, BLACK);//VERSION DRAWING
	
	DrawText("Codigo continuado por: Leonardo Brizuela", GetScreenWidth() / 2 - 250, GetScreenHeight() / 2 - 100, 25, BLACK);//VERSION DRAWING
	DrawText("(B) Back", GetScreenWidth()/2-260, GetScreenHeight()/2+200, 25, BLACK);//VERSION DRAWING
	EndDrawing();

	if (IsKeyDown(KEY_B))
	{
		menu = MenuScenes::MainMenu;
	}


}

void loseCondition()
{
	if (car.lives <= 0 && car.canCollide == true)
	{
		
		loseText();
		
	}
	//if (carPlayer2.lives <=0 && carPlayer2.canCollide == true/*&& car.lives <= 0 && car.canCollide == true*/)
	//{
	//	loseText();
	//}
}