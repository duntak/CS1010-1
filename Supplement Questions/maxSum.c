/**
 * CS1010 AY2011/2 Semester 2 Lab4 Ex2
 *
 * maxSum.c
 * This program read a length l, then calculate maximal
 * consecutive sum of length l in an array.
 *
 * Neo Han Wei
 * Discussion Group 8
 */

#include <stdio.h>
#include <math.h>

/* function prototypes */
int sum_l(int [], int, int, int);
int maxSum_l(int [], int, int, int *);
int main(void)
{
	int l;  // to calculate max consecutive sum of length l
	int arr[] = {6, 1, 8, 2, 7, 4, 7, 1, 8, 2, 3};
	int index; // index of the starting position of max consecutive sum
	int max;  // max sum of length l

	printf("Enter length l: ");
	scanf("%d", &l);

	max = maxSum_l(arr, 11, l, &index);

	printf("Maximal consecutive sum of length %d is %d, "
			"starting at array index %d\n", l, max, index);

	return 0;
}

// return maximal sum of length 'len' in array 'arr'
int maxSum_l(int arr[], int size, int len, int *index_p)
{
	int i, maxsum;

	maxsum = sum_l(arr, 11, 0, len);
	*index_p = 0;
	for (i = 1; i < (size-len+1); i++)
	{
		if (maxsum < sum_l(arr, 11, i, len))
		{
			maxsum = sum_l(arr, 11, i, len);
			*index_p = i;
		}
	}
	return maxsum;
}

// return sum of consecutive array elements,
// starting from 'start' and calculate 'len' elements
int sum_l(int arr[], int size, int start, int len)
{
	int i, sum=0;

	for (i = 0; i < len; i++)
	{
		sum += arr[start+i];
	}
	return sum;

}
