/**
 * CS1010 AY2011/2 Semester 2 Lab2 Ex3
 *
 * cookies.c
 * cookies.c read positive integer and add up its digits repeatedly
 * until the sum is a single digit
 *
 * Neo Han Wei
 * Discussion Group 8
 */

#include <stdio.h>

int sum_digits(int);
void print_cookie(int);
int main(void)
{
	int number, number1; // input

	printf("Enter a positive integer: ");
	scanf("%d", &number);

	number1 = sum_digits(number);

	print_cookie(number1);
	return 0;
}

// summing up all the digits to a single digit

int sum_digits(int number)
{
	int	count;

	while (number >= 10)
	{
		count = 0;					// RESETTING COUNT
		while (number >= 10)
		{
			count += number%10;		// EXTRACTING THE DIGITS AND ADDING TO COUNT
			number /= 10;
		}
		number += count;		
	}
	return number;
}

// printing message according to the number

void print_cookie(int luck)
{
	switch (luck){
		case 1:
			printf("You will have a fine capacity for the enjoyment of life.\n");
			break;
		case 2:
			printf("Now is the time to try something new.\n");
			break;
		case 3:
			printf("Don't let doubt and suspicion bar your progress.\n");
			break;
		case 4:
			printf("Your principles mean more to you than any money or success.\n");
			break;
		case 5:
			printf("Accept the next proposition you hear.\n");
			break;
		case 6:
			printf("A handful of patience is worth more than a bushel of brains.\n");
			break;
		case 7:
			printf("You have an active mind and a keen imagination.\n");
			break;
		case 8:
			printf("You are talented in many ways.\n");
			break;
		case 9:
			printf("Treat everyone as a friend.\n");
			break;
	}
}

