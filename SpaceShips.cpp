#include "SpaceShips.h"
//#include"Car.h"
#include <iostream>


using namespace std;

void initializeSpaceShip()
{
	spaceShip.pos.x = 0;
	spaceShip.pos.y =  GetScreenHeight() / 8.0f * 6.0f - 400.0f;
	spaceShip.pos.width = 30.0f;
	spaceShip.pos.height = 30.0f;
	spaceShip.isDeath = false;

}

void MoveSpaceShip()
{
	spaceShip.pos.x += 100.0f * GetFrameTime();
	spaceShip.pos.y -= sin(spaceShip.pos.x / 10) * GetFrameTime() * 600.0f;

	if (spaceShip.pos.x>=GetScreenWidth()+spaceShip.pos.width*2&&spaceShip.isDeath==false)
	{
		initializeSpaceShip();
	}
	if (spaceShip.isDeath==true)
	{
		initializeSpaceShip();
	}
}

void CollitionSpaceship(Car& car,SpaceShips& spaceShip)
{
	if (CheckCollisionRecs(car.bullet,spaceShip.pos))
	{
		
		spaceShip.isDeath = true;
		car.points += 100;
		cout << spaceShip.isDeath << endl;
	}
}

void CollitionSpaceshipPlayer2(Car& carPlayer2, SpaceShips& spaceShip)
{
	if (CheckCollisionRecs(carPlayer2.bullet, spaceShip.pos))
	{

		spaceShip.isDeath = true;
		carPlayer2.points += 100;
		cout << spaceShip.isDeath << endl;
	}
}