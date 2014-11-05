
/**
 * CS1010 AY2011/2 Semester 2 Lab5 Ex3
 *
 * hammingDistance.c
 *
 * <Type in description of program>
 *
 * <Type your name here>
 * <Type your discussion group here>
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LENGTH 30
#define MAX_NBR_STRS    6
#define START 0

int hamming_distances(char [][MAX_STR_LENGTH+1], int, int, int []);
void input_dist(char [][MAX_STR_LENGTH+1], int, int, int []);
int main(void)
{
	char dna_str[MAX_NBR_STRS][MAX_STR_LENGTH+1];
	int i, num, len, gate=1, dist[MAX_NBR_STRS]={0};
	
	printf("Enter the number of DNA strings: ");
	scanf("%d ", &num);

	for (i=0; i<num; i++)
	{
		printf("Enter string %d: ", i);
		fgets(dna_str[i], MAX_STR_LENGTH, stdin);
		if (i >= 1)
		{
			len = strlen(dna_str[i]);
			if (len != strlen(dna_str[i-1]))
			{
				gate = 0;
				break;
			}
		}
		printf("\n");
	}

	if(gate == 1)
	{
		for(i=0; i<num; i++)
		{
			dna_str[i][len-1] = 0;
		}
		hamming_distances(dna_str, num-1, num-1, dist);
		for(i=0; i<num; i++)
		{
			printf("The Hamming distance of pair %d is: %d.\n", i, dist[i]);
		}
	}
	else if (gate == 0)
	{
		printf("Strings are of unequal length.\n");
	}
	return 0;
}

void input_dist(char dna_str[][MAX_STR_LENGTH+1], int start, int size, int dist[])
{
	int i, k, trick;
	if (size == 0)
	{
		trick = start -1;
		for (i=start; i >= size; i--)
		{
			for (k=MAX_STR_LENGTH; k>=0; k--)
			{
				if (dna_str[size][k] != dna_str[i][k])
					dist[trick]++;
			}
			trick--;
		}
	}
	else 
	{
		trick = size + start;
		for (i=start; i>= size; i--)
		{
			for (k=MAX_STR_LENGTH; k>=0; k--)
			{
				if (dna_str[size][k] != dna_str[i][k])
					dist[trick]++;
			}
			trick--;
		}

	}
}

int hamming_distances(char dna_str[][MAX_STR_LENGTH+1], int start, int size, int dist[])
{
	if (size == 0)
	{
		input_dist(dna_str, start, size, dist);
	}
	else if (size > 0 && size < start)
	{
		input_dist(dna_str, start, size, dist);
		hamming_distances(dna_str, start, size-1, dist);

	}
	else
	{
		hamming_distances(dna_str, start, size-1, dist);
	}
	return 0;
}
