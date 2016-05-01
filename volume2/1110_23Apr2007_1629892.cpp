//1110_AC
#include <stdio.h>

int main()
{
	int n, m, y, x, i, temp, flag=0;

	scanf("%d %d %d", &n, &m, &y);

	for(x = 0; x < m; x++)
	{
		temp = x;
		for (i = 2; i <= n; i++)temp *= x,temp %= m;
		if (temp == y)
		{
			printf(" %d",x);
			flag = 1;
		}
	}

	if (!flag) printf("-1\n");

	return 0;
}