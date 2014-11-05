/* CS1010 AY2011/2 Semester 2 Lab4 Ex3
 *
 * pairs.c
 * Find out the maximum number of pairs of the same value
 *
 * Loh Wan Xin
 * B02
 */


#include <stdio.h>
#include <math.h>
#define MAX_ROW 10
#define MAX_COL 10

/* function prototype */
void read_matrix(int [][MAX_COL],int *, int *);
void print_matrix(int [][MAX_COL], int, int);
int max_pairs(int [][MAX_COL], int, int);

int main(void)
{
	int val;  // value with maximum number of pairs
	int numRows, numCols, matrix[MAX_ROW][MAX_COL];

	read_matrix(matrix, &numRows, &numCols);

	// for testing
	// print_matrix(matrix, numRows, numCols);

	val = max_pairs(matrix, numRows, numCols);

	printf("Value with maximum number of pairs is: %d\n", val);

	return 0;
}

// Read in user's input of matrix
void read_matrix(int matrix[][MAX_COL], int *numRows_p, int *numCols_p)
{
	int i,j;

	printf("Enter number of rows: ");
	scanf("%d", &*numRows_p);
	printf("Enter number of columns: ");
	scanf("%d", &*numCols_p);

	printf("Enter values:\n");
	for(i=0;i<*numRows_p;i++)
		for(j=0;j<*numCols_p;j++)
			scanf("%d", &matrix[i][j]);
}

// Compute and return a value in the matrix
// that has the maximum number of pairs
int max_pairs(int matrix[][MAX_COL], int rows, int cols)
{
	int i,j,value[10]={0},
		m,val,max=0;

	for (i=0;i<rows;i++)
	{
		for (j=0;j<cols;j++)
		{
			if ( j<cols-1 && matrix[i][j]==matrix[i][j+1])
				value[matrix[i][j]]++;
			if ( i<rows-1 && matrix[i][j]==matrix[i+1][j])
				value[matrix[i][j]]++;
		}
	}
	/* for testing
	   for (m=0;m<10;m++)
	   printf("number of '%d' pairs: %d\n", m,value[m]);
	 */

	for (m=0;m<10;m++)
		if (value[m]>max){
			max = value[m];
			val = m;
		}

	return val;
}

// print out a matrix row by row.
// given, NOT to be changed!
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
