//1113_AC
#include <stdio.h>
#include <math.h>
int m,n,t;
double out;
double way[32003];
int oil[32007];
int main()
{
	scanf("%d%d", &n, &m);
	way[1] = m;
	oil[1] = m;
	t = 2;
	while(double(way[t-1]) + double(m)/double(2*t-1) < double(n))
	{
		way[t] = way[t-1] + m/double(2*t-1);
		oil[t] = t*m;
		++t;
	}
	out = (n-way[t-1])*(2*t-1)+oil[t-1];

	if(out - floor(out) < 1e-8)printf("%.0lf", floor(out));
	else printf("%.0lf", floor(out) + 1);
	return 0;
}