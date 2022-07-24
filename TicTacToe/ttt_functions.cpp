#include <iostream>
#include <vector>

int boardWidth = 3;
int boardHeight = 3;

bool p1Turn = true;

std::vector<char> r1{ ' ', ' ', ' ' };
std::vector<char> r2{ ' ', ' ', ' ' };
std::vector<char> r3{ ' ', ' ', ' ' };
std::vector<std::vector<char>> mainVector{ r1, r2, r3 };

void printRow(std::vector<char> row)
{
	for (int i = 0; i < row.size(); i++)
	{
		std::cout << row[i] << " ";
		if (i <= 2)
		{
			std::cout << "| ";
		}
	}
	std::cout << "\n";
}

void printBoard()
{
	for (int i = 0; i < boardHeight; i++)
	{
		printRow(mainVector[i]);
	}
}

bool winCondition()
{
	// Horizontal win conditions
	if ((mainVector[0][0] == 'X') && (mainVector[0][1] == 'X') && (mainVector[0][2] == 'X'))
	{
		std::cout << "P1 Wins\n";
		return true;
	}
	if ((mainVector[1][0] == 'X') && (mainVector[1][1] == 'X') && (mainVector[1][2] == 'X'))
	{
		std::cout << "P1 Wins\n";
		return true;
	}
	if ((mainVector[2][0] == 'X') && (mainVector[2][1] == 'X') && (mainVector[2][2] == 'X'))
	{
		std::cout << "P1 Wins\n";
		return true;
	}
	if ((mainVector[0][0] == 'O') && (mainVector[0][1] == 'O') && (mainVector[0][2] == 'O'))
	{
		std::cout << "P2 Wins\n";
		return true;
	}
	if ((mainVector[1][0] == 'O') && (mainVector[1][1] == 'O') && (mainVector[1][2] == 'O'))
	{
		std::cout << "P2 Wins\n";
		return true;
	}
	if ((mainVector[2][0] == 'O') && (mainVector[2][1] == 'O') && (mainVector[2][2] == 'O'))
	{
		std::cout << "P2 Wins\n";
		return true;
	}

	// Vertical win conditions
	if ((mainVector[0][0] == 'X') && (mainVector[1][0] == 'X') && (mainVector[2][0] == 'X'))
	{
		std::cout << "P1 Wins\n";
		return true;
	}
	if ((mainVector[0][1] == 'X') && (mainVector[1][1] == 'X') && (mainVector[2][1] == 'X'))
	{
		std::cout << "P1 Wins\n";
		return true;
	}
	if ((mainVector[0][2] == 'X') && (mainVector[1][2] == 'X') && (mainVector[2][2] == 'X'))
	{
		std::cout << "P1 Wins\n";
		return true;
	}
	if ((mainVector[0][0] == 'O') && (mainVector[1][0] == 'O') && (mainVector[2][0] == 'O'))
	{
		std::cout << "P2 Wins\n";
		return true;
	}
	if ((mainVector[0][1] == 'O') && (mainVector[1][1] == 'O') && (mainVector[2][1] == 'O'))
	{
		std::cout << "P2 Wins\n";
		return true;
	}
	if ((mainVector[0][2] == 'O') && (mainVector[1][2] == 'O') && (mainVector[2][2] == 'O'))
	{
		std::cout << "P2 Wins\n";
		return true;
	}

	// Diagonal win conditions
	if ((mainVector[0][0] == 'X') && (mainVector[1][1] == 'X') && (mainVector[2][2] == 'X'))
	{
		std::cout << "P1 Wins\n";
		return true;
	}
	if ((mainVector[0][2] == 'X') && (mainVector[1][1] == 'X') && (mainVector[2][0] == 'X'))
	{
		std::cout << "P1 Wins\n";
		return true;
	}
	if ((mainVector[0][0] == 'O') && (mainVector[1][1] == 'O') && (mainVector[2][2] == 'O'))
	{
		std::cout << "P2 Wins\n";
		return true;
	}
	if ((mainVector[0][2] == 'O') && (mainVector[1][1] == 'O') && (mainVector[2][0] == 'O'))
	{
		std::cout << "P2 Wins\n";
		return true;
	}

	// Board is full condition
	for (int i = 0; i < mainVector.size(); i++)
	{
		for (int j = 0; j < mainVector[0].size(); j++)
			if (mainVector[i][j] == ' ')
			{
				return false;
			}
	}
	std::cout << "It's a tie!";
	return true;	
}

void turn()
{
	printBoard();

	if (p1Turn)
	{
		std::cout << "Player 1's turn.\n";
	}
	else
	{
		std::cout << "Player 2's turn.\n";
	}

	// Receive input
	int input1 = 0;
	int input2 = 0;

	std::cout << "Please input row: ";
	std::cin >> input1;
	while (input1 < 1 || input1 > 3)
	{
		std::cout << "Choice out of range";
		std::cout << "input row: ";
		std::cin >> input1;
	}
	// Decrement so non computer users can use 123 for row/column selection
	input1--;
	std::cout << "Please input column: ";
	std::cin >> input2;
	while (input2 < 1 || input2 > 3)
	{
		std::cout << "Choice out of range";
		std::cout << "input row: ";
		std::cin >> input2;
	}
	input2--;

	// while tile isn't blank, ask to choose new tile

	while (mainVector[input1][input2] != ' ')
	{
		std::cout << "Tile taken, please try again.\n";
		std::cout << "Input row: ";
		std::cin >> input1;
		input1--;
		std::cout << "Input column: ";
		std::cin >> input2;
		input2--;
	}

	// if p1's turn, place 'X' in tile
	if (p1Turn)
	{
		mainVector[input1][input2] = 'X';
	}
	else
	{
		mainVector[input1][input2] = 'O';
	}
	
	// if p1's turn, now p2's turn
	if (p1Turn)
	{
		p1Turn = false;
	}
	else
	{
		p1Turn = true;
	}
}
