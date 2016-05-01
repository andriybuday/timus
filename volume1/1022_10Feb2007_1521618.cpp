//1022_SB
#include <stdio.h>
int b[102];
int g[103][103];
int main()
{
	int i,j,k,n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &j);
		while (j != 0)
		{
			++b[j];
			g[j][i] = 1;
			scanf("%d", &j);
		}
	}

	for (i = 1; i <= n; i++)
	{
		j = 1;

		while (b[j] != 0) ++j;

		printf("%d ", j);
		b[j] = 256256256256;
		for( k = 1; k <= n; k++)
		{
			if (g[k][j] == 1)--b[k];
		}
	}

	printf("\n");
	return 0;
}