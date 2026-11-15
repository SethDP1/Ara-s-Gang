//helper.h Responsibilities:
	//modify the board
	//check game rules
	//save/load data

#include <iostream>
#include <cstdlib>

#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

//MOVEMENT(DONE)
//Seth is working on movement

//Helper function for moving left one row
void process_row_left(int row[], int size, int& score)
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

			score=score+temp[i];
			
			temp[i+1]=0;
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

void move_left(int board[][5], int& score, int numrows = 5) //move left as normal
{
	for(int r=0; r<numrows; r++)
	{
		process_row_left(board[r],numrows,score);
	}	
}

void move_right(int board[][5], int& score, int numrows = 5) //reverse the row, process left, then reverse back
{
	for(int r=0; r<numrows; r++)
	{
		int temp[5];

		for(int c=0; c<numrows; c++)
		{
			temp[c]=board[r][numrows-1-c];		
		}

		process_row_left(temp, numrows, score);

		for(int c=0; c<5; c++)
		{
			board[r][numrows-1-c]=temp[c];		
		}	
	}		
}

void move_up(int board[][5], int& score, int numrows = 5) //treat each column as a row moving left
{
	for(int c=0; c<numrows; c++)
	{
		int temp[5];

		for(int r=0; r<numrows; r++)
		{
			temp[r]=board[r][c];
		}	

		process_row_left(temp, numrows, score);

		for(int r=0; r<numrows; r++)
		{
			board[r][c]=temp[r];
		}	
	}	
}

void move_down(int board[][5], int& score, int numrows = 5) //Reverse the column, process left, then reverse back
{
	for(int c=0; c<numrows; c++)
	{
		int temp[5];

		for(int r=0; r<numrows; r++)
		{
			temp[r]=board[numrows-1-r][c];
		}	

		process_row_left(temp, numrows, score);

		for(int r=0; r<numrows; r++)
		{
			board[numrows-1-r][c]=temp[r];
		}	
	}
}

//PRINT BOARD
void print_board(int board[][5], int numrows = 5)
{
	cout << endl << "\t-----------------------------------------" << endl;

	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < numrows; c++)
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
		for (int c = 0; c < numrows; c++)
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

//movement validation
bool boards_are_equal(int board1[][5], int board2[][5], int size=5)
{
	for(int r=0; r<size; r++)
	{
		for(int c=0; c<size; c++)
		{
			if(board1[r][c]!=board2[r][c])
			{
				return false;
			}	
		}	
	}

	return true;
}	

//win/loss check

bool check_win(int board[][5], int size=5)
{
	for(int r=0; r<size; r++)
	{
		for(int c=0; c<size; c++)
		{
			if(board[r][c]==2048)
			{
				return true;
			}	
		}
	}	
	return false;
}	

bool check_loss(int board[][5], int size=5)
{
	//check for empty spaces
	for(int r=0; r<size; r++)
	{
		for(int c=0; c<size; c++)
		{
			if(board[r][c]==0)
			{
				return false;
			}	
		}	
	}

	//check horizontal matches
	for(int r=0; r<size; r++)
	{
		for(int c=0; c<size-1; c++)
		{
			if(board[r][c]==board[r][c+1])
			{
				return false;
			}	
		}	
	}

	
	//check vertical matches
	for(int r=0; r<size-1; r++)
	{
		for(int c=0; c<size; c++)
		{
			if(board[r][c]==board[r+1][c])
			{
				return false;
			}	
		}	
	}

	return true;
}

//VALIDATION

bool valid_tile(int value)
{
	if(value==0)
	{
		return true;
	}	

	if(value<2)
	{
		return false;
	}

	while(value%2 == 0)
	{
		value=value/2;
	}

	return value==1;
}	

//SAVE GAME and LOAD GAME

void save_game(int board[][5], int size, int score)
{
	ofstream fout("savegame.txt");

	fout<<"CS211_2048_V1"<<endl;

	for(int r=0; r<size; r++)
	{
		for(int c=0; c<size; c++)
		{
			fout<<board[r][c]<<" ";
		}
		fout<<endl;
	}	

	fout.close();

	cout<<"Game Saved"<<endl;
}

bool load_game(int board[][5], int size, int& score)
{
	ifstream fin("savegame.txt");

    if(!fin)
    {
        cout<<"Error opening file."<<endl;
        return false;
    }

    string marker;
    int tempScore;
    int tempBoard[5][5];
    fin>>marker;

    if(marker!="CS211_2048_V1")
    {
        cout<<"Invalid save file."<<endl;
        return false;
    }

    if(!(fin>>tempScore))
    {
        cout<<"Invalid score."<<endl;
        return false;
    }

    if(tempScore<0)
    {
        cout<<"Invalid score."<<endl;
        return false;
    }

    for(int r=0; r<size; r++)
    {
        for(int c=0; c<size; c++)
        {
            if(!(fin>>tempBoard[r][c]))
            {
                cout<<"Missing board data."<<endl;
                return false;
            }

            if(!valid_tile(tempBoard[r][c]))
            {
                cout<<"Invalid tile detected."<<endl;
                return false;
            }
        }
    }

    int extra;
    if(fin>>extra)
    {
        cout<<"Extra data found."<<endl;
        return false;
    }

    // COPY ONLY AFTER EVERYTHING PASSES

    score=tempScore;

    for(int r=0; r<size; r++)
    {
        for(int c=0; c<size; c++)
        {
            board[r][c]=tempBoard[r][c];
        }
    }

    cout<<"Game Loaded"<<endl;

    return true;
}	
