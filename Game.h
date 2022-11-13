#pragma once
#include "Car.h"
#include "MainMenu.h"
#include "Obstacle.h"
#include "Parallax.h"
#include <raylib.h>

struct Game
{
};

extern int framesCounter;

void Update();
void Drawing(); 
void play();
void RunGame();
void hasCollided();
void loseCondition();