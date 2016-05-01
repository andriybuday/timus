//1091_AC think more
#include <stdio.h>
#define DOFIGA 9999999
int NSD(int min, int max)
{
	int temp = 1;
	while(temp!=0)
	{
		if(min != 0)temp = max%min;
		if(min == 0)continue;
		max = min;
		min = temp;
		if(temp == 0)continue;
	}
	return max;
}

int k, s;
int way[57][57][57];

int get_way( int d, int g, int lst)
{
	if ( d == k ) return 1;

	if ( way[d][g][lst] < DOFIGA ) return way[d][g][lst];

	int curr = 0,i ,j ;

	for (i = lst; i <= s; ++i)
	{
		j = NSD(i,g);

		if (j > 1)curr += get_way(d+1, j, i+1);
	}
	
	way[d][g][lst] = curr;

	return curr;
}

int main()
{

	for(int ii = 0; ii < 51; ++ii)for(int jj = 0; jj < 51; ++jj)for(int kk = 0; kk < 51; ++kk)way[ii][jj][kk] = DOFIGA;

	scanf("%d %d", &k, &s);

	int ans = get_way(0,0,2);

	if(ans > 10000)ans = 10000;

	printf("%d\n", ans);

	return 0;
}

