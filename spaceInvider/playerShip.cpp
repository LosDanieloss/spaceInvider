#include "stdafx.h"
#include "playerShip.h"
#include <iostream>

playerShip::playerShip()
{
	outfit = 'A';
	position = 22;
	health = 5;
}


playerShip::~playerShip()
{
}

void playerShip::drawShip(std::string *draw){
	char c = ' ';
	for (int i = 0; i < position; i++)
		draw->append(sizeof(char), c);
	draw->append(sizeof(char), outfit);
	draw->append(sizeof(char), '\n');
}

void playerShip::toTheLeft(){
	if (position > 0)
		position--;
}

void playerShip::toTheRight(){
	if (position < 45)
		position++;
}

int playerShip::shoot(){
	return position;
}