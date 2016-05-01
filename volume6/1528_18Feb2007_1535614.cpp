//problem G_AC

#include <stdio.h>
int main()
{
	__int64 n = 1, p = 1;
	while(true)
	{
		scanf("%I64d%I64d",&n, &p);

		if(n == 0 && p == 0)break;

		__int64 answer = 1;
		for (int j = 1; j <= n; ++j)
		{
			answer *= (j%p);
			answer %= p;
		}
		printf("%I64d\n", answer);
	}
	return 0;
}