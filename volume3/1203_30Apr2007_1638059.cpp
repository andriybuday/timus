//1203_AC
#include <stdio.h>
int a[30003];
int main()
{
	int e, s, n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &s, &e);
		if (a[e] < s)a[e] = s;
	}
	for(int i = 1; i <= 30000; i++)
	{
		if(a[i] && a[a[i] - 1] + 1 > a[i-1])
			a[i] = a[a[i] - 1] + 1;
		else a[i] = a[i - 1];
	}
	printf("%d\n", a[30000]);
	return 0;
}