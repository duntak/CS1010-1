#include <stdio.h>

int main(void)
{
	int low, high, i, d;
	
	printf("Enter low and high: ");
	scanf("%d %d", &low, &high);

	i = low;
	d = low;

while (d < high)
{
	for (i=low; i < (d+9); i++)
	{
	printf("%d ", i);
	} 
	
	printf("%d \n", i);
	d += 10;
	low += 10;
}


	return 0;
}
