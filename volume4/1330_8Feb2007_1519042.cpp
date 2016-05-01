//1330
#include <stdio.h>
int sensor[10007];
int main()
{
int n;
scanf("%d", &n);
int i, sum = 0, tmp_for_sum;
for(i = 1; i <= n; i++)
{
	scanf("%d", &tmp_for_sum);
	sum += tmp_for_sum;
	sensor[i] = sum;
}
int q;
scanf("%d", &q);
int ii = 0, jj = 0;
for(i = 0; i < q; i++)
{
	scanf("%d%d", &ii, &jj);
	printf("%d\n", sensor[jj] - sensor[ii - 1]);
}

return 0;
}
