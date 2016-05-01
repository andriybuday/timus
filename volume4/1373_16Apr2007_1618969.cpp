//1373_
#include <stdio.h>
#define DOFIGA 1e12
#define min(x,y) ( (x)<(y)?(x):(y) )
#define max(x,y) ( (x)>(y)?(x):(y) )
inline double min3i(double a,double b,double c)
{
	return min(a, min(b,c));
}
inline double max3i(double a, double b,double c)
{
	return max(a,max(b, c));
}
double X[3];
double Y[3];
int main()
{
	int x1, x2, y1, y2;
	double xr, yr, xmax, ymax, xmin, ymin;

	xmin = ymin = DOFIGA;
	ymax = xmax = -DOFIGA;

	while(scanf("%d %d %d %d", &x1, &y1, &x2, &y2) != EOF)
	{	

		xr = (x1 + x2 + y1 - y2)/2.0;
		yr = (-x1 + x2 + y1 + y2)/2.0;

		double maxx = max3i(x1,x2,xr);
		double minx = min3i(x1,x2,xr);

		double maxy = max3i(y1,y2,yr);
		double miny = min3i(y1,y2,yr);
		
		if(xmax < maxx)xmax = maxx;
		if(xmin > minx)xmin = minx;
		if(ymax < maxy)ymax = maxy;
		if(ymin > miny)ymin = miny;
	}


	if(xmax == -DOFIGA)printf("0.0000 0.0000\n");
	else
		printf("%.4lf %.4lf\n", xmax - xmin, ymax - ymin);

	return 0;
}