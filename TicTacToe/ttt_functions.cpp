#include <iostream>
#include <vector>

int boardWidth = 3;
int boardHeight = 3;

std::vector<char> r1{ 'X', 'X', 'X' };
std::vector<char> r2{ 'O', 'O', 'O' };
std::vector<char> r3{ 'X', 'X', 'X' };
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
