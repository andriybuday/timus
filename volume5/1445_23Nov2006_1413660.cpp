#include <stdio.h>
int a[502];
int main()
{
	int n;
	scanf("%d", &n);
	int i;
	for(i = 0; i < n; i++)scanf("%d", &a[i]);
	int max = -516454;
	int sum = 0;
	for(i = 0; i < n; i++)
	{
		if(max <= a[i])max = a[i];
		sum += a[i];
	}
	sum -= max;

	int min = 1;
	if(max - sum <= 1)min = 1;
	else min = max - sum;


	printf("%d %d\n",min , max);


	return 0;
}