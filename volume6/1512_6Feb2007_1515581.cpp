//1512_SB
#include <stdio.h>

int main()
{
	int n, i;
	scanf("%d", &n);
	int remainder = n%12;
	int lastpos = 0;
	if(remainder == 3 || remainder == 9)
	{
		for(i = 4; i <= n; i += 2)printf("%d %d\n",(i-2)/2, i);
		printf("%d 2\n", (i-2)/2);
		lastpos = (i-2)/2;
	}
	else
	{
		for(i = 2; i <= n; i += 2)printf("%d %d\n",i/2, i);
		lastpos = i/2 - 1;
	}

	if(remainder == 3 || remainder == 9)
	{
		for(i = 5; i <= n; i += 2)
		{
			printf("%d %d\n", ++lastpos, i);
		}
		printf("%d 1\n", ++lastpos);
		printf("%d 3\n", ++lastpos);
		return 0;
	}
	if(remainder == 2)
	{
		printf("%d 3\n", ++lastpos);
		printf("%d 1\n", ++lastpos);
		for(i = 7; i <= n; i += 2)
		{
			printf("%d %d\n", ++lastpos, i);
		}
		printf("%d 5\n", ++lastpos);
		return 0;
	}
	if(remainder == 8)
	{
		for(int i = 1; i <= n; i += 4)
		{
			printf("%d %d\n", ++lastpos, i + 2);
			printf("%d %d\n", ++lastpos, i);
		}
		return 0;
	}
	
	for(i = 1; i <= n; i += 2)
	{
		printf("%d %d\n", ++lastpos, i);
	}

	return 0;
}