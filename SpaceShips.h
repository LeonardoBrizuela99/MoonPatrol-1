#pragma once
#include"raylib.h"
#include"Car.h"
struct SpaceShips
{
	Rectangle pos;
	bool isDeath;
};
extern SpaceShips spaceShip;

void initializeSpaceShip();
void MoveSpaceShip(/*SpaceShips& spaceShip*/);
void CollitionSpaceship(Car& car, SpaceShips& spaceShip);


