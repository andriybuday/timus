//1047_ac with cheat
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

float a[3003],c[3003];

int main()
{
	int n,i;

	scanf("%d",&n);

	scanf("%f%f",&a[0],&a[n+1]);

	for (i=1;i<=n;i++)
		scanf("%f",&c[i]);

	for (int k=n;k>=1;k--)
	{
		a[k]=a[0];

		for (i=k;i>=1;i--)
			a[k]-=i*2*c[i];

		a[k]+=k*a[k+1];
		a[k]/=k+1;
	}

	printf("%0.2f",a[1]);

	return 0;
}