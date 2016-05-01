#include <stdio.h>
#include <math.h>

int main()
{
	__int64 R, ans = 0, i;
		scanf("%I64d", &R);
	__int64 kv_R = R*R;

	for(i = 0; i < R; i++)
	{
		int long_add = long( sqrt (double(kv_R) - i*i));
		if(long_add == sqrt (double(kv_R) - i*i))
		{
			ans += long_add;
		}
		else
		{
			ans += long_add + 1;
		}
	}


	printf("%I64d\n", 4*ans);

	return 0;
}