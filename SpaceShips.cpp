#include "SpaceShips.h"
#include <iostream>

void initializeSpaceShip()
{
	spaceShip.pos.x = 1;
	spaceShip.pos.y = -10;
	spaceShip.pos.width = 10;
	spaceShip.pos.height = 10;
	spaceShip.isDeath = false;

}

void MoveSpaceShip(SpaceShips& spaceShip)
{
	spaceShip.pos.x -=10*GetFrameTime();
	spaceShip.pos.y += sin(spaceShip.pos.x / 10) * GetFrameTime();
}

void CollitionSpaceship()
{
}
