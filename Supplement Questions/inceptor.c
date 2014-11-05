// CS1010 AY2011/2 Semester 2
// Mock PE2 Ex1: inceptor.c
// Original author: A/P Khoo Siau Cheng
// Modified by: Zhou Lifeng
//
// Program description: Harray Potter and The Order of Recursion
//
// Loh Wan Xin A0085925U

/*
   Student Happiness Index (SHI):

   1 means very happy during exam
   2 means moderately happy during exam
   3 means moderately stressed up during exam
   4 means very stressed up during exam
   5 means I am going to cry!

   Your SHI: 2
 */


#include <stdio.h>

#define NUM 50

// function prototypes
void rdup(int, int);
int subseq(int [], int, int [], int);

// main function, complete
int main(void)
{
	// Task 1 //

	int num, digit;

	printf("Please enter a positive integer: ");
	scanf("%d", &num);

	printf("Please enter the digit to be ignored: ");
	scanf("%d", &digit);

	// call rdup function to print
	printf("The reversed duplicated number with %d ignored is ", digit);
	rdup(num, digit);
	printf(".\n");
	

	// Task 2 //

	int i, j, k, size;
	// base is fixed
	int base[NUM] = {  36, 35, 27, 31,  1, 33, 10, 34, 16,  9,
		38,  5, 28, 11, 29,  5, 25, 20,  2,  4,
		9, 16,  7, 17, 30, 29,  1,  3,  9, 17,
		7, 16,  7,  6, 19, 19, 25, 15,  1,  4,
		9,  0,  3, 38,  2, 21, 18, 27, 12, 30 };

	int pat[NUM];

	// Print large array: base[]
	printf("The base array is:\n");
	printf("[\n");
	i = 0;
	for (j=0; j<5; j++)
	{
		for (k=0; k<(NUM/5) && i<NUM; k++)
			printf("%3d",base[i++]);
		printf("\n");
	}
	printf("]\n");

	// read pattern
	printf("Enter the size of a pattern: ");
	scanf("%d", &size) ;
	printf("Enter the pattern of %d elements: ", size);
	for (i=0; i<size; i++)
		scanf("%d", &pat[i]);
	printf("\n");

	// print out the result of search
	if ( subseq(base, NUM, pat, size) )
		printf("The pattern is found in the base.\n");
	else
		printf("The pattern is NOT found in the base.\n");

	return 0;
}

// duplicate every digits, but ignore 'digit'
// recursively print it out reversely
void rdup(int number, int digit)
{
	if (number%10==digit)
		rdup(number/10,digit);
	else if (number>=10){
		printf("%d%d", number%10,number%10);
		rdup(number/10,digit);
	}
	else if (number>0)
		printf("%d%d", number,number);

}

// recursive function to check sub sequence
int subseq(int base[], int base_length, int pattern[], int pattern_length)
{
	int i, found = 0;
	
	if (pattern_length==1)
	{
		for(i=base_length-1;i>=0;i--)
			if(base[i]==pattern[pattern_length-1]){
				//printf("index of %d: %d\n", base[i], i);
				return 1;
			}
	}

	else
	{
		for(i=base_length-1;i>=0;i--)
			if(base[i]==pattern[pattern_length-1]){
				found=1;
				//printf("index of %d: %d\n", base[i], i);
				break;
			}
	}
	
	if (found && subseq(base,i,pattern,pattern_length-1))
			return 1;
		else
			return 0;
	
}
