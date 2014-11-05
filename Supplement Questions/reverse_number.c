#include <stdio.h>

int rev(int);
int main(void)
{
	int count=0, low, high, middle;

 	printf("Enter the range: ");
	scanf("%d %d", &low, &high);
	
	middle = low;
	while (middle != high)
	{
		if (rev(middle) == middle)
		{count += 1;
		middle++;}
		else 
		middle++;
	}
	
	if (rev(high) == high)	
		count++;


	printf("There are %d reverse numbers.\n", count);

	return 0;
}

int rev(int number)
{
	int digit, new = 0;

	while (number > 0)
	{
		digit = number % 10;
		new *= 10;
		new += digit;
		number /= 10;
	}

	return new;
}
