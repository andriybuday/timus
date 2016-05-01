//1260
#include <stdio.h>
int a[100];
int main()
{
	a[1]=1;
	a[2]=1;
	a[3]=2;
	for(int i = 4; i < 56; i++)
		a[i] = a[i-1]+a[i-3]+1;	

	int n;
	scanf("%d", &n);

	printf("%d", a[n]);
	return 0;
}

