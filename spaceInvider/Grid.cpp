#include "stdafx.h"
#include "Grid.h"
#include <iostream>

Grid::Grid()
{
	rows = 41;
	cols = 45;
	for (int i = 0; i <= rows; i++)
		 for(int j = 0; j <= cols; j++)
			board[i][j] = ' ';
	board[30][10] = 'x';
}


Grid::~Grid()
{
}

void Grid::drawGrid(std::string *draw){
	for (int i = 0; i <= rows; i++){
		if (i != 0)
			draw->append(sizeof(char), '\n');
		for (int j = 0; j <= cols; j++)
			draw->append(sizeof(char),board[i][j]);
	}
	draw->append(sizeof(char), '\n');
}

void Grid::placeNewShoot(int position){
	board[rows][position] = '|';
}

int Grid::updateLook(bool move){

	if (move)
	for (int i = rows; i >= 0; i--){
		for (int j = cols; j >= 0; j--){
			if (board[i][j] == 'x' && i < rows){
				board[i][j] = ' ';
				board[i + 1][j] = 'x';
			}
			else if (board[i][j] == 'x' && i == rows){
				board[i][j] = ' ';
				return -1;
			}
		}
	}

	for (int i = 0; i <= rows; i++){
		for (int j = 0; j <= cols; j++){
			if (board[i][j] == '*'){
				board[i][j] = ' ';
			}
			if (board[i][j] == '|' && i > 0){
				board[i][j] = ' ';
				if (board[i - 1][j] == 'x'){
					board[i - 1][j] = '*';
					return 5;
				}
					
				else
					board[i - 1][j] = '|';
			}
			if (board[i][j] == '|' && i == 0)
				board[i][j] = ' ';
		}
	}
	return 0;
}

void Grid::placeNewEnemy(int position){
	board[0][position] = 'x';
}
