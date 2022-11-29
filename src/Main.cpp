#pragma once
#include <iostream>
//#include <raylib.h>
#include "..\libs\raylib\include\raylib.h"
#include "Game.h"
#include "objetos/Car.h"
#include "menu/MainMenu.h"
#include "objetos/Obstacle.h"
#include "parallax/Parallax.h"
#include "objetos/SpaceShips.h"

SpaceShips spaceShip;
Car car, carPlayer2;
Obstacle obstacle;
MenuScenes menu;
Buttons Texto[3];
 Parallax foreGround[2];
Parallax backGround[2];
bool salir;
float scrollingBack;
float scrollingMid;
int framesCounter;

int main(void)
{
	const int screenWidth = 540;
	const int screenHeight = 810;
	InitWindow(screenWidth, screenHeight, "MoonPatrol");

	Texture2D background = LoadTexture("CloudTexture.png");
	Texture2D foreground = LoadTexture("TerrainTexture.png");
	/*Texture2D rock = LoadTexture("smallrockchipped_640.png");
	Texture2D fish_1= LoadTexture("Fish.png");
	Texture2D fish_2 = LoadTexture("Fish.png");*/
	
	SetTargetFPS(60);

	while (!WindowShouldClose()&&salir==false)
	{
		
			RunGame(background, foreground/*, rock, fish_1, fish_2*/);

		
	}

	UnloadTexture(foreground);
	UnloadTexture(background);
	/*UnloadTexture(rock);
	UnloadTexture(fish_1);
	UnloadTexture(fish_2);*/
	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}


