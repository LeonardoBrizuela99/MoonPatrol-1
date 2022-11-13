#pragma once
#include "raylib.h" 

#include <String>

using namespace std;

enum class MenuScenes
{
	MainMenu,
	Play,
	Credits,
	Quit,
	Win,
	Lose
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

void scenesSwitch();
void initializeTexts();
void drawButtons();
void drawPlay();
void checkPlay();
void drawCredits();
void checkCredits();
void drawQuit();
void checkQuit();
void initializeAll();