#include <stdio.h>

int main()
{
	int N, i;
	scanf("%d", &N);
	N = N>>1;

	if(N == 1)
	{
		printf("10");
		return 0;
	}

	if(N == 2)
	{
		printf("1090");
		return 0;
	}

	for(i = 0; i < N - 1; i++)printf("1");
	printf("0");
	for(i = 0; i < N - 2; i++)printf("8");
	printf("90");

	return 0;
}
