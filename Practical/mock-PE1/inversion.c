// inversion.c
//
// count the number of rounds needed to find a palindrome number.
//
// written by: Lifeng

#include <stdio.h>
#include <stdlib.h>  // for abs function

// function prototypes
int count_round(int);
int reverse(int);

int main(void)
{
	int number, count;

	printf("Enter a positive number: ");
	scanf("%d", &number);

	count = count_round(number);

	printf("Number of rounds needed: %d\n", count);

	return 0;
}

// count the number of rounds needed to find a palindrome
int count_round(int num)
{
	int count = 0;
	do
	{
		num = abs( num - reverse(num) );
		count++;
	} while (num != 0);
	return count;
}

// find the reverse number
int reverse(int num)
{
	int reverse_num = 0;
	while (num > 0)
	{
		reverse_num = reverse_num*10 + num%10;
		num /= 10;
	}
	return reverse_num;
}
