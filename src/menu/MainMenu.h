#pragma once
#include "..\..\libs\raylib\include\raylib.h"

#include <String>

using namespace std;

enum class MenuScenes
{
	MainMenu,
	Play,
	Multiplayer,
	Credits,
	Quit
};
extern MenuScenes menu;

struct Buttons
{
	string text{};
	Vector2 pos{};
	int fontSize{};

	Rectangle backgroundBttn{};
};
extern Buttons Texto[3];


extern bool salir;
void scenesSwitch(Texture2D& background, Texture2D& foreground/*,Texture2D& rock, Texture2D& fish_1, Texture2D& fish_2*/);
void initializeTexts();
void drawButtons();
void drawPlay();
void checkPlay();
void drawMultiPlayer();
void checkMultiPlayer();
void drawCredits();
void checkCredits();
void drawQuit();
void checkQuit();



