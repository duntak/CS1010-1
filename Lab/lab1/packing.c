/**
 * CS1010 AY2011/2 Semester 2 Lab1 Ex3
 *
 * packing.c
 * 
 * Finding the maximum number of slabs that can be packed into the tray
 * Loh Wan Xin
 * B02
 **/

#include <stdio.h>

int compute_max_slab (int, int, int, int);

int main(void)
{
	int trayLength, trayWidth, slabLength, slabWidth;
	int max_slabs;

	printf("Enter dimension of tray: ");
	scanf ("%d %d", &trayLength, &trayWidth);

	printf("Enter dimension of slab: ");
	scanf ("%d %d", &slabLength, &slabWidth);

	max_slabs = compute_max_slab(trayLength, trayWidth, slabLength, slabWidth);
	printf("Maximum number of slabs = %d\n", max_slabs);

	return 0;
}

// Compute maximum number of slabs
int compute_max_slab (int tray_length, int tray_width, int slab_length, int slab_width)
{
	int arrange_vertical, arrange_horizontal;
	arrange_vertical = (tray_length/slab_length)*(tray_width/slab_width);
	arrange_horizontal = (tray_length/slab_width)*(tray_width/slab_length);

	if (arrange_vertical >= arrange_horizontal)
		return arrange_vertical;

	else
		return arrange_horizontal;
}
