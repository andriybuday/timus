//1017
#include <stdio.h>
__int64 a[502];
int main()
{
	int i, j, n;
	scanf("%d", &n);
	a[0] = 1;
	for(j = 1; j <= n; j++)
	{
		for(i = n; i >= j; i--)
		{
			a[i] = a[i] + a[i-j];
		}
	}
	a[n] = a[n] - 1;
	printf("%I64d", a[n]);

	return 0;
}
