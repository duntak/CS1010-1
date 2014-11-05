/**
 * CS1010 AY2011/2 Semester 2 Lab2 Ex1
 *
 * collatz.c
 * This program reads a natural number and computes the number
 * of iterations required to turn the input number into 1 by
 * following the Collatz sequence: half it if the number is even,
 * or triple it and add 1 if the number is odd.
 *
 * Neo Han Wei
 * Discussion Group 8
 */

#include <stdio.h>

int count_iterations(int);
int main(void)
{

	int value;

	printf("Enter a natural number: ");
	scanf("%d", &value);

	printf("Number of iterations = %d\n", count_iterations(value));

	return 0;
}

// compute the number of iterations required for the input value to reach 1

int count_iterations(int value1)
{
	int	it;
	for (it=0; value1 != 1; it++)
	{
		if (value1 % 2 == 0)
		{	
			value1 = value1 / 2;
			
		}
	 	else  
		{
			value1 = value1 * 3 + 1;
			
		}
	}
	return it;
}
