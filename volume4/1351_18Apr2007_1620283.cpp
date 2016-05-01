#include <stdio.h>
#include <math.h>
int main()
{
	double x1, x2, y1, y2, ang1, ang2;
	int r;
	scanf("%d%lf%lf%lf%lf", &r, &x1, &y1, &x2, &y2);
	r *= r;
	ang1 = atan2(y1, x1);
	ang2 = atan2(y2, x2);
	int n;
	scanf("%d", &n);
	int x, y;
	for(int i = 0; i < n; ++i)
	{
		scanf("%d%d", &x, &y);
		double curr  = atan2((double)y, (double)x);;
		if(curr <= ang2 && curr >= ang1)
			if(x*x + y*y <= r)
			{
				printf("YES\n");
				continue;
			}
			
		printf("NO\n");
	}
	

	return 0;
}
