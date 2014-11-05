/**
 * CS1010 Supplementary Practice 
 *
 * rabbit.c
 *
 * This programs calculates whether a rabbit can jump
 * to the other side of the river.
 *
 * Written by: Lifeng
 */

#include <stdio.h>
#define MAX_JUMP 50

/* function prototype */
int count_jumps(int [], int);

int main(void)
{
	int rocks[21] = {0}, // start position and at most 20 rocks
		n,               // actual number of rocks
		i;               // counter for loop

	printf("Enter number of rocks: ");
	scanf("%d", &n);

	for (i=1; i<=n; i++)
		scanf("%d", &rocks[i]);

	printf("%d\n", count_jumps(rocks, n));

	return 0;
}

// return number of jumps needed, return -1 if impossible
int count_jumps(int rocks[], int n)
{
	int hop = 0,
		pos = 0, // position of buddy after each jump
		i;

	while (pos != n) // still not reach the other side of the river
	{
		i = pos;  // jump from current rock every time
		while ((i <= n) && ((rocks[pos] + MAX_JUMP) >= rocks[i]))
			// still in jump scope
			i++;
		i--;  // last reachable rock

		if (i == pos) // no rock within scope
			return -1;

		// else
		pos = i;
		hop++;
	}

	return hop;
}
