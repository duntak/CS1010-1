/* CS1010 AY2011/2 Semester 2 Lab4 Ex1
 *
 * estimatePi.c
 * This program reads in a list of n distinct integers and
 * computes the estimate value for pi.
 *
 * Loh Wan Xin
 * B02
 */

#include <stdio.h>
#include <math.h>
#define MAX 50

// function prototypes
double pi(int [], int);
int gcd(int, int);

int main(void)
{
	int i, size, arr[MAX];

	scanf("%d", &size);
	for (i=0;i<size;i++)
		scanf("%d", &arr[i]);

	/* Check array input
	   for (i=0;i<size;i++)
	   printf("%d:%d ",i,arr[i]);
	   printf("\n");
	 */

	printf("Estimated pi = %.4f\n", pi(arr,size));
	return 0;
}

// Compute the estimated value of pi
double pi(int arr[], int size)
{
	int i,j,
		count_pair = 0,
		total_pair = 0;

	for (i=0;i<size-1;i++)
	{
		for (j=i;j<size-1;j++)
		{
			if (gcd(arr[i],arr[j+1])==1)
				count_pair++;

			total_pair++;
			//printf("%d:count=%d, total=%d\n", i, count_pair, total_pair);
		}
	}
	return sqrt(6.0*total_pair/count_pair);
}

// Find the greatest common divisor between two numbers
int gcd(int a,int b)
{
	int i,num,greatest=1;

	num = fmin(a,b);

	for (i=2;i<=num;i++)
		if(!(a%i)&&!(b%i))
			greatest=i;
	//printf("gcd(%d,%d):%d\n",a,b,greatest);
	return greatest;
}
