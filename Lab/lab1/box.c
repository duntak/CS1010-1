/**
 * CS1010 AY2011/2 Semester 2 Lab1 Ex1
 *
 * box.c
 * This program calculates the surface area of a box, and the
 * length of the diagonal connecting two vertices furthest apart.
 *
 * Loh Wan Xin
 * B02
 */

#include <stdio.h>
#include <math.h>

double compute_surface_area (double, double, double);
double compute_diagonal (double, double, double);

int main(void)
{
	int length, width, height, surface_area;
	double diagonal;

	printf("Enter length: ");
	scanf("%d", &length);

	printf("Enter width : ");
	scanf("%d", &width);

	printf("Enter height: ");
	scanf("%d", &height);

	surface_area = compute_surface_area (length, width, height);
	diagonal = compute_diagonal (length, width, height);

	printf("Surface area = %d\n", surface_area);
	printf("Diagonal = %.2f\n", diagonal);

	return 0;
}

//Compute surface area
double compute_surface_area (double length, double width, double height)
{
	double area;
	area = 2*length*width + 2*length*height + 2*width*height;

	return area;
}

//Compute diagonal of the box
double compute_diagonal (double box_length, double box_width, double box_height)
{
	double sum_square;

	sum_square = pow(box_length,2)+ pow(box_width,2) + pow(box_height,2);

	return sqrt(sum_square);
}
