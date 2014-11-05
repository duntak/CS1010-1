/* CS1010 AY2011/2 Semester 2 Lab4 Ex4
 *
 * minesweeper.c 
 * Read the game level, and location of mines
 * and compute the values of safe squares
 * in a numeric two-dimensial array
 *
 * Loh Wan Xin
 * B02
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MINE '*'       // a mine-filled square
#define L1_ROWS 8      // number of rows for level-1 grid
#define L1_COLS 8      // number of columns for level-1 grid
#define L2_ROWS 12     // number of rows for level-2 grid
#define L2_COLS 16     // number of columns for level-2 grid
#define L3_ROWS 16     // number of rows for level-3 grid
#define L3_COLS 30     // number of columns for level-3 grid

void scan_mines(char [][L3_COLS+1],int);
void input_num(char [][L3_COLS+1],int,int);
void print_grid(char [][L3_COLS+1],int,int);

int main(void)
{
	int level, rows, cols;
	int rows_limit[3] = {L1_ROWS, L2_ROWS, L3_ROWS};
	int cols_limit[3] = {L1_COLS, L2_COLS, L3_COLS};

	scanf("%d\n", &level);
	
	rows = rows_limit[level-1];
	cols = cols_limit[level-1];

	char grid[rows][L3_COLS+1];

	scan_mines(grid,rows);
	//print_grid(grid,rows,cols);
	input_num(grid,rows,cols);
	print_grid(grid,rows,cols);

	return 0;
}

// Read the grid for minefield
void scan_mines(char grid[][L3_COLS+1], int rows)
{
	int r;
	for (r=0; r<rows; r++)
	{
		scanf("%s", grid[r]);
	}
}

//Compute the values of safe squarwes
void input_num(char grid[][L3_COLS+1], int rows, int cols)
{
	int r,c;
	char count_mine;
	for (r=0;r<rows;r++)
	{
		for (c=0;c<cols;c++)
		{
			if(grid[r][c]==MINE){
				continue;
			}

			count_mine='0';
			if (( r>0&&c>0) && grid[r-1][c-1]==MINE)
				count_mine++;
			if (r>0 && grid[r-1][c]==MINE)
				count_mine++;
			if ((r>0&&c<cols-1) && grid[r-1][c+1]==MINE)
				count_mine++;
			if (c>0 && grid[r][c-1]==MINE)
				count_mine++;
			if (c<cols-1 && grid[r][c+1]==MINE)
				count_mine++;
			if ((r<rows-1&&c>0) && grid[r+1][c-1]==MINE)
				count_mine++;
			if (r<rows-1 && grid[r+1][c]==MINE)
				count_mine++;
			if ((r<rows-1&&c<cols-1) && grid[r+1][c+1]==MINE)
				count_mine++;

			grid[r][c]=count_mine;
		}
	}

	for(r=0;r<rows;r++)
	{
		for(c=0;c<cols;c++)
		{
			if(grid[r][c]==MINE)
				grid[r][c]='9';
		}
	}
}

// Print out the two dimensional array
void print_grid(char grid[][L3_COLS+1], int rows, int cols)
{
	int r, c;
	for (r=0;r<rows;r++)
	{
		for(c=0;c<cols;c++)
			printf(" %c", grid[r][c]);
		printf("\n");
	}
}
