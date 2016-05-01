#include <stdio.h>
int t[102][4];
int order[103];
int n, i, K, Max, Time;
bool b;

int main()
{
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		scanf("%d%d%d", &t[i][1], &t[i][2], &t[i][3]);

	for(i = 1; i <= n; i++)
		order[i] = i;

	do
	{
		b = true;
		for(K = 1; K < n; K++)
			if (t[order[K]][1] > t[order[K+1]][1])
			{
				b = false;
				i = order[K];
				order[K] = order[K + 1];
				order[K + 1] = i;
			}
		if (b == true)break;
	}while(true);


	Time = t[order[1]][1] + t[order[1]][2];

	if (Time > t[order[1]][3])
	{
		Max = Time - t[order[1]][3];
		for (K = 2; K <= n; K++)t[order[K]][3] = t[order[K]][3] + Max;
	}
	for(i = 2; i<=n; i++)
	{
		if (Time < t[order[i]][1])Time = t[order[i]][1];
		Time = Time + t[order[i]][2];
		if (Time > t[order[i]][3])
		{
			Max = Time - t[order[i]][3] + Max;
			for (K = i + 1; K <= n; K++)
			{
				t[order[K]][3] = t[order[K]][3] + Time - t[order[i]][3];
			}
		}
	}

	printf("%d\n", Max);

	return 0;
}