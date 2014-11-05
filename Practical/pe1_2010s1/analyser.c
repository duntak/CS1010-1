// CS1010 AY2010/1 Semester 1 PE1 Ex2
//
// analyser.c
// 
// This program receives a sequence of student marks and
// find max, min and average marks as well as printing 
// distribution and histogram.
// 
// Written by: Lifeng

#include <stdio.h>
//#include <math.h>

/* function prototypes */
void print_grade_frq(int, int, int, int, int);
void print_histogram(int, int, int, int, int);
int find_max(int, int, int, int, int);

int main(void)
{
	int mark, choice,                       // user's inputs
		max_mark = 0, min_mark = 100,       // min and max marks
		num_A, num_B, num_C, num_D, num_F,  // counters for grades
		total_stu = 0;                      // number of students
	float total_mark = 0;                   // total marks 
	// defined as float to avoid integer division problem

	num_A = num_B = num_C = num_D = num_F = 0; // initialize

	do
	{
		printf("Enter mark (negative number to end): ");
		scanf("%d", &mark);
		if(mark <0)  // end of input marks
			break;

		total_mark += mark; 
		total_stu++;

		if(mark > max_mark) // can also use math function fmin(), fmax()
			max_mark = mark;
		if(mark < min_mark)
			min_mark = mark;

		switch(mark/10)
		{
			case 10:
			case 8:
			case 9: num_A++;
					break;
			case 7: num_B++;
					break;
			case 6: num_C++;
					break;
			case 5: num_D++;
					break;
			default:num_F++;
		}
	} while(1); // loop termination condition inside (break)

	do
	{
		printf( "1. Show maximum and minimum marks\n"
				"2. Show average mark\n"
				"3. Show grade frequency table\n"
				"4. Show grade histogram\n"
				"5. Exit\n");
		printf("Select your choice: ");
		scanf("%d", &choice);
		printf("\n");
		switch(choice)
		{
			case 1: printf("The maximum and minimum are %d and "
							"%d respectively.\n", max_mark, min_mark);
					break;
			case 2: printf("The average mark is %.2f\n", 
							total_mark/total_stu);
					break;
			case 3: print_grade_frq(num_A, num_B, num_C, num_D, num_F); 
					break;
			case 4: print_histogram(num_A, num_B, num_C, num_D, num_F);
					break;
			default: printf("Thank you and goodbye!\n");
		}
		printf("\n");
	} while(choice != 5);

	return 0;
} 

// print the frequence distribution of student grades
void print_grade_frq(int num_A, int num_B, int num_C, int num_D, int num_F)
{
	printf("A:%d\nB:%d\nC:%d\nD:%d\nF:%d\n", 
			num_A, num_B, num_C, num_D, num_F);

}

// print out the histogram diagram
void print_histogram(int num_A, int num_B, int num_C, int num_D, int num_F)
{
	int i, max = find_max(num_A, num_B, num_C, num_D, num_F);
	for(i=max; i>0; i--)
	{
		printf("%d", i);
		if(num_F >= i)
			printf("  ***");
		else
			printf("     ");
		if(num_D >= i)
			printf("  ***");
		else
			printf("     ");		
		if(num_C >= i)
			printf("  ***");
		else
			printf("     ");		
		if(num_B >= i)
			printf("  ***");
		else
			printf("     ");		
		if(num_A >= i)
			printf("  ***");
		else
			printf("     ");
		printf("\n");
	}
	printf("     F    D    C    B    A\n");
}

// look for max number among 5 given integers
int find_max(int num_A, int num_B, int num_C, int num_D, int num_F)
{
	int max = num_A;
	if(num_B > max)
		max = num_B;
	if(num_C > max)
		max = num_C;
	if(num_D > max)
		max = num_D;
	if(num_F > max)
		max = num_F;
	// or you can use math function fmax
	//max = fmax(num_A, num_B);
	//...
	return max;
}
