//1448_AC
#include <stdio.h>
int main()
{
register int N, b, i;
scanf("%d%d", &N, &b);
double L = 100.0/double(b);
double Period = L/2.0;

for(i = 0; i < N; i++)
	if((Period-i < 1.0)&&(Period-i > -1.0))
	{
		printf("1");
		Period += L;
	}
	else printf("0");
return 0;
}
