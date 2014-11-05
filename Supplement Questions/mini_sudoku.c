/**
 * CS1010 Supplementary Practice 
 *
 * mini_sudoku.c
 *
 * This program  reads an incomplete Sudoku board (with 0 
 * representing blank cells) and attempts to solve the puzzle.
 *
 * Written by: Lifeng
 */

#include <stdio.h>
#include <math.h>

#define SIZE 4

/* function prototypes */
void readBoard (int board[SIZE][SIZE]);
void fillBoard (int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE]);
int fillRow(int board[SIZE][SIZE]);  // fill in rows
int fillCol(int board[SIZE][SIZE]);  // fill in columns
int fillSec(int board[SIZE][SIZE]);  // fill in sections

int main(void)
{
	int board[SIZE][SIZE];

	readBoard (board);
	fillBoard (board);
	printBoard(board);

	return 0;
}

// read a board line by line
void readBoard(int board[SIZE][SIZE])
{
	int i, j;

	printf("Enter the board, "
			"using 0 to indicate a blank cell:\n");
	for (i=0; i<SIZE; i++)
	{
		for (j=0; j<SIZE; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}
}

void fillBoard(int board[SIZE][SIZE])
{
	int fillable = 1;  // 1 - board fillable, 0 - not fillable

	while (fillable)
	{
		fillable = fillRow(board) + fillCol(board) + fillSec(board);
		// if fillable is calculated as bigger than 1,
		// it means some blanks are filled in this round,
		// therefore we should continue next round.
		// if fillable is calculated as 0, it means no more
		// blank can be filled by examining either rows, 
		// columns or sections. therefore there is no need
		// to continue loop and we shall quit
	}
}

// return 1 if any slot is filled, 0 otherwise
int fillRow(int board[SIZE][SIZE])
{
	int i, j,
		fillable = 0,    // whether the board can be updated
		blankX, blankY,  // indice of a blank cell to fill in
		rowSum,          // sum of integers in a row
		numZero;         // numer of zeros in a row

	for (i = 0; i < SIZE; i++)
	{
		numZero = 0;
		rowSum = 10;
		for (j = 0; j < SIZE; j++)
		{
			if (board[i][j] == 0)  // found a blank cell
			{
				blankX = i;
				blankY = j;
				numZero++;
			}
			else
				rowSum -= board[i][j]; // update sum
			// sum of all values in a row is 10
		}
		if (numZero == 1)  // only 1 blank cell in current row?
		{
			board[blankX][blankY] = rowSum;
			fillable = 1;
		}
	}

	return fillable;
}


// return 1 if any slot is filled, 0 otherwise
int fillCol(int board[SIZE][SIZE])
{
	int i, j,   
		fillable = 0,    // whether the board can be updated
		blankX, blankY,  // indice of a blank cell to fill in
		colSum,          // sum of integers in a column (10)
		numZero;         // numer of zeros in a column

	for (i = 0; i < SIZE; i++)
	{
		numZero = 0;    
		colSum = 10;
		for (j = 0; j < SIZE; j++)          
		{
			if (board[j][i] == 0)  // found a blank cell
			{
				blankX = j;
				blankY = i;
				numZero++;
			}
			else
				colSum -= board[j][i];  // update sum
		}
		if (numZero == 1)  // only 1 blank cell in current column?
		{
			board[blankX][blankY] = colSum;
			fillable = 1;
		}
	}
	return fillable;
}


// return 1 if any slot is filled, 0 otherwise
int fillSec(int board[SIZE][SIZE])
{
	int i, j, r, c,
		fillable = 0,    // whether the board can be updated
		secSize = (int)sqrt(SIZE), // size of a section to search
		blankX, blankY,  // indice of a blank cell to fill in
		secSum,          // sum of integers in a section
		numZero;

	for (i = 0; i < SIZE; i += secSize)
	{
		for (j = 0; j < SIZE; j += secSize)
		{
			numZero = 0;
			secSum = 10;
			for (r = i; r < i+secSize; r++)
			{
				for (c = j; c < j+secSize; c++)
				{
					if (board[r][c] == 0) // found a blank cell
					{
						blankX = r;
						blankY = c;
						numZero++;
					}
					else
						secSum -= board[r][c];  // update sum
				}
			}
			if (numZero == 1)     // only 1 blank cell in current section?
			{
				board[blankX][blankY] = secSum;
				fillable = 1;
			}

		}
	}
	return fillable;
}

void printBoard(int board[SIZE][SIZE])
{
	int i, j;

	printf("\nThe Sudoku puzzle solved:\n");
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
}
