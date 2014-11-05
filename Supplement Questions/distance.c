/**
 * CS1010 Supplementary Practice 
 *
 * distance.c
 *
 * This program calculates the distance between two points.
 *
 * <name>
 */

#include <stdio.h>
#include <math.h>

// function prototypes here

double root(double, double);
double square(double, double);
// main function is complete - no need to change
int main(void)
{
	double x1, y1, x2, y2;  // coordinates of two points
	double distance;        // distance between two points

	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);

	distance = root( square(x2, x1), square(y2, y1) );

	printf("The distance between the two points is %.2f\n", distance);

	return 0;
}


// calculate (a-b)^2
double square(double a, double b)
{
	return pow(a-b,2);  // stub, to be replaced by actual return value
}


// calculate square root of (a+b)
double root(double a, double b)
{
	return sqrt(a + b);  // stub, to be replaced by actual return value
}
