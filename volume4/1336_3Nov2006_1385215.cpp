#include <stdio.h>
int main()
{
	__int64 n;
	scanf("%I64d", &n);
	printf("%I64d\n%I64d\n", n*n, n);
	return 0;
}