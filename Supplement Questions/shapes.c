/**
 * CS1010 Supplementary Practice 
 *
 * shapes.c
 *
 * This program prints three shapes.
 *
 * <name>
 */

#include <stdio.h>

// function prototypes
void draw_circle(void);
void draw_intersecting_lines(void);
void draw_rectangle(void);
void draw_triangle(void);
void draw_rocket_ship(void);
void draw_male_stick_figure(void);
void draw_female_stick_figure(void);

int main (void)
{
	/*
	 * NOTE: THE FOLLOWINGS SHOW HOW TO CALL A FUNCTION
	 * THAT TAKES NO PARRAMETER
	 * AND DOES NOT RETURN VALUE TO A CALLER.
	 */

	// draw rocket ship
	draw_rocket_ship();
	printf("\n\n\n");

	// draw male stick figure
	draw_male_stick_figure();
	printf("\n\n\n");

	// draw female stick figure
	draw_female_stick_figure();
	printf("\n\n\n");

	return  0;
}

void draw_rocket_ship()
{
	// your code below
	draw_triangle();
	draw_rectangle();
	draw_intersecting_lines();

}

void draw_male_stick_figure()
{
	// your code below
	draw_circle();
	draw_rectangle();
	draw_intersecting_lines();


}

void draw_female_stick_figure ( )
{
	// your code below
	draw_circle();
	draw_triangle();
	draw_intersecting_lines();


}

void draw_circle()
{
	printf("   **   \n");
	printf(" *    * \n");
	printf(" *    * \n");
	printf("   **   \n");
}

void draw_rectangle()
{
	printf(" ****** \n");
	printf(" *    * \n");
	printf(" *    * \n");
	printf(" *    * \n");
	printf(" ****** \n");
}

void draw_triangle()
{
	printf("   *    \n");
	printf("  *  *  \n");
	printf(" *    * \n");
	printf("********\n");
}

void draw_intersecting_lines()
{
	printf("   *    \n");
	printf("  *  *  \n");
	printf(" *    * \n");
	printf("*      *\n");
}
