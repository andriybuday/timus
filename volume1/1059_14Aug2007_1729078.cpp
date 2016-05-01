#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	if(n == 0)printf("0\n");
	else
	{
	printf("0\nX\n*\n");
	for(int i = 1; i < n; ++i)
		printf("%d\n+\nX\n*\n", i);
	printf("%d\n+\n", n);
	}
	
	return 0;
}