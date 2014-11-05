#include <stdio.h>

int main(void)
{
	int integer, i, minusone = 1, minustwo = 1, result;

	printf("Enter integer: ");
	scanf("%d", &integer);

	while (integer > 47)
	{
		printf("%d is too big, enter another integer: ", integer);
		scanf("%d", &integer);
	}

	if (integer == 1)
	{	printf("1\n");
	}
	else if (integer == 2)
	{	printf("1 1\n");
	}
	else if (integer >= 3)
	{
		printf("1 1 ");
		for (i = 2; i != integer; i++)
		{
			result = minusone + minustwo;
			printf("%d ", result);
			minustwo = minusone;
			minusone = result;
		}
		printf("\n");
	}
		return 0;
	
}
