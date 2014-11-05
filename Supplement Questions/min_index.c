/* CS1010 AY2011/2 Semester 2 Lab5 Ex2
 *
 * min_index.c
 *
 * Find the index of the smallest element 
 * in an array of n integers
 * where 0 < n <= 10
 *
 * Loh Wan Xin
 * B02
 */

#include <stdio.h>
#define MAX_SIZE 10

int get_min_index(int [], int);
int get_min_index_rec(int, int [], int, int);

int main(void)
{
	int arr[MAX_SIZE]; 
	int i, 
		n,  // actual number of array elements
		min_index; // index of smallest array element

	printf("How many elements? ");
	scanf("%d", &n);

	printf("Enter %d elements:\n", n);
	for (i=0; i<n; i++)
		scanf("%d", &arr[i]);

	min_index = get_min_index(arr,n);

	printf("Index of min element: %d\n", min_index);

	return 0;
}

// recursive function, return index of 
// the smallest array element
int get_min_index(int arr[],int size)
{
	return get_min_index_rec(0,arr,1,size);
}

// auxiliary function of get_min_index
int get_min_index_rec(int min_index, int arr[], int start, int size)
{
	if (start==size)
		return min_index;
	else 
	{
		if (arr[min_index]>arr[start])
			min_index=start;
		return get_min_index_rec(min_index,arr,start+1,size);
	}
}
