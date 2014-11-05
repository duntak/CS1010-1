/**
 * CS1010 AY2011/2 Semester 2 Lab5 Ex1
 *
 * palindrome.c
 * <Check for palindrome>
 *
 * <Neo Han Wei>
 * <Discussion Group 8>
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 80
int is_palindrome(char [], int);

int main(void)
{
	int i, count=0, num, len;
	char string[MAX+1];

	printf("How many strings? ");
	scanf("%d ", &num);

	for (i=0; i<num; i++)
	{	
		fgets(string, 81, stdin);
		len = strlen(string);
		if (string[len-1] == '\n')
			string[len-1] = '\0';
		if (is_palindrome(string, len))
			count++;
	}
	printf("%d\n", count);
	return 0;
}

int is_palindrome(char string[], int len)
{
	int i, j, k=0, m=0;
	char string2[len];

	//	puts(string);

	for (i=0; i<len; i++)
	{
		if (isalpha(string[i]))
		{
			if (isupper(string[i]))
			{	
				string[m] = tolower(string[i]);
				m++;
			}
			else 
			{
				string[m] = string[i];
				m++;
			}
		}
		if (string[i] == '\0')
			string[m] = '\0';
	}

//	puts(string);
	len = strlen(string);

	for (j=len; j>-1; j--)
	{
		if (isalpha(string[j]))
		{
			string2[k] = string[j];
			k++;
		}
		if (j==0)
		{
			string2[k] = '\0';
			break;
		}
	}
//	puts(string2);

//	puts(string);
	
	if ((strcmp(string, string2)) == 0)
	{
		return 1;
	}
	else 
	{	
		return 0;
	}
}

