#include <stdio.h>

int main(void)
{
	int i, number, digit,  rev=0,last;
 
	printf("Enter a 6-digit number: ");
	scanf("%d", &number);
	printf("Digits are: ");
	last = number % 10;			// THIS IS TO EXTRACT THE LAST DIGIT
	while (number > 0)
	{
		rev = rev * 10 + number % 10; // THIS IS TO MAKE A NEW NUMBER CALLED REV BY PUSHING THE DIGITS UP TEN BY TEN :)
		number /= 10;
	}  							// THIS IS TO INVERT THE NUMBER
	for (i=0; i<5; i++)
	{
		digit = rev % 10; 
		rev /= 10;
		printf("%d,", digit);
	}							// THIS IS TO EXTRACT THE FIRST 5 DIGITS
	printf("%d\n", last);		// THIS IS TO PRINT THE LAST DIGIT
	return 0;
}
