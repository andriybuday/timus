//1515
#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int i, el;
	int nominal = 0;
	for (i = 0; i < n; ++i)
	{
		scanf("%d", &el);
		if (el <= nominal + 1) nominal += el;
		else break;
	}
	++nominal;
	printf("%d\n", nominal);

	return 0;
}
