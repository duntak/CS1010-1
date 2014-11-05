/**
 * CS1010 AY2011/2 Semester 2 Lab2 Ex4
 *
 * book.c
 * Calculate the final price of each book in 2012
 * and also count the number of books for each edition
 *
 * Loh Wan Xin
 * B02
 */

#include <stdio.h>
#define CURRENT_YEAR 2012

double compute_final(int,double);

int main(void)
{
	double initialPrice,    // initial price of a book
		   finalPrice;      // final price of a book

	int numEdition1 = 0,    // number of books of edition 1
		numEdition2 = 0,    // number of books of edition 2
		numEdition3 = 0,    // number of books of edition 3
		numEdition4 = 0,    // number of books of edition 4
		numEdition5 = 0;    // number of books of edition 5

	int i, numBooks, Edition, YearPublish;

	printf("Enter number of books: ");
	scanf("%d",&numBooks);

	for (i=1;i<=numBooks;i++)
	{
		// read info. of a book
		printf("Book %d\n", i);
		printf("\tEdition: ");
		scanf("%d",&Edition);

		printf("\tYear of publish: ");
		scanf("%d", &YearPublish);

		printf("\tInitial price: ");
		scanf("%lf",&initialPrice);

		// calculate final price of a book
		// 1. If the depreciated price falls below $20, restore the final
		//    price to $20;
		// 2. If the initial price is below $20, then keep the final
		//    price the same as the initial price.

		if (initialPrice<20)
			finalPrice=initialPrice;
		else
			finalPrice=compute_final(YearPublish,initialPrice);

		// print out final price of a book
		printf("\tFinal price: %.2f\n", finalPrice);


		// update edition statistics
		switch(Edition)
		{	
			case 1: numEdition1+=1; break;
			case 2: numEdition2+=1; break;
			case 3: numEdition3+=1; break;
			case 4: numEdition4+=1; break;
			case 5: numEdition5+=1; break;
		}
	}

	// print out edition statistics
	printf("Number of edition 1 books: %d\n",numEdition1);
	printf("Number of edition 2 books: %d\n",numEdition2);
	printf("Number of edition 3 books: %d\n",numEdition3);
	printf("Number of edition 4 books: %d\n",numEdition4);
	printf("Number of edition 5 books: %d\n",numEdition5);

	return 0;
}

// Compute the Final Price if Initial Price is more than 20
double compute_final(int yearPublish,double initialPrice)
{		
	double final;
	final=initialPrice;

	while(yearPublish<CURRENT_YEAR)
	{
		final = 0.90*final;
		yearPublish+=1;
	}
	if (final<20)
		final=20;

	return final;
}
