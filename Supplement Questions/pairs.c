/**
 * CS1010 AY2011/2 Semester 2 Lab4 Ex3
 *
 * pairs.c
 * <Type in description of program>
 *
 * Neo Han Wei
 * Discussion Group 8
 */

#include <stdio.h>
#include <math.h>
#define MAX_ROW 10
#define MAX_COL 10

/* function prototype */
void print_matrix(int [][MAX_ROW], int, int);
void read_matrix(int [][MAX_COL], int *, int *);
int max_pairs(int [][MAX_COL], int, int);

int main(void)
{
	int val;  // value with maximum number of pairs
	int numRows, numCols, matrix[MAX_ROW][MAX_ROW];

	read_matrix(matrix, &numRows, &numCols);
//	print_matrix(matrix, numRows, numCols);

	val = max_pairs(matrix, numRows, numCols);

	printf("Value with maximum number of pairs is: %d\n", val);

	return 0;
}

// user input => row, columns and each values
void read_matrix(int matrix[][MAX_COL], int *numRows_p, int *numCols_p)
{
	int i, j;

	printf("Enter number of rows: ");
	scanf("%d", &*numRows_p);
	printf("Enter number of columns: ");
	scanf("%d", &*numCols_p);
	printf("Enter values:\n");

	for (i=0; i < *numRows_p; i++)
		for (j=0; j < *numCols_p; j++)
			scanf("%d", &matrix[i][j]);

}


// find out the value with the max pair
int max_pairs(int matrix[][MAX_COL], int rows, int cols)
{
	int i, j, k;
	int sum=0, tally=0, value;

	for (i=0; i < 10; i++)
	{
		for (j=0; j < rows; j++)
		{
			for (k=0; k < cols; k++)
			{	
				if (k+1 < cols)
				{
					if ((matrix[j][k] == i) && (matrix[j][k+1] == i))
						tally += 1;
				}
				if (j+1 < rows)
				{
					if ((matrix[j][k] == i) && (matrix[j+1][k] == i))
						tally += 1;
				}
//				printf("%d %d\n", k, tally); 
			}
		}
		
		if (tally > sum)
		{
		//	printf("%d %d\n", tally, i);
			sum = tally;
			value = i;
			tally = 0;
		}
	}
	return value;

}


// print out a matrix row by row.
// for testing purpose
void print_matrix(int matrix[][MAX_COL], int numRows, int numCols)
{
	int i, j;

	for (i=0; i<numRows; i++)
	{
		for (j=0; j<numCols; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
