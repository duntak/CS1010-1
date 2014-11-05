/* CS1010 AY2011/2 Semester 2 Lab4 Ex2
 *
 * maxSum.c
 * This program read a length l, then calculate maximal
 * consecutive sum of length l in an array.
 *
 * Loh Wan Xin
 * B02
 */

#include <stdio.h>
#include <math.h>

/* function prototypes */
int maxSum_l(int [], int, int, int *);
int sum_l(int [], int, int, int);

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
	int i,sum,max=0;
	for (i=0;i<size-len+1;i++)
	{
		sum = sum_l(arr,size,i,len);
		if(sum>max){
			max = sum;
			*index_p = i;
		}
		//printf("%d: max=%d\n", i,max);
	}
	return max;
}


// return sum of consecutive array elements,
// starting from 'start' and calculate 'len' elements
int sum_l(int arr[], int size, int start, int len)
{
	int j, sum=0;
	for (j=0;j<len;j++)
		sum += arr[start+j];

	/*
	printf("%d",arr[start]);
	for (j=1;j<len;j++)
		printf("+%d",arr[start+j]);
	printf("=%d\n",sum);
	*/

	return sum;
}
