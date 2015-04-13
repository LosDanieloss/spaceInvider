// spaceInvider.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "playerShip.h"
#include "enemyShip.h"
#include "Grid.h"
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <string>
#include <iostream>

void prepareConsoleView(){
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	// max chars is 45
	MoveWindow(console, r.left + 400, r.top, 600, 600, true);
}

int _tmain(int argc, _TCHAR* argv[])
{
	prepareConsoleView();

	HANDLE current = GetStdHandle(STD_OUTPUT_HANDLE);

	HANDLE buffer = CreateConsoleScreenBuffer(
		GENERIC_WRITE,
		0,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL
		);

	playerShip *ship = new playerShip();
	enemyShip *enemy = new enemyShip();
	Grid *grid = new Grid();
	int points = 0;
	bool first = true;
	int cntr = 0;

	
	std::srand(std::time(0));
	int randomNumb = 0; 
	unsigned long written = 0;

	while ( ship->health > 0){
		
		std::string draw;
		int tmpPoints = 0;

		grid->drawGrid(&draw);
		ship->drawShip(&draw);

		if (_kbhit()){

			int key = _getch();
			if (key == 97 || key == 75){
				// to the left
				ship->toTheLeft();
			}
			else if (key == 100 || key == 77 ){
				// to the right
				ship->toTheRight();
			}
			else if (key == 32){
				grid->placeNewShoot(ship->shoot());
			}
			else if (key == 27){
				// ESC to quite the game
				break;
			}			
		}

		if (cntr == 10){
			randomNumb = std::rand() % 10;
			if (randomNumb < 4){
				grid->placeNewEnemy(enemy->newEnemyInOurSpace(grid->cols));
			}
		}
		if (cntr == 10)
			tmpPoints = grid->updateLook(true);
		else
		{
			tmpPoints = grid->updateLook(false);
		}

		if (tmpPoints == -1)
			ship->health--;
		else
		points += tmpPoints;

		draw.append("	POINTS: ");
		std::string spoint = std::to_string(points);
		draw.append(spoint);

		draw.append("				Health: ");
		std::string shealth = std::to_string(ship->health);
		draw.append(shealth);

		const char *nap = draw.c_str();

		if (first){
			WriteConsoleA(current, nap, strlen(nap), &written, NULL);
			system("cls");
			SetConsoleActiveScreenBuffer(current);
			first != first;
		}
		else{
			WriteConsoleA(buffer, nap, strlen(nap), &written, NULL);
			system("cls");
			SetConsoleActiveScreenBuffer(buffer);
			first != first;
		}

		cntr = ++cntr % 11;
	}

	std::cout << "=========================================" << std::endl
		<< "============== GAMER OVER ===============" << std::endl
		<< "=========================================" << std::endl;

	std::cout << "You finished with " << points << " points." << std::endl;

	system("pause");
	delete(ship);
	delete(enemy);
	delete(grid);
	return 0;
}

