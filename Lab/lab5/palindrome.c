/* CS1010 AY2011/2 Semester 2 Lab5 Ex1
 *
 * palindrome.c
 * Read in a list of strings,
 * and for each input string,
 * determine if it is a palindrome
 *
 * Loh Wan Xin
 * B02
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 80

int is_palindrome(char []);
void clean_up(char []);

int main(void)
{
	int i, n, count = 0;
	char string[MAX];

	printf("How many strings? ");
	scanf("%d ", &n);

	for (i=0;i<n;i++) {
		fgets(string,MAX,stdin);
		if (is_palindrome(string))
			count++;
	}

	printf("%d\n", count);

	return 0;
}

// check if it is a palindrome
// return 1 if it is, 0 otherwise
int is_palindrome(char string[])
{
	int i, j, len;

	clean_up(string);
	// printf("%s\n", string);

	len = strlen(string);
	for (i=0,j=len-1; i<len/2;i++)
		if(string[i]!=string[j--])
			return 0;

	return 1;
}

// remove non-letters chars in phase,
// turn upper case letters to lower case letters
void clean_up(char string[])
{
	int i, j, len  = strlen(string);

	for (i=j=0; i<len; i++)
		if (isalpha(string[i])) // check letter
			string[j++] = tolower(string[i]);

	string[j] = '\0'; // to make it a string
}
