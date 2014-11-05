#include <stdio.h>

int main(void)
{
	int h1, h2, m1, m2, s1, s2;
	int d1, d2, d3;

	scanf("%d %d %d", &h1, &m1, &s1);
	scanf("%d %d %d", &h2, &m2, &s2);

	if (s1 > s2)
	{
		m2--;
		d3 = s2 + 60 - s1;
		
		if (m1 > m2)
		{
			d2 = m2 + 60 - m1;
			h2--;
			d1 = h2 - h1;
		}
		else 
		{
			d2 = m2 - m1;
			d1 = h2 - h1;
		}
	}
	else 
	{
		d3 = s2 - s1;

		if (m1 > m2)
		{
			d2 = m2 + 60 - m1;
			h2--;
			d1 = h2 - h1;
		}
		else 
		{
			d2 = m2 - m1;
			d1 = h2 - h1;
		}
	}

	printf("Time difference: %02d:%02d:%02d\n", d1, d2, d3);

	return 0;
}
