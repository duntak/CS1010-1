#include <stdio.h>
#include <math.h>

int count_digit(int);
int palindrome(int);
int reverse(int);
void analyse(int);
int main(void)
{
	int num;

	printf("Enter a positive number: ");
	scanf("%d", &num);
	
	analyse(num);

	return 0;
}
// count iteration
int palindrome(int x)
{
	int y; 

	y = reverse(x);

	while (x != y)
	{
		x = fabs(x - y);
		y = reverse(x);
	}
	return x;
}

// analyse number and print words
void analyse(int number)
{
	int num;
	num = palindrome(number);
	
	switch (count_digit(num)){
		case 1: case 3:
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
// reverse the number
int reverse(int back)
{
	int digit, new=0;
	while (back > 0)
	{
		digit = back % 10;
		new *= 10;
		new += digit;
		back /= 10;
	}
	return new;
}

// counting no. of digits
int count_digit(int number)
{
	int count=0;
	while(number > 0)
	{
		number /= 10;
		count++;
	}
	return count;
}
