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
void MoveSpaceShip();
void CollitionSpaceship(Car& car, SpaceShips& spaceShip);
void CollitionSpaceshipPlayer2(Car& carPlayer2, SpaceShips& spaceShip);
//


