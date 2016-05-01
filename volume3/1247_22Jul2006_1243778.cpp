//1247
#include <stdio.h>
int main()
{
	int a, n, s, i, ts = 0;
	scanf("%d%d", &n, &s);

for(i = 1; i <= n; i++)
{
	scanf("%d", &a);
	if((ts == 0)&&(a == 0))continue;
	ts += a - 1;
	if(ts > s)
	{
		printf("NO");
		return 0;
	}
}
printf("YES");

return 0;
}
