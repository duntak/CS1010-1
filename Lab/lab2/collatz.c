/**
 * CS1010 AY2011/2 Semester 2 Lab2 Ex1
 *
 * collatz.c
 * This program reads a natural number and computes the number
 * of iterations required to turn the input number into 1 by
 * following the Collatz sequence: half it if the number is even,
 * or triple it and add 1 if the number is odd.
 *
 * Loh Wan Xin
 * B02
 */

#include <stdio.h>

int count_iterations (int);

int main(void)
{
	int num_iteration, natural_number;
	printf("Enter a natural number: ");
	scanf("%d", &natural_number);

	num_iteration=count_iterations(natural_number);

	printf("Number of iterations = %d\n",num_iteration);

	return 0;
}

// Count the number of loops it takes to reach 1
int count_iterations (int N)
{
	int iteration=0;

	while(N>1)
	{
		if (N%2==0) // If N is even, divide by 2
			N/=2;
		else
			N=3*N+1; // If N is odd, triple it plus 1

		iteration++; // Number of loop plus 1
	}
	return iteration;
}
