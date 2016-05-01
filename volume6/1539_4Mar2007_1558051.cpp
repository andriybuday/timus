#include <cstdio>
#include <cmath>
//#include <iostream>
//using namespace std;
double a[103];
double b[103];
int main(){
	
	double tmp;int n, d, i;
	scanf("%d%d",&d,&n);

	double eps = 0.5;
	double eps2 = 0.49999999;
	eps *= 1.0/(pow(10.0, double(d)));
	eps2 *= 1.0/(pow(10.0, double(d)));
	
	for(i = 1; i <= n; ++i)
	{
		scanf("%lf", &tmp);
		a[i] = tmp + eps2;
		b[i] = tmp - eps;
	}
	bool good = false;
	int ans = 1;
	while(!good)
	{
		good = true;
		for(i = 1; i <= n; ++i)
		{
			if (floor(a[i]*ans) != ceil(b[i]*ans))
			{
				good = false;
				break;
			}
			
		}
		ans++;
	}
	--ans;
	printf("%d", ans);
	return 0;
}
/*
2 3
0.71
52.29
170.86
*/