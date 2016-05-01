#include <stdio.h>
__int64 m,i,n,n1;

__int64 NSD(__int64 min, __int64 max)
{
	__int64 temp = 1;
	while(temp!=0)
	{
		if(min != 0)temp = max%min;
		if(min == 0)continue;
		max = min;
		min = temp;
		if(temp == 0)continue;
	}
	return max;
}

int main()
{
int n, i; 
scanf("%d", &n);
n1 = (n-1)/2;
m=0;
for (i=1; i <= n1; i++)
{
	if (NSD(i,n)==1)m++;
}
printf("%I64d", m);
}