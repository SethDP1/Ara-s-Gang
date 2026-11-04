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
{
	//Slide left
	int temp[5]={0};
	int pos=0;

	for(int i=0; i<size; i++)
	{
		if(row[i]!=0)
		{
			temp[pos++]=row[i];
		}	
	}

	//Merge
	for(int i=0; i<size-1; i++)
	{
		if(temp[i]!=0 && temp[i]==temp[i+1])
		{
			temp[i]=temp[i]*2;
					temp[i+1]=1;
		}	
	}

	//Slide again after merge
	int result[5]={0};
	pos=0;

	for(int i=0; i<size; i++)
	{
		if(temp[i]!=0)
		{
			result[pos++]=temp[i];
		}	
	}	

	//Copy back
	for(int i=0; i<size; i++)
	{
		row[i]=result[i];
	}	
}

void move_left(int board[][5], int numrows = 5) //move left as normal
{
	for(int r=0; r<numrows; r++)
	{
		process_row_left(board[r],5);
	}	
}

void move_right(int board[][5], int numrows = 5) //reverse the row, process left, then reverse back
{
	for(int r=0; r<numrows; r++)
	{
		int temp[5];

		for(int c=0; c<5; c++)
		{
			temp[c]=board[r][4-c];		
		}

		process_row_left(temp, 5);

		for(int c=0; c<5; c++)
		{
			board[r][4-c]=temp[c];		
		}	
	}		
}

void move_up(int board[][5], int numrows = 5) //treat each column as a row moving left
{
	int temp[5];

	for(int r=0; r<numrows; r++)
	{
		temp[r]=board[r][c];
	}	

	process_row_left(temp, numrows);

	for(int r=0; r<numrows; r++)
	{
		board[r][c]=temp[r];
	}	
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
