#pragma once
#include "objetos/Car.h"
#include "menu/MainMenu.h"
#include "objetos/Obstacle.h"
#include "parallax/Parallax.h"
#include"objetos/SpaceShips.h"
#include "..\libs\raylib\include\raylib.h"

struct Game
{
};

extern int framesCounter;

void Update();
void UpdateMenu();
void Drawing(Texture2D& background, Texture2D& foreground/*, Texture2D& rock, Texture2D& fish_1*/);
void DrawingMultiplayer(Texture2D& background, Texture2D& foreground/*,Texture2D& rock, Texture2D& fish_1, Texture2D& fish_2*/);

void RunGame(Texture2D& background, Texture2D& foreground/*, Texture2D& rock, Texture2D& fish_1, Texture2D& fish_2*/);
//bool Pause();
//void hasCollided();
void UpdateMultiPlayer();
void CreditsWindow();


void loseText();
void loseCondition();
void initializeAll();
void backMenu();

