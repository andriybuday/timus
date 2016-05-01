//1294AC
#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, d;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	a *= 1000;
	b *= 1000;
	c *= 1000;
	d *= 1000;
	if(a*b == c*d)
	{
		printf("Impossible.\n");
		return 0;
	}
	double ab = a*b;
	double cd = c*d;
	double a2b2 = a*a + b*b;
	double c2d2 = c*c + d*d;
	double x2 = 0;

	x2 = ((ab*c2d2 - cd*a2b2) / (ab - cd));

	double kv = sqrt(x2);
	int answ;
	if(kv - floor(kv) < 0.5555555555555555555)
	{
			answ = floor(kv);
	}
	else
		answ = ceil(kv);
	

	printf("Distance is %d km.\n", answ);


	return 0;
}