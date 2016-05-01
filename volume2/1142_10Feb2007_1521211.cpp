//1142_SB
#include <stdio.h>
int f[11];
int main()
{
	int k, n;
	f[0] = 1;
	for(int i = 1; i <= 10; i++)
	{
		k = 1;
		for(int p = 1; p <= i; p++)
		{
			k = k * (i - p + 1) / p;
			f[i] = f[i] + k * f[i - p];
		}
	}
	scanf("%d", &n);
	while(n != -1)
	{
		printf("%d\n", f[n]);
		scanf("%d", &n);	
	}
	return 0;
}