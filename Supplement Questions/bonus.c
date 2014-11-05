#include <stdio.h>

int main(void)
{
	int day, billable1, billable2, bonus;

	printf("Enter billable days: ");
	scanf("%d", &day);

	if ((day > 48) || ((day <= 48) && (day >= 41))) 
	{
		billable1 = (day - 40) * 550;
		billable2 = 325 * 8; 
	}
	else if ((day >= 33) && (day <=40))
	{
		billable1 = (day - 32) * 325;
	}
	else if (day < 33)
	{
		bonus = 0;
	}

	bonus = billable1 + billable2;

	printf("Bonus = $%d\n", bonus);

	return 0;
}
