/**
 * CS1010 AY2011/2 Semester 2 Lab4 Ex1
 *
 * estimatePi.c
 * This program reads in a list of n distinct integers and
 * computes the estimate value for pi.
 *
 * Neo Han Wei
 * Discussion Group 8
 */

#include <stdio.h>
#include <math.h>
// function prototypes
double pi(int [], int);
int gcd(int, int);
int main(void)
{
	int values, i, arr[50] = {0};

	scanf("%d", &values);
	for (i=0; i<values; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	printf("Estimated pi = %.4lf\n", pi(arr, values));

	return 0;
}

// Write a description of the function here
double pi(int arr[], int size)
{
	int i, j, count=0, pairs=0,div;

	for(i=0; i<(size-1); i++)
		for(j=(i+1); j<size; j++)
		{	
			div = gcd(arr[i], arr[j]);
			pairs++;
			if (div == 1)
				count++;
		}
	return sqrt((double)pairs/count*6.0);

}

int gcd(int a, int b)
{
	int smallest, n=2, gcd=1;
	if (a<b)
		smallest = a;
	else 
		smallest = b;
	
	while (n <= smallest)
	{
		if ((a%n ==0) && (b%n ==0))
		{
			gcd = n;
			n++;
		}
		else 
			n++;
	}

	return gcd;
}	
