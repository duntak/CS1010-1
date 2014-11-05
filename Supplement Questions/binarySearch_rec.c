// Search for an element
// using Binary Search
// and recursion

#include <stdio.h>
#define MAX 20
int binarySearch (int [], int, int, int);

int main(void)
{
	int i, size, key, index,
		arr[MAX];

	printf("Enter number of integers: ");
	scanf("%d", &size);
	printf("Enter the %d integers in increasing order: ", size);
	for (i=0;i<size;i++)
		scanf("%d", &arr[i]);

	printf("Enter key: ");
	scanf("%d", &key);

	index = binarySearch(arr,0,size-1,key);

	if (index>=0)
		printf("Number %d found at index %d\n", key, index);
	else
		printf("Number not found!\n");

	return 0;
}

int binarySearch(int arr[], int start, int end, int key)
{
	int mid = (start+end)/2;

	if(start>end)
		return -1;
	else{	
		if(arr[mid]==key)
			return mid;
		else if (key<arr[mid])
			return binarySearch(arr,start,mid-1,key);
		else
			return binarySearch(arr,mid+1,end,key);
	}
}
