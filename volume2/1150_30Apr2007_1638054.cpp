//1150_AC
#include <stdio.h>
#include <string.h>

int i,j,k,m,n,x,k1,y,z;
int s[100],tem;
int a[10];
int b[12];

int main()
{
	j=1;
	b[1]=1;
	for (i=2;i<=10;i++)
	{
		j*=10;
		b[i]=j;
	}
	memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	scanf("%d",&n);
	k=1;
	while (n!=0)
	{
		s[++k]=n%10;
		n/=10;
	}
	for (i=2,j=k;i<j;i++,j--)
	{
		tem=s[i];
		s[i]=s[j];
		s[j]=tem;
	}
	m=0;
	for (i=2;i<=k;i++)
	{
		x=0;
		for (j=1;j<i;j++)
			x=x*10+s[j];
		y=s[i];
		z=0;
	for (j=i+1;j<=k;j++)
		z=z*10+s[j];
	z++;
	if (y!=0)
	{
		a[0]+=(x*b[k-i+1]);
		a[y]+=(x*b[k-i+1]+z);
	} 
	else 
		a[0]+=(x-1)*b[k-i+1]+z;
	for (j=1;j<=9;j++)
	{
		if (j<y)
			a[j]+=(x+1)*b[k-i+1];
		if (j>y)
			a[j]+=x*b[k-i+1];
	}
	}
	for (i=0;i<=9;i++)
		printf("%d\n",a[i]);
	return 0;
}