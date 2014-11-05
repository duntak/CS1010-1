#include <stdio.h>

int main(void)
{
	int number, digit, hold_digit, i;

	scanf("%d %d", &number, &digit);

	for (i = 0; i < digit; i++)
	{
		hold_digit =  number % 10;
		number /= 10;
	}

	printf("%d\n", hold_digit);

	return 0;
}
