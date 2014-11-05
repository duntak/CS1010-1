// analysis.c
//
// count the number of digits in the palindrome number been found.
// and print out message accordingly
//
// written by: Lifeng

#include <stdio.h>
#include <stdlib.h>  // for abs() function

// function prototypes
int palindrome(int);
int reverse(int);
void analyse(int);
int count_digit(int);

int main(void)
{
	int number;

	printf("Enter a positive number: ");
	scanf("%d", &number);

	number = palindrome(number);

	analyse(number);

	return 0;
}

// return the palindrome been found
int palindrome(int num)
{
	int reverse_num = reverse(num);
	while ( num != reverse_num )
	{
		num = abs( num - reverse_num );
		reverse_num = reverse(num);
	}
	return num;
	/*
	do
	{
		reverse_num = reverse(num);
		num = abs( num - reverse_num );
	} while (num != 0);
	return reverse_num;
	*/
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

// analyze and print out messages accordingly
void analyse(int num)
{
	switch (count_digit(num))
	{
		case 1:
		case 3:
			printf("Bingo!\n");
			break;
		case 2:
			printf("Ding dong!\n");
			break;
		default:
			printf("Incredible!\n");
			break;
	}
}

// count the number of digits in an integer
int count_digit(int num)
{
	int count = 0;
	while (num > 0)
	{
		num /= 10;
		count++;
	}
	return count;
}
