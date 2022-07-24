#include <iostream>
#include <vector>
#include "ttt_functions.h"

int main()
{
	//Print the board
	// a ttt board is a 2D matrix of size 3
	// 3 arrays of size 3 within on array
	// Rows and columns 0-2
	printBoard();

	// printBoard() could maybe go at the beginning of every turn
	// instead of calling it multiple times in main()

	
	// Vectore for tiles used
	std::vector<std::vector<int>> tilesUsed;

	// Receive input
	int input1 = 0;
	int input2 = 0;

	std::cout << "Please input row: ";
	std::cin >> input1;
	std::cout << "Please input column: ";
	std::cin >> input2;

	// Check against used tiles vector
	std::vector<int> tempVector;
	tempVector.push_back(input1);
	tempVector.push_back(input2);

	for (int i = 0; i < tempVector.size(); i++)
	{
		std::cout << tempVector[i];
	}

	// Compare input to used tiles

}