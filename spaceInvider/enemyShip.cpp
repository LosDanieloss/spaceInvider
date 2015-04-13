#include "stdafx.h"
#include "enemyShip.h"
#include <ctime>
#include <cstdlib>

enemyShip::enemyShip()
{
}


enemyShip::~enemyShip()
{
}

int enemyShip::newEnemyInOurSpace(int length){
	std::srand(std::time(0));
	int position = std::rand() % length;
	return position;
}
