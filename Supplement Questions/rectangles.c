/**
 * CS1010 AY2011/2 Semester 2 Lab3 Ex3
 *
 * rectangles.c
 * <Fill in a description of this program>
 *
 * <Type your name here>
 * <Type your discussion group here>
 */

#include <stdio.h>
#include <math.h>
#define OVERLAP -1
#define TOUCH 0
#define DISJOINT 1

// function prototypes
void adjustCorners(float *, float *, float *, float *);
void typeAndArea(float, float, float, float, 
		float, float, float, float, int *, float *);
int find_type(float, float, float, float, 
		float, float, float, float);

int main(void)
{
	int type;
	float rectAx1, rectAy1, rectAx2, rectAy2; // 1st rectangle
	float rectBx1, rectBy1, rectBx2, rectBy2; // 2nd rectangle
	float area; // overlapped area

	// read inputs
	printf("Enter one corner of 1st rectangle: ");
	scanf("%f %f", &rectAx1, &rectAy1);
	printf("Enter opp corner of 1st rectangle: ");
	scanf("%f %f", &rectAx2, &rectAy2);

	printf("Enter one corner of 2nd rectangle: ");
	scanf("%f %f", &rectBx1, &rectBy1);
	printf("Enter opp corner of 2nd rectangle: ");
	scanf("%f %f", &rectBx2, &rectBy2);

	// user may not enter bottom-left and top-right corners,
	// adjust the values so that these 2 corners are captured
	adjustCorners(&rectAx1, &rectAy1, &rectAx2, &rectAy2);
	adjustCorners(&rectBx1, &rectBy1, &rectBx2, &rectBy2);

	typeAndArea(rectAx1, rectAy1, rectAx2, rectAy2,
			rectBx1, rectBy1, rectBx2, rectBy2,
			&type, &area);

	printf("Rectangle A = ([%.1f, %.1f], [%.1f, %.1f])\n", 
			rectAx1,rectAy1, rectAx2, rectAy2);
	printf("Rectangle B = ([%.1f, %.1f], [%.1f, %.1f])\n", 
			rectBx1,rectBy1, rectBx2, rectBy2);

	// fill in your code below



	printf("Overlapped area = %.2f\n", area);

	return 0;
}

// after invocation,
// [*rect_x1, *rect_y1] will be bottom-left corner
// [*rect_x2, *rect_y2] will be top-right corner
void adjustCorners(float *rect_x1, float *rect_y1,
		float *rect_x2, float *rect_y2)
{
	// fill in your code below




}


// return type and overlapped area to the caller
void typeAndArea(float rectAx1, float rectAy1, float rectAx2, float rectAy2,
		float rectBx1, float rectBy1, float rectBx2, float rectBy2,
		int *type, float *overlapping_area)
{
	*type = find_type(rectAx1, rectAy1, rectAx2, rectAy2, 
			rectBx1, rectBy1, rectBx2, rectBy2);

	// fill in your code below



}


// return position of two rectangles: overlap(-1), disjoint(1), touch(0)
int find_type(float rectAx1, float rectAy1, float rectAx2, float rectAy2, 
		float rectBx1, float rectBy1, float rectBx2, float rectBy2)
{
	// now check their relative position
	if (rectAx1 > rectBx2 || rectAx2 < rectBx1 
			|| rectAy1 > rectBy2 || rectAy2 < rectBy1)
		return DISJOINT;
	else if ( rectAx1 == rectBx2 || rectBx1 == rectAx2 ||
			rectAy1 == rectBy2 || rectBy1 == rectAy2 )
		return TOUCH;
	else
		return OVERLAP;
}
