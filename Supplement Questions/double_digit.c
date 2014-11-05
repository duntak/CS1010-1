#include <stdio.h>

int rev(int);
int main(void)
{
	int reverse, new, number, digit, new_number=0;

	scanf("%d", &number);

	reverse = rev(number);

	while (reverse  > 0)
	{
		digit = reverse % 10;
		digit *= 2;
		new = digit % 10;
		new_number *= 10;
		new_number += new;
		reverse /= 10;
	}

	printf("%d\n", new_number);

	return 0;
}

int rev(int number)
{
	int digit, new;

	while (number > 0)
	{
		digit = number % 10;
		new *= 10;
		new += digit;
		number /= 10;
	}

	return new;
}

