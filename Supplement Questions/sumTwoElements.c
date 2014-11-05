/* CS1010 Supplementary Practice 
 *
 * sumTwoElements.c
 *
 * This program finds two array elements whose sum
 * equals to given sum
 *
 * <name>
 */

#include <stdio.h>
#define MAX 20

void find_two_elements(int [], int, int, int *, int *);

int main(void)
{
	int i, size, sum;
	int index1, index2;
	int arr[MAX];

	printf("Enter size of array: ");
	scanf("%d", &size);

	printf("Enter sorted array: ");
	for (i=0; i<size; i++)
		scanf("%d", &arr[i]);

	printf("Enter sum: ");
	scanf("%d", &sum);

	index1 = index2 = -1;
	find_two_elements(arr, size, sum, &index1, &index2);

	if (index1 != -1)
		printf("The two elements are at indices %d and %d.\n", index1, index2);
	else
		printf("There is no solution.\n");

	return 0;
}

void find_two_elements(int arr[], int size, int sum, int *idx1, int *idx2)
{
	int low=0, high=size-1,
		total = arr[low]+arr[high];

	while ((low<=high) && (total!=sum))
	{
		if (total > sum)
			high--;
		else
			low++;
		total = arr[low]+arr[high];
	}
	if (total==sum)
	{
		*idx1 = low;
		*idx2 = high;
	}
}


