/**
 * CS1010 AY2011/2 Semester 2 Lab1 Ex3
 *
 * packing.c
 * Arrange slabs in a tray.
 *
 * Neo Han Wei
 * Discussion Group 8
 */

#include <stdio.h>

int compute_max_slabs(int, int, int, int);
int main(void)
{
	int height1, height2, width1, width2;

	printf("Enter dimension of tray: ");
	scanf("%d %d", &height1, &width1);

	printf("Enter dimension of slab: ");
	scanf("%d %d", &height2, &width2);

	printf("Maximum number of slabs = %d\n", compute_max_slabs(height1, height2, width1, width2));

	return 0;
}

// calculate the max number of slabs

int compute_max_slabs(int w, int x, int y, int z)
{
	int m1, m2, m3;

	m1 = ( w / x ) * ( y / z );

	m2 = ( w / z ) * ( y / x);

	if (m1 > m2)
	{
		m3 = m1;
	}
	else 

		m3 = m2;

	return m3;

}
