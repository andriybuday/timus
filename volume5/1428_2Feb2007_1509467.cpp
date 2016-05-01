//1428_AC
#include <stdio.h>
#include <cmath>
int main()
{

	double a, b, c;

	scanf("%lf%lf%lf", &a, &b, &c);

	printf("%.0lf\n%.0lf\n2\n", pow(2.0, (c-1.0)/a), pow(2.0, (c-1.0)/b));

}