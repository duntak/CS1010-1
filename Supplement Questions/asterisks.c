#include <stdio.h>

int main(void)
{
	int i, j=1, k=1, n;

	printf("Enter n: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		for (k= n+i; k != n; k--)
		{
			printf("  ");
		}
		
		for (j=1; j != n; j++)
		{
			printf("**");
		}
		printf("*\n");
	}

	return 0;
}

