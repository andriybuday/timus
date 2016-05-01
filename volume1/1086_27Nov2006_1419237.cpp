//1086_AC
#include <stdio.h>
int a[15001],b[200000],i,n,m;
void make()
{
int i,j,an;
for (i=2; i<200000; i++)
if (!b[i])
for (j=2; j<=200000/i; j++)
if (i*j<=200000) b[i*j]=1;
an=0;
for (i=2; i<200000; i++)
if (!b[i])
{
an++;
a[an]=i;
}
}
int main()
{
	make();
	scanf("%d", &n);
	int index;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &index);
		printf("%d\n", a[index]);
	}
return 0;
}

