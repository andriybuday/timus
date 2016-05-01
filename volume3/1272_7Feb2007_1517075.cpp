#include <iostream>
#include <set>
using namespace std;
int a[10005];
int main()
{
	int n, k, m;
	int first, second;
	scanf("%d%d%d", &n, &k, &m);
	int counter = 1;
	for (int i = 0; i < k; i++)
	{
		scanf("%d%d", &first, &second);
		if(!a[first] && !a[second])
		{
			a[first] = a[second] = counter;
			++counter;
			continue;
		}
		if(a[first] && !a[second])
		{
			a[second] = a[first];
			continue;
		}
		if(!a[first] && a[second])
		{
			a[first] = a[second];
			continue;
		}
		if(a[first] && a[second])
		{
			int temp_first = a[first];
			int temp_second = a[second];
			for (int j = 1; j <= n; j++)
			{
				if(a[j] == temp_second)a[j] = temp_first;
			}
			continue;
		}
	}

	int zeros = 0;
	set<int> differs;
	for(int i = 1; i <= n; i++)
	{
		if(a[i])
		{
			differs.insert(a[i]);
		}
		else ++zeros;
	}

	printf("%d\n", zeros + differs.size() - 1);

	return 0;
}