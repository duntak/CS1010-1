#include <stdio.h>

int main(void)
{
	int min, hours, minutes;

	printf("Enter time in minutes: ");
	scanf("%d", &min);

	hours = min / 60;
	minutes = min % 60;

	printf("%d hours and %d minutes.\n", hours, minutes);

	return 0;
}
