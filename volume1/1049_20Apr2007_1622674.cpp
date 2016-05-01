//1049_Sb
#include <stdio.h>
//#include <math.h>
#define SIZE 10000
int divisors[SIZE + 5];
int main()
{
	int i, curr, j;
	for(i = 0; i < 10; ++i)
	{
		scanf("%d", &curr);
		for(j = 2; j < curr/2; ++j)
			if(!(curr%j))
			{
				++divisors[j];
				curr/=j;
				j = 1;
			}
		++divisors[curr];
	}

	int mult = 1;
	for(i = 2; i < SIZE; ++i)
	{
		if(divisors[i])
		{
			mult *= divisors[i] + 1;
			mult %= 10;
		}
	}

	printf("%d\n", mult);

	return 0;
}