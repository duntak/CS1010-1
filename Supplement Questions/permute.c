// Print out all permutations of a string

#include <stdio.h>
#include <string.h>

void permute(char [],int,int);
void swap(char *, char *);

int main(void) 
{ 
	char s[100]; 

	printf("Enter the string\n");
	scanf("%s",s);

	permute(s,0,strlen(s)-1);
	return 0;
}

void permute(char s[],int begin,int end)
{
	int k;
	if(begin==end)
	{
		printf("%s\n",s);
		return;
	}
	for(k=begin;k<=end;k++)
	{ 
		swap(&s[begin],&s[k]);
		permute(s,begin+1,end); 
		swap(&s[begin],&s[k]);
	}
}

void swap (char *x, char *y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}

