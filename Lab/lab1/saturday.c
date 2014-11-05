/**
 * CS1010 AY2011/2 Semester 2 Lab1 Ex4
 *
 * saturday.c
 * to compute the date of the Saturday in the week
 * given the date of the Monday
 *
 * Loh Wan Xin
 * B02
 */

#include <stdio.h>

int compute_saturday (int);

int main(void)
{
	int day, month, year;
	int saturday;

	printf("Enter date of a Monday as <year month day>: ");
	scanf("%d %d %d", &year, &month, &day);

	saturday = compute_saturday (day);
	switch (month)
	{	// For month's with 31 days
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (saturday>31)
		{
			month+=1;
			saturday=saturday-31;
		}
		break;

		// For month's with 30 days
		case 4: case 6: case 9: case 11:
		if (saturday>30)
		{
			month+=1;
			saturday=saturday-30;
		}
		break;
		case 2:
		if ((year%400==0) || ((year%4==0) && (year%100!=0))){
			// it is a LEAP year
			if (saturday>29){
				month+=1;
				saturday=saturday-29;}
		}
		else {
			// NOT a LEAP year
			if(saturday>28){
				month+=1;
				saturday=saturday-28;
			}
		}
		break;
	}

	if (month>12)
	{	year+=1;
		month=month-12;
	}


	printf("The date of Saturday in that week is: "
			"%d-%d-%d\n", year, month, saturday);

	return 0;
}

int compute_saturday (int d)
{
	return d+5;
}
