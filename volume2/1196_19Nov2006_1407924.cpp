#include <stdio.h>

int a[15003];

int main()
{
	int n, k, i, j;

	scanf("%d", &n);

	for(i = 0; i < n; i++)scanf("%d", &a[i]);
	
	scanf("%d", &k);

	int counter = 0;

	for(i = 0; i < k; i++)
	{
		int year;
		scanf("%d", &year);
		///binary search
		int curr = n/2, roof = n-1, floor = 0;

		while(true)
		{
			if(year == a[curr])
			{
				counter++;
				break;
			}else
			if(year > a[curr])
			{
				floor = curr;
				curr += (roof-curr)/2;
			}else
			if(year < a[curr])
			{
				roof = curr;
				curr -= (curr - floor)/2;
			}
			if(roof - floor <= 2)
			{
				for(j = floor; j <= floor + 2; j++)
				{
					if(year == a[j])
					{
						counter++;
						break;
					}
				}
				break;
			}
		}
		
		///end of it
	}

	printf("%d\n", counter);

	return 0;
}