#include <stdio.h>
#define SPEED 2

int time(int, int);
int main(void)
{
	int no, from, to;
	int update_level1 = 1, update_level2 = 1;
	int time_count1 = 0, time_count2 = 0;
	printf("Enter instruction: ");
	scanf("%d %d %d", &no, &from, &to);

	if (no == 1)
	{
		update_level1 = from - update_level1;
		time_count1 += update_level1;
		update_level1 = from - to;
		if (update_level1 < 0)
		{update_level1 *= -1;}

		time_count1 += update_level1;
		update_level1 = to;
	}

	else if (no == 2)
	{
		update_level2 = from - update_level2;
		time_count2 += update_level2;
		update_level2 = from - to;
		if (update_level2 < 0)
		{update_level2 *= (-1);
		}
		time_count2 += update_level2;
		update_level2 = to;
	}

	printf("Enter instruction: ");
	scanf("%d %d %d", &no, &from, &to);

	if (no == 1)
	{
		update_level1 = from - update_level1;
		if (update_level1 < 0)
		{			update_level1 *= (-1);
		}
		time_count1 += update_level1;
		update_level1 = from - to;
		if (update_level1 < 0)
		{			update_level1 *= (-1);
		}
		time_count1 += update_level1;
		update_level1 = to;
	}
	else if (no == 2)
	{
		update_level2 = from - update_level2;
		if (update_level2 < 0)
		{			update_level2 *= (-1);
		}
		time_count2 += update_level2;
		update_level2 = from - to;
		if (update_level2 < 0)
		{			update_level2 *= (-1);
		}
		time_count2 += update_level2;
		update_level2 = to;
	}

	printf("Elevator 1 took %d sec. and ended at level %d\n", time_count1*SPEED, update_level1);

	printf("Elevator 2 took %d sec. and ended at level %d\n", time_count2*SPEED, update_level2);

	return 0;
}
