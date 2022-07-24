#include <iostream>
#include <vector>
#include "ttt_functions.h"

int main()
{
	while (winCondition() != true)
	{
		turn();
	}
	printBoard();

}