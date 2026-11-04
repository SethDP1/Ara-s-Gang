//helper.h Responsibilities:
	//modify the board
	//check game rules
	//save/load data

#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

//MOVEMENT
//Seth is working on movement

//Helper function for moving left one row
void process_row_left(int row[], int size)

void move_left(int board[][5], int numrows = 5) //move left as normal
{
	//Slide left
	
	//Merge
	
}

void move_right(int board[][5], int numrows = 5) //reverse the row, process left, then reverse back
{
	//Slide right
	
	//Merge
	
}

void move_up(int board[][5], int numrows = 5) //treat each column as a row moving left
{
	//Slide up
	
	//Merge
	
}

void move_down(int board[][5], int numrows = 5) //Reverse the column, process left, then reverse back
{
	//Slide down
	
	//Merge
	
}

//PRINT BOARD
void print_board(int board[][5], int numrows = 5)
{
	cout << endl << "\t-----------------------------------------" << endl;

	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			if(board[r][c] > 0)
				cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
			else
				cout << "\t|" << right << setw(6) << setfill(' ') << " ";

			//cout << board[r][c] << "\t|\t";
		}
		cout << "\t|" << endl;
		cout << "\t-----------------------------------------" << endl;
	}

	cout << "\t" << endl << endl;
}

//TILE INSERTION
void insert_random(int board[][5], int numrows = 5)
{
	int r, c;
	//count empty
	int empty_count = 0;
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			if (board[r][c] == 0)
				empty_count++;
		}
	}

	if (empty_count > 0)
	{
		while (true)
		{
			//generate random location r, c
			r = rand() % numrows;
			c = rand() % numrows;
			//check if empty
			if (board[r][c] == 0)
			{
				//add number randomly {2,4}
				board[r][c] = 2 * (1 + (rand() % 2));
				break;
			}
		}

	}
}

//VALIDATION FOR MOVEMENT AND CHECKING FOR WIN/LOSS


//SCORE CALCULATION
