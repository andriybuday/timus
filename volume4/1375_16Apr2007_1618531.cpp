//1375_AC
#include <stdio.h>

int main()
{
	int i, j, k, p;
	scanf("%d%d", &k, &p);

	for (i = 0; i < 10000; ++i)
	{
		for (j = 0; j < 1000; ++j)
		{
			if((i*i + j*j)%p == k)
			{
				if(i < p && j < p)
				{
					printf("%d %d", i, j);
					return 0;
				}
			}
		}
	}
	printf("NO SOLUTION\n");
	return 0;
}