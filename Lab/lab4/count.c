#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void)
{	
	int count=0;
	char str[30+1];


	printf("Enter a line: ");
	scanf("%s", str);
	
	char *p = strstr(str,"the");

	//printf("%s\n",p);
	
	while (p)
	{
		count++;
		p++;
		p = strstr(p,"the");
		
		//printf("%s\n",p);
	}

	printf("number of ""the"": %d\n", count);
	return 0;
}
