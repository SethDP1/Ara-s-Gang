//main.cpp Responsibilities:
	//start the game
	//get user input
	//call movement functions from helper
	//print messages/menus
	//run until win, lose, or exit

#include <iostream>
#include <ctime>
#include "2048_helper.h"
using namespace std;

int main()
{
	srand(time(0));
	
	int size = 5;
	int board[5][5] = {
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
	};
	//while getch == x loop for up down left right

//Inserts two initial tiles in the board to start with
	insert_random(board,size);
	insert_random(board,size);
	
//the "print board" function is in the helper file
	cout << "Initial Board : [5x5] :" << endl;
	print_board(board)

	char choice = 'u';	//initialized
	while (choice != 'e')
	{
		int old_board[5][5];
		for(int r=0; r<size; r++)
		{
			for(int c=0; c<size; c++)
			{
				old_board[r][c]=board[r][c];
			}	
		}		

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

		if(!boards_are_equal(board,old_board,size))
		{
			insert_random(board,size);
		}	

		print_board;

		if(check_win(board,size))
		{
			cout<<"You Win!"<<endl;
			break;
		}	

		if(check_loss(board,size))
		{
			cout<<"Game Over!<<endl;
			break;	
		}	
	}


	return 0;
}
