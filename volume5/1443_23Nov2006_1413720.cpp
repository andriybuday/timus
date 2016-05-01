#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	double sss, lll;
	scanf("%lf%lf", &sss, &lll);


	__int64 N = n;
	__int64 S = __int64(sss*10000);
	__int64 L = __int64(lll*10000);

	__int64 k = ( S/L )*N;

	__int64 z = S%L;

	if(z == 0)
	{
		printf("%d", k);
		return 0;
	}

	__int64 l = L/z;//amount of parts in one rai

	//N

	k += N/l;
	

	if(N % l)k++;

	printf("%I64d", k);


	return 0;
}