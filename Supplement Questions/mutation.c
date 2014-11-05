/**
 * CS1010 Supplementary Practice 
 *
 * mutation.c
 *
 * This program simulate the effects of mutations 
 * on a DNA string: Amplification, Deletion, Inversion 
 *
 * Written by: Lifeng
 */

#include <stdio.h>
#define MAX 1000

/* function prototypes */
// print dna array
void printDNA(char [], int);
// amplify dna portion
void ampDNA(char [], int, int, int);
// delete dna portion
void delDNA(char [], int, int, int);
// inverse dna portion
void invDNA(char [], int, int, int);

int main(void)
{
	int i,
		num = 0,    // number of dna
		n;          // number of mutations
	int pos1, pos2; // start, end positions of mutation
	char c, dna[MAX];

	do
	{
		scanf("%c", &c);
		if (c == '\n')
			break;
		dna[num++] = c;
	} while (1);

	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf(" %c %d %d", &c, &pos1, &pos2);

		switch (c)
		{
			case 'a': 
				ampDNA(dna, num, pos1, pos2);
				num += pos2 - pos1 + 1;  // update length
				break;
			case 'd':
				delDNA(dna, num, pos1, pos2);
				num -= pos2 - pos1 + 1;  // update length
				break;
			case 'i':
				invDNA(dna, num, pos1, pos2);
				break;
		}
	}
	printDNA(dna, num);

	return 0;
}

// print out DNA sequence
void printDNA(char dna[], int num)
{
	int i;
	for (i=0; i<num; i++)
		printf("%c", dna[i]);
	printf("\n");

	return;
}

// DNA amplification: insert duplicate copy of a region
void ampDNA(char dna[], int num, int pos1, int pos2)
{
	int i;
	for (i=num-1; i>pos2; i--)
		dna[i+(pos2-pos1+1)] = dna[i];
	for (i=pos1; i<=pos2; i++)
		dna[i+(pos2-pos1+1)] = dna[i];

	return;
}

// DNA deletion: delete the selected region
void delDNA(char dna[], int num, int pos1, int pos2)
{
	int i;
	for (i=pos2+1; i<num; i++)
		dna[i-(pos2-pos1+1)] = dna[i];

	return;
}

// DNA inversion: reverse the orientation of the specified region
void invDNA(char dna[], int num, int pos1, int pos2)
{
	int i;
	char temp;
	for (i=pos1; i<=pos2/2; i++)
	{
		temp = dna[i];
		dna[i] = dna[pos1+pos2-i];
		dna[pos1+pos2-i] = temp;
	}

	return;
}
