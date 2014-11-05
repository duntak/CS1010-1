#include <stdio.h>

int main(void)
{
	int price, arrival, leave;

	printf("Enter arrival time: ");
	scanf("%d", &arrival);

	printf("Enter leave time: ");
	scanf("%d", &leave);

	price = (leave - arrival) * 2;

	if (price >= 10)
		price = 10;
	
	printf("Your fare is: $%d\n", price);

	return 0;

}
