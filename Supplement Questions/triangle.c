#include <stdio.h>

int main(void)
{
	int side1, side2, side3;

	scanf("%d %d %d", &side1, &side2, &side3);


	if ((side1 >= side2 + side3) || (side2 >= side1 + side3) || (side3 >= side1 + side2))
	{
		printf("not a triangle\n");
	}
	else
	{
		if ((side1 != side2) && (side2 != side3) && (side3 != side1))
		{	
			printf("scalene\n");
		}
		else if ((side1 == side2) && (side2 == side3) && (side3 == side1))
		{
			printf("equilateral\n");
		}  
		else if ((side1 == side2)|| (side2 == side3) || (side1 == side3))
		{
			printf("isoceles\n");
		}
	}
		return 0;
}
