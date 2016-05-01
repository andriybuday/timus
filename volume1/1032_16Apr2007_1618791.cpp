//1032_AC
#include <stdio.h>
#define PARASHA -5555
int a[10005];
int b[10005];
int c[10005];
int main()
{
	int n, i, j, el, s = 0;
	for(i = 0; i <= 10004; ++i)c[i] = PARASHA;

	scanf("%d", &n);

	c[0] = 0;

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &el);
		a[i] = el;
		s += el;
		s %= n;
		b[i] = s;
		if(c[s] == PARASHA)c[s] = i;
		else
		{
			printf("%d\n", i-c[s]);
			for(j  = c[s]+1; j <= i; ++j)
			{
				printf("%d\n", a[j]);
			}
			return 0;
		}
	}
	return 0;
}