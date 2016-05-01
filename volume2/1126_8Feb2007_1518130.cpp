//1126_AC
#include <iostream>
#include <set>
using namespace std;
int a[25004];
int main()
{
	multiset<int> divace;
	int m;
	scanf("%d", &m);
	int shower = 256;
	int j = 0;
	while(shower != -1)
	{
		scanf("%d", &shower);
		a[++j] = shower;
	}
	for(int i = 1; i <= m; i++)
	{
		divace.insert(a[i]);
	}
	int max = -1, min = 25625625;
	typedef multiset<int>::iterator I;
	max = *(--divace.end());
	printf("%d\n", max);
	j = m + 1;//upper
	int i = 1;//lover
	while(a[j] != -1)
	{
		divace.insert(a[j]);
		I lovvvvver = divace.lower_bound(a[i]);
		divace.erase(lovvvvver);
		max = *(--divace.end());
		printf("%d\n", max);

		++j;
		++i;
	}


	return 0;
}