#pragma once
#include <iostream>
#include <raylib.h>
#include "Game.h"
#include "Car.h"
#include "MainMenu.h"
#include "Obstacle.h"
#include "Parallax.h"
#include "SpaceShips.h"

SpaceShips spaceShip;
Car car;
Obstacle obstacle;
MenuScenes menu;
Buttons Texto[3];
 Parallax foreGround[2];
Parallax backGround[2];

float scrollingBack;
float scrollingMid;
int framesCounter;

int main(void)
{
	const int screenWidth = 540;
	const int screenHeight = 810;
	InitWindow(screenWidth, screenHeight, "MoonPatrol");

	Texture2D background = LoadTexture("resources/CloudTexture.png");
	Texture2D foreground = LoadTexture("resources/TerrainTexture.png");
	
	SetTargetFPS(60);

	while (!WindowShouldClose()/*&& quit==true*/)
	{
		
			RunGame(/*background,*/ foreground);
		
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}


