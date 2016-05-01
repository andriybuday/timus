//1293_TL
#include <stdio.h>

int F(int n, int k)
{
	
	int res = 0;
	while(k)
	{
		int kb = k%10;
		res += kb*kb*kb;
		k = k/10;
	}
	n--;
	
	if(n == 1)return res;
	if(res == 153)return 153;
	return F(n, res);

}

int main()
{
	int T, N, K, L, i;
	scanf("%d", &T);

	for(i = 0; i < T; i++)
	{
		scanf("%d%d%d", &N, &K, &L);
		
		printf("%d\n", F(N, K) - L );

	}
	return 0;
}
/*

2
4 6 123
7 93 49

*/