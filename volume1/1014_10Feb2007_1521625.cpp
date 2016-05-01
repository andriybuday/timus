//1014_AC
#include <stdio.h>
unsigned long N;
int ind;
char buf[51];
int main()
{
	int i,n;
	scanf("%lu",&N);
	if (N<10) 
	{
		if(N==0)
		{
			printf("10\n");
			return 0;
		}
		else
			printf("%lu\n",N);
		return 0;
	}
	buf[49] = 0;
	ind = 48;
	for (;;)
	{
		n=1;
		for (i = 9; i >= 2; i--)
			if (N%i == 0)
			{
				n=0;
				N/=i;
				buf[ind--] = i + '0';
				break;
			}
		if (N==1) break;
		if (n)
		{
			printf("-1\n");
			return 0;
		}
	}
	printf("%s\n",buf+ind+1);

	return 0;
}