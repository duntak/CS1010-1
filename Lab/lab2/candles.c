/**
 * CS1010 AY2011/2 Semester 2 Lab2 Ex2
 *
 * candles.c
 * find out how many candles can he burn in total,
 * given two positive integers n and k
 *
 * Loh Wan Xin
 * B02
 */

#include <stdio.h>

int count_candles (int,int);

int main(void)
{
	int num_candles, num_residuals, candles_burn;

	printf("Enter number of candles and \n"
			"number of residuals to make a new candle: ");
	scanf("%d %d", &num_candles, &num_residuals);

	candles_burn = count_candles (num_candles, num_residuals);

	printf("Total candles burnt = %d\n", candles_burn     );

	return 0;
}

// Calculate the number of candles that can be burned
int count_candles (int n,int k)
{
	int residual_left, count;

	count = n; // Initialise count = Number of candles
	residual_left = n;

	while (residual_left>=k) //when residual wax is more than k,new candles can be rolled out
	{
		count=count+residual_left/k; //adding new candles to the count
		residual_left = residual_left/k + residual_left%k;		
	}
	return count;
}
