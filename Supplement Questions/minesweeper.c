//minesweeper.c 
#include <stdio.h>
#include <string.h>
#define MINE '*'       // a mine-filled square
#define L1_ROWS 8      // number of rows for level-1 grid
#define L1_COLS 8      // number of columns for level-1 grid
#define L2_ROWS 12     // number of rows for level-2 grid
#define L2_COLS 16     // number of columns for level-2 grid
#define L3_ROWS 16     // number of rows for level-3 grid
#define L3_COLS 32     // number of columns for level-3 grid
void print_game(int, int);
void scan_mines(char [][L3_COLS+2], int, int);
void analyse_mine(char [][L3_COLS+2], int [][L3_COLS+2], int, int);

int main(void)
{
	int level, rows, cols;
	int rows_limit[3] = {L1_ROWS, L2_ROWS, L3_ROWS};
	int cols_limit[3] = {L1_COLS, L2_COLS, L3_COLS};

	scanf("%d\n", &level);

	rows = rows_limit[level-1];
	cols = cols_limit[level-1];

	print_game(rows, cols);
	return 0;
}

void print_game(int rows, int cols)
{ 
	int i, j, score[L3_ROWS][L3_COLS+2] = {{0}};
	char grid[L3_ROWS+2][L3_COLS+2] = {{0}};

	scan_mines(grid, rows, cols);

	analyse_mine(grid, score, rows, cols);

	for (i=1; i<rows; i++)
	{
		for (j=1; j<cols; j++)
		{
			printf("%d ", score[i][j]);
		}
		printf("\n");
	}
}

// Read the grid for minefield
void scan_mines(char grid[][L3_COLS+2], int rows, int cols)
{
	int i, j;

	for (i=1; i<rows+1; i++)
		for (j=1; j<cols+1; j++)
		{	
			scanf(" %c", &grid[i][j]);
		}
}

void analyse_mine(char grid[][L3_COLS+2],int score[][L3_COLS+2], int rows, int cols)
{
	int i,j;

	for (i=1; i<rows+1; i++)
		for (j=1; j<cols+1; j++)
		{
			if (grid[i][j] == MINE)
				score[i][j] = 9;
			else if (grid[i][j] != MINE)
			{	score[i][j] = (grid[i-1][j-1] == MINE) +
					(grid[i-1][j] == MINE) +
					(grid[i-1][j+1] == MINE) +
					(grid[i][j-1] == MINE) +
					(grid[i][j+1] == MINE) +
					(grid[i+1][j-1] == MINE) +
					(grid[i+1][j] == MINE) +
					(grid[i+1][j+1] == MINE);
			}	
		}

}
