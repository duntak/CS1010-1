/**
 * CS1010 AY2011/2 Semester 2 Supplement 1
 *
 * bmi.c
 * This program calculates the bmi of a person.
 *
 * <Neo Han Wei>
 * <Discussion Group 2>
 */

#include <stdio.h>

int main(void)
{
	double mass, height, bmi;

	printf("Enter mass in kg: ");
	scanf("%lf", &mass);

	printf("Enter height in m: ");
	scanf("%lf", &height);

	bmi = mass / (height * height); 

	printf("Your bmi is = %lf\n", bmi);

	return 0;
}
