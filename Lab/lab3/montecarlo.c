/**
 * CS1010 AY2011/2 Semester 2 Lab3 Ex1
 *
 * montecarlo.c
 * Description: Prompt the user to enter the number of darts thrown.
 *				Through the use of a random number generator, determine the 
 *				number of darts that landed inside the unit circle's quadrant
 *				and use it to approximate the value of pi
 *
 * Name: Loh Wan Xin
 * Discussion Group: B02
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int throwDarts(int);
int land_Inside(void);

int main(void)
{
	int darts_total,   // number of darts to be thrown
		darts_inside;  // number of darts inside quadrant
	double approx_Pi;

	srand (time(NULL));

	printf("How many darts? ");
	scanf("%d", &darts_total);
	
	darts_inside = throwDarts(darts_total);
	printf("Darts landed inside unit circle's quadrant = %d\n", darts_inside);

	approx_Pi = 4.0000*darts_inside/darts_total;
	printf("Approximated pi = %.4f\n", approx_Pi);
	return 0;
}

// Compute and return the number of darts that landed inside the unit circle
int throwDarts(int darts_total)
{
	int i, // Counter for loop
		count = 0;

	for (i=1;i<=darts_total;i++)
		if (land_Inside())
			count++;

	return count;
}

// Check if the dart thrown landed inside the unit circle 
int land_Inside(void)
{
	double x,y;

	x = (double)rand()/RAND_MAX;
	y = (double)rand()/RAND_MAX;

	if (x*x+y*y<=1)
		return 1;
	else
		return 0;
}
