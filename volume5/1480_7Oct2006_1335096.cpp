#include <stdio.h>


int main()
{
	int N, i, j, beg, end;
	scanf("%d", &N);

	int count_N = N*N;
	int count_1 = 1;

	printf("%d\n", N*N + (N/2) + 1);

	for(i = 1; i <= N; i++)
	{
		if(i%2)
		{
			beg = 1; end = N;
		}
		else 
		{
			beg = 0; end = N-1;
		}

		for(j = beg; j <= end; j++)
		{
			if(j%2)
			{
				printf("%d ", count_N);
				count_N--;
			}
			else
			{
				printf("%d ", count_1);
				count_1++;	
			}
		}
		printf("\n");

	}



	return 0;
}