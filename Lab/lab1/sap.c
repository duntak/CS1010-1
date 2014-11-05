/**
 * CS1010 AY2011/2 Semester 2 Lab1 Ex2
 *
 * sap.c
 * Calculating how well an undergraduate in NUS should do
 * to meet their target Cumulative Average Point(CAP)
 *
 * Loh Wan Xin
 * B02
 */

#include <stdio.h>

float compute_sap(int, float, int, float);

int main(void)
{
	int mcAttempted, mcAttempting;
	float capCurrent, capTarget, sap;

	printf("Enter MCs attempted and current CAP: ");
	scanf("%d %f", &mcAttempted, &capCurrent);

	printf("Enter MCs attempting and target CAP: ");
	scanf("%d %f", &mcAttempting, &capTarget);

	sap = compute_sap(mcAttempted, capCurrent, mcAttempting, capTarget);

	if (sap > 5.0)
		printf("Mission impossible!\n");

	else
		printf("SAP >= %.2f\n", sap);

	return 0;
}

// Compute Targetted Semester Average Point
float compute_sap(int mc_attempted, float current_cap, int mc_attempting, float target_cap)
{
	float point;
	point=(target_cap*(mc_attempted+mc_attempting)-(mc_attempted*current_cap))/mc_attempting;

	return point;
}
