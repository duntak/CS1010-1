/**
 * CS1010 AY2011/2 Semester 2 Supplement 2
 *
 * bill.c
 * This program calculates the final bill after service charge and gst.
 *
 * <Neo Han Wei>
 * <Discussion Group 2>
 */

#include <stdio.h>
#include <math.h>
#define gst 0.07
#define service 0.10

int main(void)
{
	double bprice, fprice, sp, gp ;

	printf("Enter menu price: $");
	scanf("%lf", &bprice);

    sp = bprice * service;

	printf("10%% Service Charge: $%.2lf\n", sp);

    gp = (bprice + sp) * gst;

	printf("7%% GST: $%.2lf\n", gp); 

    fprice = bprice + gp + sp;

	printf("Your Total Bill: $%.2lf\n", fprice);

	return 0;
}
