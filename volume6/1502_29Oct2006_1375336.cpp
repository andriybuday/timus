#include <stdio.h>
int main()
{
	__int64 n;
	scanf("%I64d", &n);
	printf("%I64d\n", n*(n+1)*(n+2) / 2);
	return 0;
}