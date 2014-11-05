#include <stdio.h>

int main(void)
{
	int number, digit, new;

	scanf("%d", &number);

	while (number > 0)
	{
		digit = number % 10;
		new *= 10;
		new += digit;;
		number /= 10;
	}

	printf("%d\n", new);

	return 0;
}
