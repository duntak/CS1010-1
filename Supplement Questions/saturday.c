/**
 * CS1010 AY2011/2 Semester 2 Lab1 Ex4
 *
 * saturday.c
 * Find the date of the next saturday
 *
 * Neo Han Wei
 * DG 8
 */

#include <stdio.h>

int main(void)
{
	int day, month, year;
	int day1, month1, year1;

	printf("Enter date of a Monday as <year month day>: ");
	scanf("%d %d %d", &year, &month, &day);

	switch (month){
		case 1: case 3: case 5: case 7: case 8: case 10:
			if (day + 5 > 31)
			{	month1 = month + 1;
				day1 = day + 5 - 31;
				printf("The date of Saturday in that week is: %d-%d-%d\n", year, month1, day1);}
			else
			{	day1 = day + 5;
				printf("The date of Saturday in that week is: %d-%d-%d\n", year, month, day1);}
				break;
		case 4: case 6: case 9: case 11:
				if (day + 5 > 30)
				{	month1 = month + 1;
					day1 = day + 5 - 30;
					printf("The date of Saturday in that week is: %d-%d-%d\n", year, month1, day1);}
				else 
				{	day1 = day + 5;
					printf("The date of Saturday in that week is: %d-%d-%d\n", year, month, day1);}
					break;
		case 2:
					if (((year % 400 == 0) || ((year % 4 ==0) && (year % 100 !=0))) && (day + 5 > 29))
					{	month1 = month + 1;
						day1 = day + 5 - 29;
						printf("The date of Saturday in that week is: %d-%d-%d\n", year, month1, day1);}
					else if ((year % 400 != 0) && (day + 5 > 28))
					{	month1 = month + 1;
						day1 = day + 5 - 28;
						printf("The date of Saturday in that week is: %d-%d-%d\n", year, month1, day1);}
					else if (((year % 400 != 0) || (year % 400 != 0 )) && (day + 5 < 28))
					{	day1 = day + 5;
						printf("The date of Saturday in that week is: %d-%d-%d\n", year, month, day1);}
						break;
		case 12:
					if (day + 5 > 31)
					{	month1 = month - 11;
						day1 = day + 5 - 31;
						year1 = year + 1;
						printf("The date of Saturday in that week is: %d-%d-%d\n", year1, month1, day1);}
					else 	
					{	day1 = day + 5;
						printf("The date of Saturday in that week is: %d-%d-%d\n", year, month, day1);}
						break;}
						return 0;
}	
