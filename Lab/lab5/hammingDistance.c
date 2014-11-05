/* CS1010 AY2011/2 Semester 2 Lab5 Ex3
 *
 * hammingDistance.c
 *
 * to compute the Hamming Distance
 * of a list of DNA strings
 *
 * Loh Wan Xin
 * B02
 */

#include <stdio.h>
#include <string.h>

#define MAX_STR_LENGTH 30
#define MAX_NBR_STRS    6
#define MAX_PAIRS      15

int hamming_distances(char [][MAX_STR_LENGTH+1], int, int []);

int main(void)
{
	int i, // counter for loop
		n, // number of DNA strings
		dist[MAX_PAIRS+1] = {0};
	char dna_str[MAX_NBR_STRS][MAX_STR_LENGTH+1];

	printf("Enter the number of DNA strings: ");
	scanf("%d", &n);

	for (i=0;i<n;i++)
	{ 
		printf("Enter string %d: ", i);
		scanf("%s", dna_str[i]);
	}

	// for checking of dna string input
	/* for(i=0;i<n;i++)
	printf("dna string %d: %s\t"
				"length = %d\n", i,dna_str[i],strlen(dna_str[i]));
	*/

	if (hamming_distances(dna_str,n,dist)){
		i = 0;
		while (dist[i]!= -1)
		{
			printf("The Hamming distance of pair %d"
					" is: %d.\n", i, dist[i]);
			i++;
		}
	}
	else
		printf("Strings are of unequal length.\n");

	return 0;
}

// calculates the Hamming distances among all pairs
// and stores them in array dist
// return 0 if strings are of unequal distance
// return 1 otherwise
int hamming_distances(char dna_str[][MAX_STR_LENGTH+1],
		int size, int dist[])
{
	int i, j, check, len, dist_num = 0, count;

	for (i=0;i<size-1;i++)
		for (j=i+1;j<size;j++)
			if (strlen(dna_str[i])!=strlen(dna_str[j]))
				return 0;

	len = strlen(dna_str[0]);
	for (i=0;i<size-1;i++)
	{
		for (j=i+1;j<size;j++)
		{
			count = 0;
			for (check=0;check<len;check++)
			{
				/*
				printf("dna_str[%d][%d]=%c\t"
						"dna_str[%d][%d]=%c\n",
						i,a,dna_str[i][check],j,check,dna_str[j][check]);
				*/
				if (dna_str[i][check]!=dna_str[j][check])
					count++;
			}
			dist[dist_num++]=count;
		}
	}

	dist[dist_num] = -1;
	//for(i=0;i<dist_num;i++)
	//	printf("%d: %d\n", i,dist[i]);
	return 1;
}
