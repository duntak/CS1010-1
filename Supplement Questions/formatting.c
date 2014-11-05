#include <stdio.h>

int main(void)
{
	char character;
	int integer;
	double floating;

	scanf("%c %d %lf", &character, &integer, &floating);
	printf("'%c''%5d''%5.4lf'\n", character, integer, floating);

	return 0;

}
