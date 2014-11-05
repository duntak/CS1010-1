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
#define MAX_NBR_STRS   10

int hamming_distances(char [][MAX_STR_LENGTH+1], int, int []);

int main(void)
{
	char dna_str[MAX_NBR_STRS][MAX_STR_LENGTH+1];
	int i, num, len, gate=1, dist[MAX_NBR_STRS]= {0};
	int count;

	printf("Enter the number of DNA strings: ");
	scanf("%d", &num);
	getchar();                   // get rid of the whitespace in buffer ***IMPT***
	for (i=0; i<num; i++)
	{
		printf("Enter string %d: ", i);
		fgets(dna_str[i], MAX_STR_LENGTH, stdin);
		if (i>= 1)
		{
			len = strlen(dna_str[i]);
			if (len != strlen(dna_str[i-1]))
			{
				gate = 0;
				break;
			}
		}
	}

	if (gate == 1)
	{
		count = hamming_distances(dna_str, num, dist);
		for (i=0; i<count; i++)
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

int hamming_distances(char dna_str[][MAX_STR_LENGTH+1],
		int size, int dist[])
{
	int i, count=0, j, k, len;
	len = strlen(dna_str[0]);
	
	for (i=0; i<size; i++)
	{
		for (j=i+1; j<size; j++)
		{
			for (k=0; k<len; k++)
			{
				if(dna_str[i][k] != dna_str[j][k])
					dist[count]++;
			}
			count++;
		}
	}
//	printf("%d", count);
	return count;
}
