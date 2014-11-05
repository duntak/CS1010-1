// CS1010 AY2011/2 Semester 1
// PE1 Ex1: century.c
//
// This program read in a year and determine 
// which century that year falls in
//
// written by: Lifeng

#include <stdio.h>

void printCentury(int);
void printOrdinal(int);

int main(void)
{
	int year; // user's input

	printf("Enter year: ");
	scanf("%d", &year);

	printCentury(year);

	return 0;
}

// prints out the century that a year is in
void printCentury(int year)
{
	int century = year/100 + 1;

	printf("The year %d falls in the %d", year, century);

	printOrdinal(century);

	printf(" century.\n");
}

// prints ordinal suffix ("st" "nd" "rd" and "th")
void printOrdinal(int century)
{
	if (century%10 == 1 && century%100 != 11)
		printf("st");
	else if (century%10 == 2 && century%100 != 12)
		printf("nd");
	else if (century%10 == 3 && century%100 != 13)
		printf("rd");
	else 
		printf("th");
}
