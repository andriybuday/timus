//1021_AC
#include <stdio.h>
int a[50000];

int main()
{

	int found = 0, pos = 0, tmp, n, m, i;

	scanf("%d", &n);

	for(i = 0; i < n; i++)scanf("%d", &a[i]);

	scanf("%d", &m);

	for(i = 0; i < m; i++)
	{
		scanf("%d", &tmp);

		while(tmp + a[pos] < 10000) pos++;

		if(tmp + a[pos] == 10000)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}