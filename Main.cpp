#pragma once
#include <iostream>
#include <raylib.h>
#include "Game.h"
#include "Car.h"
#include "MainMenu.h"
#include "Obstacle.h"
#include "Parallax.h"

Car car;
Obstacle obstacle;
MenuScenes menu;
Buttons Texto[3];
Parallax parallax;
int framesCounter;

int main(void)
{
	const int screenWidth = 540;
	const int screenHeight = 810;
	InitWindow(screenWidth, screenHeight, "MoonPatrol");

	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		RunGame();
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}


