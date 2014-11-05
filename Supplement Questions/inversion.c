// CS1010 AY2011/2 Semester 2
// Mock PE1 Ex1: inversion.c
// Name: Loh Wan Xin
// Discussion Group: B02
// Description: Reads a positive integer, find the reverse of the num
// and count the number of iterations for num to equal the reverse value

#include <stdio.h>
#include <stdlib.h>

int reverse(int);
int count_round (int);

int main (void)
{
	int num, count;

	printf("Enter a positive number: "); // Prompt for user input
	scanf("%d", &num);

	count = count_round(num); 
	
	printf("Number of rounds needed: %d\n", count);

	return 0;
}

// To find the reverse of the number
int reverse (int num)
{
	int inv=0;

	for (;num>0;num/=10)
	{
		inv = inv*10 + num%10;
	}
	return inv;
}

// Calculate and print the number of iterations
int count_round (int num)
{
	int rev, count = 1;

	rev = reverse(num);
	while (num!=rev)
	{
		num = abs(rev - num);
		rev = reverse(num);
		count++;
	}
	return count;
}
