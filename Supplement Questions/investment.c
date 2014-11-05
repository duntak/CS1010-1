/**
 * CS1010 AY2011/2 Semester 2 Supplement 1
 *
 * investment.c
 * This program calculates the amount of money in bank after N years.
 *
 * <Neo Han Wei>
 * <Discussion Group 2>
 */

#include <stdio.h>
#include <math.h>

int main(void)
{
	double prince, interest, amt; 
	int year;

	printf("Enter principal amount: ");
	scanf("%lf", &prince);

	printf("Enter interest rate: ");
	scanf("%lf", &interest); 

	printf("Enter number of years: ");
	scanf("%d", &year);

	amt = (prince * (1 - pow(interest/100, year+1)))/(1- interest/100);

	printf("Amount = $%.2lf\n", amt);

	return 0;
}
