
/*
Imagine we are using a two-dimensional array as the basis for creating the game battle- ship. In the game of battleship a �~� character entry in the array represents ocean
(i.e., not a ship), a �#� character represents a place in the ocean where part of a ship is present, and a �H� character represents a place in the ocean where part of a ship
is present and has been hit by a torpedo. Thus, a ship with all �H� characters means the ship has been sunk. Declare a two-dimensional char array that is 25 by 25 that represents
the entire ocean and an If statement that prints �HIT� if a torpedo hits a ship given the coordinates X and Y. Write a C++ program that will read in a file representing a game
board with 25 lines where each line has 25 characters corresponding to the description above.

You should write a function called fire() that will take an X and Y coordinate and print �HIT� if a ship is hit and �MISS� if a ship is missed. If a ship is HIT you should
update the array with an �H� character to indicate the ship was hit. If a ship is hit that has already been hit at that location you should print �HIT AGAIN�. You should write
a second function called fleetSunk that will determine if all the ships have been sunk. Your C++ program must then call these functions until all the ships have been sunk at
which point the program should display �The fleet was destroyed!�.

Your game loop logic (the main logic of a game) should like like the following:

do {
fire(x, y, gameBoard);
} while(!fleetSunk(gameBoard));
*/

//Include Statments
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
void fire(int, int, char[25][25]);
int fleetSunk(char[25][25]);
void printBoard(char[25][25]);

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Jimmy Ortiz -- Lab 8" << endl << endl;

	//Variable declarations
	int x, y;
	char gameBoard[25][25];
	ifstream in;

	//Program logic
	in.open("input.dat");
	for (int x = 0; x < 25; x++)
	{
		for (int y = 0; y < 25; y++)
		{
			in >> gameBoard[x][y];
		}
	}

	//Game Loop Logic
	do {
		cout << "Enter row [1 - 25] : ";
		cin >> x;
		cout << "Enter column [1 - 25] : ";
		cin >> y;
		fire(x, y, gameBoard);
	} while (!fleetSunk(gameBoard));
	cout << "The fleet was destroyed!" << endl;

	//Closing program statements
	
	return 0;
}

//Function Definitions
void printBoard(char gameBoard[25][25])
{
	for (int x = 0; x < 25; x++)
		cout << x % 10;
	for (int x = 0; x < 25; x++)
	{
		for (int y = 0; y < 25; y++)
		{
			cout << gameBoard[x][y];
		}
	}
}

void fire(int x, int y, char gameBoard[25][25])
{
	if (gameBoard[x][y] == '~')
	{
		cout << "MISS" << endl;
	}
	else if (gameBoard[x][y] == '#')
	{
		cout << "HIT" << endl;
		gameBoard[x][y] = 'H';
	}
	else if (gameBoard[x][y] == 'H')
	{
		cout << "HIT AGAIN" << endl;
	}
	cout << endl;
}

int fleetSunk(char gameBoard[25][25])
{
	int ret = 1;
	for (int row = 0; row < 25; row++)
	{
		for (int col = 0; col < 25; col++)
		{
			if (gameBoard[row][col] == '#')
			{
				ret = 0;
				break;
			}
		}
	}
	return ret;
}

