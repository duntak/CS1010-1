/**
 * CS1010 AY2011/2 Semester 2 Lab3 Ex2
 *
 * bisection.c
 * Description: Asks the user to enter integer cofficients of
 *				a polynomial of degree 3 and two end points.
 *				Compute the root of a continuous function
 *
 * Name: Loh Wan Xin
 * Discussion Group: B02
 */

#include <stdio.h>
#include <math.h>
#define THRESHOLD 0.0001

double polynomial(double, int, int, int, int);

int main(void)
{
	int    c3, c2, c1, c0; // coefficients of polynomial
	// int i=1; Use for checking
	double a, b,           // endpoints
		   pA, pB;       // function values at endpoints
	double m, pM;          // midpoint and function value at midpoint

	printf("Enter coefficients (c3,c2,c1,c0) of polynomial: ");
	scanf("%d %d %d %d", &c3, &c2, &c1, &c0);

	printf("Enter endpoints a and b: ");
	scanf("%lf %lf", &a, &b);

	do
	{
		m=(a+b)*0.5;
		pM = polynomial(m,c3,c2,c1,c0);

		pA = polynomial(a,c3,c2,c1,c0);
		pB = polynomial(b,c3,c2,c1,c0);
		/* For checking purposes
		   printf("#%d: a = %f; b = %f; m = %f\n"
		   "\t p(a) = %f; p(b) = %f; p(m) = %f\n", i,a,b,m,pA,pB,pM);	
		   i++;
		 */
		if ( fabs(a-b)<THRESHOLD || pM==0 )
			break;

		if (pB>0){
			if (pM>0)
				b=m;
			else
				a=m;
		}
		else{
			if (pM>0)
				a=m;
			else
				b=m;
		}
	} while (1);


	printf("root = %f\n", m);
	printf("p(root) = %f\n", pM);

	return 0;
}

// Compute the polynomial function value given x
double polynomial (double x, int c3, int c2, int c1, int c0)
{
	double funcValue;

	funcValue = c3*pow(x,3)+c2*pow(x,2)+c1*x+c0;

	return funcValue;
}
