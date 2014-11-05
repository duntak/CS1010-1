// hilo.c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototype
void start_game(int);

int main(void)
{
	int secret_num;
	char choice;

	srand(time(NULL));

	printf("The secret number is between 1 and 100.\n");
	do {
		secret_num = rand()%100 + 1;
		start_game(secret_num);
		printf("\nDo you want to play again (y/n)? ");
		scanf(" %c", &choice);  // avoid white space problem
	} while (choice == 'y');

	printf("\nThanks for playing. Bye!\n");

	return 0;
}

void start_game(int secret)
{
	int attempts = 1, guess;
	while (attempts <= 5)
	{
		printf("Enter your guess [%d]: ", attempts);
		scanf("%d", &guess);
		if (guess < secret)
			printf("Your guess is too low!\n");
		else if (guess > secret)
			printf("Your guess is too high!\n");
		else
		{
			printf("Congratulations! Your did it in %d steps.\n", attempts);
			return;  // game over, return immediately
		}
		attempts++;
	}
	// tried out all 5 chances
	printf("Too bad. The number is %d. Better luck next time!\n", secret);
}
