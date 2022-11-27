#include "SpaceShips.h"
//#include"Car.h"
#include <iostream>


using namespace std;

void initializeSpaceShip()
{
	spaceShip.pos.x = 0;
	spaceShip.pos.y =  GetScreenHeight() / 8 * 6 - 400;
	spaceShip.pos.width = 30;
	spaceShip.pos.height = 30;
	spaceShip.isDeath = false;

}

void MoveSpaceShip()
{
	spaceShip.pos.x += 100 * GetFrameTime();
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
