/**
 * CS1010 AY2011/2 Semester 2 Lab1 Ex1
 *
 * box.c
 * This program calculates the surface area of a box, and the
 * length of the diagonal connecting two vertices furthest apart.
 *
 * Neo Han Wei
 * Discussio Group 2
 */

#include <stdio.h>
#include <math.h>


int compute_surface_area(int ,int, int);
double compute_diagonal(double, double, double);
int main(void)
{
	int length, width, height;

	printf("Enter length: ");
	scanf("%d", &length);

	printf("Enter width : ");
	scanf("%d", &width);

	printf("Enter height: ");
	scanf("%d", &height);

	printf("Surface area = %d\n", compute_surface_area(length, width, height));

	printf("Diagonal = %.2f\n", compute_diagonal(length, width, height));

	return 0;
}
// calculate the surface area of the box

int compute_surface_area(int x, int y, int z)
{ 
	int area;	
	area = x * y * 2 + y * z * 2 + z * x * 2;
	return area;
}

//calculate the diagonal of the box

double compute_diagonal(double a, double b, double c)
{
	double diagonal;
	diagonal = pow( a * a + b * b + c * c, 0.5);
	return diagonal;
}
