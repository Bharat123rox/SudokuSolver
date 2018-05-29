#include <bits/stdc++.h>
#define UNFILLED 0
using namespace std;

bool findunfilled(int grid[9][9], int& row, int& col)
{
	for (row = 0; row < 9; row++)
	{
		for (col = 0; col < 9; col++)
		{
			if(grid[row][col] == UNFILLED)
				return true;
		}
	}
	return false;
}

bool inRow(int grid[9][9], int row, int num)
{
	for(int col = 0; col < 9; col++)
	{
		if(grid[row][col] == num)
			return true; 
	}
	return false;
}

bool inCol(int grid[9][9], int col, int num)
{
	for(int row = 0; row < 9; row++)
	{
		if(grid[row][col] == num)
			return true;
	}
	return false;
}

bool inBox(int grid[9][9], int startrow, int startcol, int num)
{
	for(int row = 0; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			if(grid[row+startrow][col+startcol] == num)
				return true;
		}
	}
	return false;
}

bool isok(int grid[9][9], int row, int col, int num)
{
	return ( !inRow(grid, row, num) && 
		!inCol(grid, col, num) && 
		!inBox(grid, row - row%3, col - col%3, num) );
}

void printSudoku(int grid[9][9])
{
	cout << "\n Solved Sudoku: \n"; 
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			cout << grid[i][j] << " "; 
		}
		cout << endl;
	}
}

bool solveSudoku(int grid[9][9])
{
	int row, col;
	if(!findunfilled(grid, row, col))
		return true;
	for(int i = 1; i <= 9; i++)
	{
		if(isok(grid, row, col, i))
		{
			grid[row][col] = i;
			if(solveSudoku(grid)) 
			{
				return true;
			}
			grid[row][col] = UNFILLED;
		}
	}
	return false; //Backtracking Step!
}


int main()
{
	int grid[9][9];
	cout << "Enter the partially solved Sudoku row by row with zero for unfilled entries: \n";
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			cin >> grid[i][j];
			//Basic Input Validation
			assert(("Invalid Input",  (grid[i][j] >= 0) && (grid[i][j] <= 9)) );
		}
	}
	if(solveSudoku(grid))
	{
		printSudoku(grid);
	}
	else
	{
		cout << "No Solution";
	}
	return 0;
}