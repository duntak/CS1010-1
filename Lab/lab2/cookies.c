/**
 * CS1010 AY2011/2 Semester 2 Lab2 Ex3
 *
 * cookies.c
 * Read in a positive integer
 * Add up its digits repeatedly until the sum is a single digit
 * and print out the corresponding Fortune Cookie message 
 *
 * Loh Wan Xin
 * B02
 */

#include <stdio.h>

int sum_digits(int);
void print_cookie(int);

int main(void)
{
	int number,digit; 

	printf("Enter a positive integer: ");
	scanf("%d", &number);

	digit=sum_digits(number);
	print_cookie(digit);

	return 0;
}

// Extract out the digits
int sum_digits (int N)
{
	int sum;

	for (sum=N;N>=10;N=sum) // Perform loop when sum of digits or number is greater than 10
	{	
		for(sum=0;N!=0;N/=10) // Extract out and sum the digits
		{
			sum+=N%10;
		}
	}
	return sum;

}

// Print out the corresponding Fortune Cookie message
void print_cookie(int digit)
{
	switch (digit)
	{	case 1: printf("You will have a fine capacity for the enjoyment of life.\n");break;
		case 2:	printf("Now is the time to try something new.\n");break;
		case 3: printf("Don't let doubt and suspicion bar your progress.\n");break;
		case 4: printf("Your principles mean more to you than any money or success.\n");break;
		case 5: printf("Accept the next proposition you hear.\n");break;
		case 6:	printf("A handful of patience is worth more than a bushel of brains.\n");break;
		case 7: printf("You have an active mind and a keen imagination.\n");break;
		case 8: printf("You are talented in many ways.\n");break;
		case 9: printf("Treat everyone as a friend.\n");break;
	}
}
