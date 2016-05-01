#include <stdio.h>

void quickSortR(int* a, long N) 
{
  long i = 0, j = N; 
  int temp, p;

  p = a[ N>>1 ];

  
  do
  {
    while ( a[i] < p ) i++;
    while ( a[j] > p ) j--;

    if (i <= j) {
      temp = a[i]; a[i] = a[j]; a[j] = temp;
      i++; j--;
    }
  } while ( i<=j );

  if ( j > 0 ) quickSortR(a, j);
  if ( N > i ) quickSortR(a+i, N-i);
}

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

inline int NSK(int x, int y)
{
	return x / NSD(x, y) * y;
}




int a[1002];
int k[1002];

int main()
{
	int n, i, x;

	scanf("%d", &n);
		
	for(i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}

	for(i = 1; i <= n; i++)
	{
		int j = i;

		int count = 1;

		while(a[j] != i)
		{
			j = a[j];
			count++;
		}	
		k[i] = count;
	}

	quickSortR(k, n);
	
	int curr_NSK = k[1];

	for(i = 1; i <= n; i++)
	{
		curr_NSK = NSK(curr_NSK, k[i]);
	}

	printf("%d", curr_NSK);

	return 0;
}
