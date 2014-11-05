// CS1010 AY2010/1 Semester 1 PE1 Ex1
//
// code.c
// 
// This program processed time as instructed
// and outputs two chars accordingly. 
// 
// Written by: Lifeng

#include <stdio.h>
#include <math.h>

/* function prototypes */
int convert_minutes(int, int, int);
char lookup_table(int);
int get_number(int);
int get_decimal(int);

int main(void)
{
	int day_input, hr_input, min_input, // user's inputs
		minutes,                        // converted minutes
		number;                         // 2 digit number, 1st and 4th digits of minutes
	char first_char, second_char;

	printf("Enter days, hours and minutes: ");
	scanf("%d %d %d", &day_input, &hr_input, &min_input);

	minutes = convert_minutes(day_input, hr_input, min_input);
	number  = get_number(minutes);

	first_char  = lookup_table(number);
	second_char = lookup_table(get_decimal(number));

	printf("%c%c\n", first_char, second_char);

	return 0;
}

// convert day, hour, minutes into minutes only
int convert_minutes(int day, int hour, int minute)
{
	// for debugging
	//printf("convert_minutes: %d\n", day*24*60+hour*60+minute);
	return day*24*60 + hour*60 + minute;
}

// return a number of just digit 4 and digit 1
int get_number(int minutes)
{
	int digit_1, digit_4; // 1st and 4th digit of minutes

	digit_1 = minutes % 10;
	digit_4 = minutes / 1000 % 10;

	// for debugging
	//printf("get_number: %d\n", digit_4*10+digit_1);
	return digit_4*10 + digit_1;
}

// check the table for game code
char lookup_table(int number)
{
	if(number%2 == 0)
		return 'A';
	else if(number%3 == 0)
		return 'F';
	else if(number%5 == 0)
		return 'K';
	else if(number%7 == 0)
		return 'P';
	else if(number%11==0 || number%13==0)
		return 'T';
	else
		return 'Z';
}

// get the two digits after decimal point
int get_decimal(int number)
{
	float decimal = sqrt(number);

	// for debugging
	//printf("get_decimal: %d\n", (int)(decimal*100)%100);
	return (int)(decimal*100) % 100;  // get the first 2 decimal places
}
