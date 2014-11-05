/**
 * CS1010 AY2011/2 Semester 2 Lab1 Ex2
 *
 * sap.c
 * find out how well they should do in the current cem to meet their target CAP
 *
 * Neo Han Wei
 * Discussion Group 2
 */

#include <stdio.h>

double compute_sap(int, int, float, float);
int main(void)
{
	float sap, capCurrent, capTarget;
	int mcAttempted, mcAttempting;

	printf("Enter MCs attempted and current CAP: "); 
	scanf("%d %f", &mcAttempted, &capCurrent);

	printf("Enter MCs attempting and target CAP: ");
	scanf("%d %f", &mcAttempting, &capTarget);

	sap = compute_sap(mcAttempted, mcAttempting, capCurrent, capTarget);

	if (sap > 5.00)
	{
		printf("Mission impossible!\n");
	}
	else
		printf("SAP >= %.2f\n", sap);

	return 0;
}

// compute sap

double compute_sap(int w, int x, float y, float z)
{
	float cap;
	cap = ((z * (w + x)) - (w * y))/ x;
	return cap;
}

