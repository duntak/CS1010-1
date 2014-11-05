// CS1010 AY2011/2 Semester 1
// PE1 Ex2: winners.c
//
// This program determines who are the winners fof a lucky draw.
//
// Written by: Lifeng

#include <stdio.h>

// function prototypes
int is_winner(int, int, int);
int contains(int, int);

int main(void)
{
	int factor,      	// factor-digit
		must_have,	    // must-have-digit 
		num; 	    	// number of participants
	int i, count = 0;

	printf("Enter factor-digit: ");
	scanf("%d", &factor);
	printf("Enter must-have-digit: ");
	scanf("%d", &must_have);
	printf("Enter number of participants: ");
	scanf("%d", &num);

	for (i=1; i<=num; i++)
		if (is_winner(factor, must_have, i))
			count++;

	printf("Number of winners: %d\n", count);

	return 0;
}

// check whether player i is winner
int is_winner(int factor, int must_have, int i)
{
	if (i%factor==0 && contains(must_have, i))
		return 1;
	return 0;
}

// check whether player i have must-have number
int contains(int must_have, int i)
{
	while (i > 0)
	{
		if (i%10 == must_have)
			return 1;
		i /= 10;
	}
	return 0;
}
