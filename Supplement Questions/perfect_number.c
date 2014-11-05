#include <stdio.h>

int main(void)
{
	int count= 0, number, integer=1;

	scanf("%d", &number);

	while ((integer != number) || (integer < number))
	{
		if (number % integer == 0)
		{
			count += integer;
		}

			integer++;
	}
		if (count == number)
		{
			printf("%d is a perfect number.\n", number);
		}
		else 
		{
			printf("%d is not a perfect number, its sum of proper divisors is %d.\n", number, count);
		}

	return 0;
}
		
