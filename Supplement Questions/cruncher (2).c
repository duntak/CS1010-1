#include <stdio.h>
#include <math.h>

int cal_sq_sum (int);
int cal_diff (int);
int count_triangular_num (int);

int main(void)
{
	int num, choice;

	printf("Enter a positive integer: ");
	scanf("%d", &num);

	do
	{
		printf("\n***** Select an option *****\n"
				"1. Compute sum of squares of individual digits\n"
				"2. Compute difference between largest and smallest digits\n"
				"3. Check the number of triangular numbers in range [1, %d]\n"
				"4. Read in another integer\n"
				"5. Exit\n"
				"Enter your choice: ", num);
		scanf("%d", &choice);
		printf("\n");

		switch (choice)
		{
			case 1:
				printf("The sum of squares of individual "
						"digits of %d is %d.\n", num, cal_sq_sum(num));
				break;
			case 2:
				printf("Difference between largest "
						"and smallest digits of %d is %d.\n", num, cal_diff(num));
				break;
			case 3:
				printf("There are %d triangular numbers "
						"in range [1, %d].\n", count_triangular_num(num), num);
				break;
			case 4:
				printf("Enter a positive integer: ");
				scanf("%d", &num);
				break;
			case 5:
				printf("Thank you and goodbye!\n");
				break;
		}
	} while (choice!=5);

	return 0;
}

// Compute and return the sum of squares
int cal_sq_sum(int num)
{
	int i, // Counter for loop
		sq_sum = 0;

	for (i=num;i>0;i/=10)
		sq_sum += pow(i%10,2);

	return sq_sum;
}

// Compute and return the difference between the largest digit and smallest digit in num
int cal_diff(int num)
{
	int i, digit, max_digit, min_digit;

	max_digit = num%10; // Let the first digit extracted be the max and min before comparing with the other digits
	min_digit = num%10;

	for(i=num;i>0;i/=10)
	{
		digit = i%10;
		max_digit = fmax(max_digit,digit);
		min_digit = fmin(min_digit,digit);
	}
	return max_digit - min_digit;
}

// Count the number of triangular numbers in the range [1,bound]
int count_triangular_num(int bound)
{
	int num = 1,
		diff = 2,
		count = 0;
	
	while (num<=bound)
	{
		count++;
		num += diff;
		diff++;
	}

	return count;
}
