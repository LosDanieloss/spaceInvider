#pragma once

#include <string>

class playerShip
{
public:

	char outfit;
	int position;
	int health;

	playerShip();
	~playerShip();
	void drawShip(std::string* draw);
	void toTheLeft();
	void toTheRight();
	int shoot();
};

