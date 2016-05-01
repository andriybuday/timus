//1136_SB
#include <stdio.h>
int a[3003];
void print_the_root(int beg,int end)
{
	if(beg == end)
	{
		printf("%d ", a[end]);
		return;
	}
	if(beg > end)return;
	int i = end-1;
	while(a[i] > a[end])
	{
		--i;
	}

	print_the_root(i+1, end-1);//B
	print_the_root(beg, i);//A

	printf("%d ", a[end]);
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	print_the_root(1,n);

	return 0;
}