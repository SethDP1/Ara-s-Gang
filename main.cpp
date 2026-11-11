//main.cpp Responsibilities:
	//start the game
	//get user input
	//call movement functions from helper
	//print messages/menus
	//run until win, lose, or exit

#include <iostream>
#include "2048_helper.h"
using namespace std;

int main()
{
	int size = 5;
	int board[5][5] = {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
	};
	//while getch == x loop for up down left right

//the "print board" function is in the helper file
	cout << "Initial Board : [5x5] :" << endl;
	print_board(board);

	//Inserts two initial tiles in the board to start with
	insert_random(board,size);
	insert_random(board,size);
	print_board(board)

	char choice = 'u';	//initialized
	while (choice != 'e')
	{

		cout << "Please enter choice:{w,s,a,d,e} for UP, DOWN, LEFT, RIGHT, Exit: " << endl;
		cout << "Choice: ";
		cin >> choice;

//PROCESS

		if (choice == 'e')
			break;
		
		if (choice == 'w')
			move_up(board, size);
		else if (choice == 's')
			move_down(board, size);
		else if (choice == 'a')
			move_left(board, size);
		else if (choice == 'd')
			move_right(board, size);

		insert_random(board, size);
		print_board(board);

	}


	return 0;
}
