//1377_AC
#include <stdio.h>
#include <math.h>
int a[103][103];
void out(int n, int m)
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)printf("%d ", a[i][j]);
		printf("\n");
	}
}
int main()
{
	int n, m, counter = 1;
	scanf("%d%d", &n, &m);
	int left = 1, right = m;
	int roof = 1, floor = n;
	while (left <= right || roof <= floor)
	{
		for(int i = left; i <= right; i++)
		{
			if(i > 0 && roof > 0)
				if(!a[roof][i])
					a[roof][i] = counter++;
		}
		roof++;
		for(int i = roof; i <= floor; i++)
		{
			 if(i > 0 && right > 0)
				if(!a[i][right])
					a[i][right] = counter++;
		}
		right--;
		for(int i = right; i >= left; i--)
		{
			if(i > 0 && floor > 0)
				if(!a[floor][i])
					a[floor][i] = counter++;
		}
		floor--;
		for(int i = floor; i >= roof; i--)
		{
			if(i > 0 && left > 0)
				if(!a[i][left])
					a[i][left] = counter++;
		}
		left++;
	}
	//out(n, m);
	int x, y, first;
	scanf("%d%d", &x, &y);
	first = a[x][y];
	scanf("%d%d", &x, &y);
	printf("%d\n", abs(first - a[x][y]));

	return 0;
}
