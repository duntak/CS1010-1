#include <stdio.h>

int main(void)
{
	int spending, reward, miles, points;

	printf("Enter amount of spending in SGD: ");
	scanf("%d", &spending);

	printf("Enter type of rewards (1=double, 2=platinum): ");
	scanf("%d", &reward);

	if (reward == 1)
	{
		points = (spending / 8) * 10;
		miles = points / 8 * 5;
	}

	else if (reward == 2)
	{
		points = (spending / 8) * 5 * 10;
		miles = points / 8 * 5;
	}

	printf("Your spending is: SGD %d\n", spending);
	printf("Type of rewards: %d\n", reward);
	printf("Number of points earned: %d\n", points);
	printf("Number of miles earned: %d\n", miles);

	return 0;
}
