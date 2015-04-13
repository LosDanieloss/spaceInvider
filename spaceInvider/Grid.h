#pragma once

#include <string>

class Grid
{
public:

	char board[42][46];
	int cols, rows;

	Grid();
	~Grid();
	void drawGrid(std::string *draw);
	void placeNewShoot(int position);
	int updateLook(bool move);
	void placeNewEnemy(int position);
};

