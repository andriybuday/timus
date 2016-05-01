//1192
#include <stdio.h>
#include <math.h>
#define pi 3.1415926535
int main()
{
	int v, a;
	
	double k;

	scanf("%d%d%lf", &v, &a, &k);

	printf("%.2lf", sin(a*pi/180.0) * cos(a*pi/180.0) * v * v * (k / (k - 1.0)) / 5.0);

	return 0 ;
}


//double len = sin(a*pi/180.0) * cos(a*pi/180.0) * v * v * (k / (k - 1.0)) / 5.0;