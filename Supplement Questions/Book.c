//* S1010 AY2011/2 Semester 2 Lab2 Ex4
//*
//* book.c
//* <Fill in a description of this program>
//*
//* <Type your name here>
//* <Type your discussion group here>
//*
#include <stdio.h>
#include <math.h>
#define depre 0.9

int main(void)
{
	double initialPrice,    // initial price of a book
		   finalPrice;      // final price of a book

	int numEdition1 = 0,    // number of books of edition 1
		numEdition2 = 0,    // number of books of edition 2
		numEdition3 = 0,    // number of books of edition 3
		numEdition4 = 0,    // number of books of edition 4
		numEdition5 = 0;    // number of books of edition 5
	int num_books, i, year, edition;

	printf("Enter number of books: ");
	scanf("%d", &num_books);

	for (i=1; i <= num_books; i++)
	{
		// read info. of a book
		printf("Book %d\n", i);
		printf("\tEdition: ");
		scanf("%d", &edition);

		printf("\tYear of publish: ");
		scanf("%d", &year);

		printf("\tInitial price: ");
		scanf("%lf", &initialPrice);

		// calculate final price of a book
		// 1. If the depreciated price falls below $20, restore the final
		//    price to $20;
		// 2. If the initial price is below $20, then keep the final
		//    price the same as the initial price.
		finalPrice = initialPrice * pow(depre, 2012 - year);

		if (finalPrice < 20.00)
			finalPrice = 20.00;
		if (initialPrice < 20.00)
			finalPrice = initialPrice;


		// print out final price of a book
		printf("\tFinal price: %.2f\n", finalPrice);


		// update edition statistics
		if (edition == 1)
			numEdition1++;
		else if (edition == 2)
			numEdition2++;
		else if (edition == 3)
			numEdition3++;
		else if (edition == 4)
			numEdition4++;
		else if (edition == 5)
			numEdition5++;





	} // end of for loop


	// print out edition statistics

	printf("Number of edition 1 books: %d\n", numEdition1);
	printf("Number of edition 2 books: %d\n", numEdition2);
	printf("Number of edition 3 books: %d\n", numEdition3);
	printf("Number of edition 4 books: %d\n", numEdition4);
	printf("Number of edition 5 books: %d\n", numEdition5);
	return 0;
}
