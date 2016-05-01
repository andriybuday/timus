//1191_AC
#include <stdio.h>

int main()
{
	int cop,n,ti,rob = 0,st,ost,tmp;
	scanf("%d %d",&cop,&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&ti);
		st = rob;
		rob += ti;
		if (rob > cop)
		{
			printf("YES\n");
			return 0;
		}
		st = cop-st;
		ost = st%ti;
		cop += (ti-ost);
	}

	printf("NO\n");
	return 0;
}