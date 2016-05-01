//1200_AC
#include <stdio.h>
#include <math.h>
#define eps 0.001

int main()
{
	double A, B, Best = 0;
	int K;
	int Ba = 0, Bb = 0;
	
	scanf("%lf%lf%d", &A, &B, &K);

	double p, pb = 0.0;

	int a = K, b = 0;
	for (a = K; a >= 0; a--)
	{
		p = (K-a)*B - (K-a)*(K-a);
		if (p > pb+eps)
		{
			pb = p;
			b = K-a;
		}
		p = a*A - a*a + pb;
		if (p > Best-eps)
		{
			Best = p;
			Ba = a;
			Bb = b;
		}
	}

	printf("%.2lf\n%d %d\n", Best, Ba, Bb);
}