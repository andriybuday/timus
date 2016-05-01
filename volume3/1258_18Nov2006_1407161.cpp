//1258_AC
#include <stdio.h>
#include <math.h>


int main()
{
	int i;

	double w,d;

	double x0,y0,x1,y1;

	scanf ("%lf%lf%lf%lf%lf%lf",&w,&d,&x0,&y0,&x1,&y1);

	char c[10000];

	scanf ("%s",c);

	for (i=0;c[i];i++)
	{
		if (c[i]=='F') y0=-y0;
		if (c[i]=='L') x0=-x0;
		if (c[i]=='B') y0=d+d-y0;
		if (c[i]=='R') x0=w+w-x0;
	}


	double dist = sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));

	printf ("%.4lf\n",dist);

	return 0;
}