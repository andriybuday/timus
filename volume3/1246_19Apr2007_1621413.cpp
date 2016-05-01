//1246_AC
#include <stdio.h>
#include <math.h>
int a[200007], b[200007];
#define DOFIGA 99999999
int main()
{
	int n, i;
	scanf("%d", &n);
	int min_x = DOFIGA, min_y = DOFIGA, min_i = 0;
	for(i = 1; i <= n; ++i)
	{
		scanf("%d %d", &a[i], &b[i]);
		if(b[i] < min_y)
		{
			min_y = b[i];
			min_x = a[i];
			min_i = i;
		}
		else if(b[i] == min_y && a[i] < min_x)
		{
			
			min_x = a[i];
			min_i = i;
		}
	}
	a[n+1] = a[1];
	b[n+1] = b[1];
	a[0] = a[n];
	b[0] = b[n];
	
	int px =  a[min_i-1] - a[min_i],py = b[min_i-1] - b[min_i],nx = a[min_i+1] - a[min_i],ny = b[min_i+1] - b[min_i];

	int det = px*ny - py*nx;

	if(det < 0)printf("ccw");
	else printf("cw");

	return 0;
}