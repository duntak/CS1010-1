/* CS1010 AY2011/2 Semester 2 Lab5 Ex4
 *
 * mine_clusters.c
 * Count the number of distinct mine clusters
 *
 * Loh Wan Xin
 * B02
 */

#include <stdio.h>
#include <string.h>
#define MINE '*'   // a mine-filled cell
#define FREE '-'   // a mine-free cell
#define MAX_ROWS 20  // maximum rows of a minefield
#define MAX_COLS 40  // maximum columns of a minefield

void scan_minefield(char [][MAX_COLS+1], int *, int *);
void print_minefield(char [][MAX_COLS+1], int *, int *);
int count_minecluster(char [][MAX_COLS+1], int *, int *);
void find_cluster(char [][MAX_COLS+1], int, int );

int main(void)
{
	char minefield[MAX_ROWS+1][MAX_COLS+1];
	int row_size, col_size; // actual size of minefield read

	scan_minefield(minefield,&row_size,&col_size);
	//print_minefield(minefield,&row_size,&col_size);

	printf("%d\n", count_minecluster(minefield,&row_size,&col_size));

	return 0;
}

// To read in the minefield
void scan_minefield(char mines[][MAX_COLS+1], 
		int *row_size_p, int *col_size_p)
{
	int r;

	scanf("%d %d", row_size_p, col_size_p);
	getchar(); // to catch the newline
	for (r=1; r<*row_size_p+1; r++)
		scanf("%s", mines[r]);  // no blank
}

// To print out the minefield
// for checking purposes
void print_minefield(char mines[][MAX_COLS+1],
		int *row_size_p, int *col_size_p)
{
	int r;

	for (r=1; r<*row_size_p+1; r++)
		printf("%s\n", mines[r]);

	printf("\n");
}

// Count the number of mine cluster
// Return the number of mine cluster
int count_minecluster(char mines[][MAX_COLS+1],
		int *row_size_p, int *col_size_p)
{
	int i,j, count = 0;

	for (i=0;i<*row_size_p+1;i++)
		for (j=0;j<*col_size_p+1;j++)
			if (mines[i][j]== MINE)
			{
				find_cluster(mines,i,j);
				count++;
				//print_minefield(mines,row_size_p,col_size_p);
				//printf("count: %d\n",count);
			}
	return count;
}

// Recursive function to find minecluster
void find_cluster(char mines[][MAX_COLS+1], int row, int col)
{
	int i,j;

	mines[row][col]= '9'; 	// Change MINE to '9'
							// to show cluster when checking
	for(i=row-1;i<=row+1;i++)
		for(j=col-1;j<=col+1;j++)
			if(mines[i][j]==MINE)
				find_cluster(mines,i,j);
}

