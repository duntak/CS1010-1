/**
 * CS1010 AY2011/2 Semester 2 Lab3 Ex2
 *
 * bisection.c
 * Computing the value of root of a function and its f(root)
 *
 * Neo Han Wei
 * Discussion Group 8
 */

#include <stdio.h>
#include <math.h>

#define threshold 0.0001

double polynomial(double, int, int, int, int);

int main(void)
{
	int c3, c2, c1, c0; // coefficients of polynomial
	double a, b,           // endpoints
		   pA, pB;         // function values at endpoints
	double m, pM;          // midpoint and function value at midpoint

	printf("Enter coefficients (c3,c2,c1,c0) of polynomial: ");
	scanf("%d %d %d %d", &c3, &c2, &c1, &c0);

	printf("Enter endpoints a and b: ");
	scanf("%lf %lf", &a, &b);

	m = (a + b)/2.0;
	pM = polynomial(m, c3, c2, c1, c0);
	pA = polynomial(a, c3, c2, c1, c0);
	pB = polynomial(b, c3, c2, c1, c0);
	
	while ((fabs(fabs(a)- fabs(b)) > threshold) &&  (pM != 0.0))	
	{
		if (pM < 0.0)
		{
			if (pA < 0.0)
				a = m;
			else if (pB < 0.0) 
				b = m;
		}
		else
		{
			if (pA >= 0.0)
				a = m;
			else if (pB >= 0.0)
				b = m;
		}
		m = (a + b)/2.0;
		pM = polynomial(m, c3, c2, c1, c0);
		pA = polynomial(a, c3, c2, c1, c0);
		pB = polynomial(b, c3, c2, c1, c0);

	} 

	printf("root = %f\n", m);
	printf("p(root) = %f\n", pM);

	return 0;
}


// computing the polynomial function value
double polynomial(double value, int c3, int c2, int c1, int c0)
{
	double result;

	result = (double)c3 * pow(value,3) + (double)c2 * pow(value,2) + (double)c1 * pow(value,1) + (double)c0;

	return result;
}

