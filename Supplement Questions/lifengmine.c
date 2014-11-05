#include <stdio.h>
#define MINE '*'       // a mine-filled square
#define L1_ROWS 8      // number of rows for level-1 grid
#define L1_COLS 8      // number of columns for level-1 grid
#define L2_ROWS 12     // number of rows for level-2 grid
#define L2_COLS 16     // number of columns for level-2 grid
#define L3_ROWS 16     // number of rows for level-3 grid
#define L3_COLS 30     // number of columns for level-3 grid

/* function prototypes */
void read_board(char [][L3_COLS+2], int, int);
void compute_score(char [][L3_COLS+2], int [][L3_COLS+2], int, int);
void print_board(int [][L3_COLS+2], int, int);

int main(void)
{
	int level, rows, cols;

	// build a surrounding minefield so that all cells
	// can be treated as inner cells - simplify calculations
	char mine_board[L3_ROWS+2][L3_COLS+2] = {{0}};
	int score_board[L3_ROWS+2][L3_COLS+2] = {{0}};

	int rows_limit[3] = {L1_ROWS, L2_ROWS, L3_ROWS};
	int cols_limit[3] = {L1_COLS, L2_COLS, L3_COLS};

	scanf("%d\n", &level);

	rows = rows_limit[level-1];
	cols = cols_limit[level-1];

	read_board(mine_board, rows, cols);
	compute_score(mine_board, score_board, rows, cols);
	print_board(score_board, rows, cols);

	return 0;
}

// read in a board of game
void read_board(char board[][L3_COLS+2], int rows, int cols)
{
	int i, j;
	for (i=1; i<=rows; i++)
	{
		for (j=1; j<=cols; j++)   //i, j starts at 1 to form border
		{
			scanf(" %c", &board[i][j]);
		}
	}
}

// compute the score of each cell according to surrounding mines
void compute_score(char mine[][L3_COLS+2], int score[][L3_COLS+2],
		int rows, int cols)
{
	int i, j;
	for (i=1; i<=rows; i++)
	{
		for (j=1; j<=cols; j++)
		{
			if (mine[i][j] == '*')
				score[i][j] = 9;
			else
				score[i][j] = (mine[i-1][j-1] == '*') +
					(mine[i-1][j]   == '*') +
					(mine[i-1][j+1] == '*') +
					(mine[i][j-1]   == '*') +
					(mine[i][j+1]   == '*') +
					(mine[i+1][j-1] == '*') +
					(mine[i+1][j]   == '*') +
					(mine[i+1][j+1] == '*');
		}
	}
}

// print out the score board
void print_board(int score[][L3_COLS+2], int rows, int cols)
{
	int i, j;
	for (i=1; i<=rows; i++)
	{
		for (j=1; j<=cols; j++)
		{
			printf(" %d", score[i][j]);
		}
		printf("\n");
	}
}
