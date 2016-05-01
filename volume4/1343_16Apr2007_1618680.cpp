//1343_AC
#include <stdio.h>

#define PR_ARR 5000000
#define PR_DONE 340000
__int64 a[PR_DONE + 10000],i,n,m;
bool b[PR_ARR + 50];
void make()
{
	__int64 i,j,an;
	for (i=2; i<PR_ARR; i++)
		if (!b[i])
			for (j=2; j<=PR_ARR/i; j++)
				if (i*j<=PR_ARR) b[i*j]=1;
	an=0;
	for (i=2; i<PR_ARR; i++)
		if (!b[i])
		{
			an++;
			a[an]=i;
		}
}
int main()
{
	make();

	__int64 shield;

	scanf("%I64d", &n);
	if(n == 0)
	{
		printf("000000000017");
		return 0;
	}
	scanf("%I64d", &shield);

	for(i = 0; i < 12-n; ++i)shield *= 10;

	bool flag = 0;
	while(1)
	{

		i = 0;
		for(i = 1; i <= PR_DONE; ++i)
			if(!(shield % a[i]))
			{
				shield++;
				flag = 1;
				break;
			}

			if(flag)
			{
				flag = 0;
				continue;
			}
			else printf("%012I64d\n", shield);
			return 0;
	}

	/*
	while(true)
	{
	scanf("%d %I64d", &n, &shield);
	printf("%I64d\n", NSD(n, shield));
	}
	*/


	printf("%I64d", shield);

	return 0;
}