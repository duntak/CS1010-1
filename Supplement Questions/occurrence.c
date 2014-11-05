/**
 * CS1010 Supplementary Practice 
 *
 * occurrence.c
 *
 * This program counts the number of repetitive chars in a string.
 *
 * <name> 
 */

#include <stdio.h>
#include <string.h>

int occurrence(char str1[], char str2[]);

int main(void)
{
	char str1[100];      // input
	char str2[100];      // assume large enough

	scanf("%s", str1);   // no blank inside string
	scanf("%s", str2);   // no blank inside string

	printf("%d\n", occurrence(str1, str2));

	return 0;
}

// count the number of groups of repetitive chars
int occurrence(char str1[], char str2[])
{
	// hint: address arithmetic will be needed
	int count=0, i=0, len, lencheck;
	len = strlen(str2);
	lencheck = strlen(str1);
	lencheck = lencheck - len + 1;
	while (1)
	{
		if (!strncmp(str1+i, str2, len))
		{	count++;
			i += len-1;
		}
		i++;
		if (i == lencheck+1)
			break;

	}

	return count;  // stub
}
