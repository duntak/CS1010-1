/**
 * CS1010 AY2011/2 Semester 2 Lab2 Ex2
 *
 * candles.c
 * how many candles can alexandra burn in total, given two positive integers n and k
 *
 * Neo Han Wei
 * Disscussion Group 8
 */

#include <stdio.h>

int count_candles(int, int);
int main(void)
{
	int candle, residual;

	printf("Enter number of candles and \n"
			"number of residuals to make a new candle: ");
	scanf("%d %d", &candle, &residual);

	printf("Total candles burnt = %d\n", count_candles(candle, residual));

	return 0;
}

//calculate the total no. of candles burned

int count_candles(int candle, int residual)
{

	int count, residual_left;

	count=candle;
	residual_left =candle;
	while (residual_left  >= residual)
	{	
		count = count + residual_left/residual;
		residual_left = residual_left/residual + residual_left%residual;
	}

	return count;

}
