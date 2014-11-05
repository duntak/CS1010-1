#include <stdio.h>

int main(void)
{
	int i, count, dash = -1;

	printf("Enter count: ");
	scanf("%d", &count);
	for (i=0; i != count; i++)
	{
		printf("#");
		while (dash != i)
		{
			printf("-");
			dash++;
		}
		dash = -1;
	}
	printf("\n");

	return 0;
}
