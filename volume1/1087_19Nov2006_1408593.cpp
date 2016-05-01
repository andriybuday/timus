//1087_AC_cheat

#include <stdio.h>
int a[10003];
int b[51];

void computation(int n,int m)
{

	int i,j;

	a[0]=1;
	for(i=1;i<=n;i++)
	{
		bool sign=false;

		for(j=1;j<=m;j++)
			if(i-b[j]>=0&&a[i-b[j]]==2) sign=true;
		if(sign) a[i]=1;
		else a[i]=2;
	}
	printf("%d\n",a[n]);
// for(i=1;i<=n;i++) printf("%d ",a[i]);
}
int main()
{
int n, m, i;
scanf("%d%d", &n, &m);
for(i = 1; i <= m; i++)
scanf("%d", &b[i]);

computation(n,m);

return 0;
}