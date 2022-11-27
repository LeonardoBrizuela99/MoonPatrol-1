#include "MainMenu.h"
#include "Game.h"
#include <iostream>

 

void initializeTexts()
{
	Texto[0].text = "1PLAYER";
	Texto[0].fontSize = 40;
	Texto[0].pos.x = GetScreenWidth() / 2 - MeasureText(Texto[0].text.c_str(), 50) / 2.0f + 12;
	Texto[0].pos.y = 170;

	Texto[0].backgroundBttn.x = GetScreenWidth() / 2.0f- MeasureText(Texto[0].text.c_str(), 50) / 2;
	Texto[0].backgroundBttn.y = 163;
	Texto[0].backgroundBttn.width = static_cast<float>(MeasureText(Texto[0].text.c_str(), 50));
	Texto[0].backgroundBttn.height = 50;

	Texto[1].text = "2PLAYER";
	Texto[1].fontSize = 40;
	Texto[1].pos.x = GetScreenWidth() / 2 - MeasureText(Texto[0].text.c_str(), 50) / 2.0f + 5;
	Texto[1].pos.y = 50;

	Texto[1].backgroundBttn.x = GetScreenWidth() / 2.0f - MeasureText(Texto[0].text.c_str(), 50) / 2;
	Texto[1].backgroundBttn.y = 47;
	Texto[1].backgroundBttn.width = static_cast<float>(MeasureText(Texto[0].text.c_str(), 50));
	Texto[1].backgroundBttn.height = 50;

	Texto[2].text = "CREDITS";
	Texto[2].fontSize = 40;
	Texto[2].pos.x = GetScreenWidth() / 2 - MeasureText(Texto[1].text.c_str(), 50) / 2.0f+ 22;
	Texto[2].pos.y = 310;
		  
	Texto[2].backgroundBttn.x = GetScreenWidth() / 2.0f- MeasureText(Texto[1].text.c_str(), 50) / 2;
	Texto[2].backgroundBttn.y = 303;
	Texto[2].backgroundBttn.width = static_cast<float>(MeasureText(Texto[1].text.c_str(), 50));
	Texto[2].backgroundBttn.height = 50;


	Texto[3].text = "QUIT";
	Texto[3].fontSize = 40;
	Texto[3].pos.x = GetScreenWidth() / 2 - MeasureText(Texto[2].text.c_str(), 50) / 2.0f+ 13;
	Texto[3].pos.y = 380;
		  
	Texto[3].backgroundBttn.x = GetScreenWidth() / 2.0f- MeasureText(Texto[2].text.c_str(), 50) / 2;
	Texto[3].backgroundBttn.y = 373;
	Texto[3].backgroundBttn.width = static_cast<float>(MeasureText(Texto[2].text.c_str(), 50));
	Texto[3].backgroundBttn.height = 50;
}

void drawPlay()
{
	DrawRectangle(static_cast<int>(Texto[0].backgroundBttn.x), static_cast<int>(Texto[0].backgroundBttn.y), static_cast<int>(Texto[0].backgroundBttn.width), static_cast<int>(Texto[0].backgroundBttn.height), WHITE);
	DrawText(Texto[0].text.c_str(), static_cast<int> (Texto[0].pos.x), static_cast<int>(Texto[0].pos.y), static_cast<int> (Texto[0].fontSize), BLUE);
}

void checkPlay()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[0].backgroundBttn))
	{
		menu = MenuScenes::Play;
	}
}

void drawMultiPlayer()
{
	DrawRectangle(static_cast<int>(Texto[1].backgroundBttn.x), static_cast<int>(Texto[1].backgroundBttn.y), static_cast<int>(Texto[1].backgroundBttn.width), static_cast<int>(Texto[1].backgroundBttn.height), WHITE);
	DrawText(Texto[1].text.c_str(), static_cast<int> (Texto[1].pos.x), static_cast<int>(Texto[1].pos.y), static_cast<int> (Texto[1].fontSize), BLUE);
}

void checkMultiPlayer()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[1].backgroundBttn))
	{
		menu = MenuScenes::Multiplayer;
	}
}

void drawCredits()
{
	DrawRectangle(static_cast<int>(Texto[2].backgroundBttn.x), static_cast<int>(Texto[2].backgroundBttn.y), static_cast<int>(Texto[2].backgroundBttn.width), static_cast<int>(Texto[2].backgroundBttn.height), WHITE);
	DrawText(Texto[2].text.c_str(), static_cast<int>(Texto[2].pos.x), static_cast<int>(Texto[2].pos.y), static_cast<int>(Texto[2].fontSize), BLUE);
}

void checkCredits()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[2].backgroundBttn))
	{
		menu = MenuScenes::Credits;
	}
}

void drawQuit()
{
	DrawRectangle(static_cast<int>(Texto[3].backgroundBttn.x), static_cast<int>(Texto[3].backgroundBttn.y), static_cast<int>(Texto[3].backgroundBttn.width), static_cast<int>(Texto[3].backgroundBttn.height), WHITE);
	DrawText(Texto[3].text.c_str(), static_cast<int>(Texto[2].pos.x), static_cast<int>(Texto[3].pos.y), static_cast<int>(Texto[3].fontSize), RED);
}

void checkQuit()
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), Texto[3].backgroundBttn))
	{
		menu = MenuScenes::Quit;

	}
}

void drawButtons()
{
	BeginDrawing();
	ClearBackground(BEIGE);
	drawPlay();
	drawMultiPlayer();
	drawCredits();
	drawQuit();
	EndDrawing();
}

void scenesSwitch(Texture2D& background, Texture2D& foreground)
{
	switch (menu)
	{
	case MenuScenes::MainMenu:

		initializeAll();
		UpdateMenu();
		drawButtons();

		break;

	case MenuScenes::Play:
			
			Update();
			Drawing(background, foreground);

		break;

	case MenuScenes::Multiplayer:

		UpdateMultiPlayer();
		DrawingMultiplayer(background,foreground);
		/*Drawing(foreGround);*/
		break;

	case MenuScenes::Credits:

		
		CreditsWindow();
		
		break;

	case MenuScenes::Quit:

		 salir = true;
		

		break;

	
	}

}

/*bool Pause()
{
	if (IsKeyPressed('P') || IsKeyPressed('p') || IsKeyPressed(KEY_ESCAPE))
	{
		cout << pause << endl;
		return pause = !pause;

		//cout << pause << endl;
		//0 false
		//1 true
	}
}*/