#include <stdio.h>
void quickSortR(int* a, long N)
{
  long i = 0, j = N;
  int temp, p;

  p = a[ N>>1 ];
  
  do {
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

int arr[100007];
int main()
{
	char *str = new char[4];
	int i, n, k;
	scanf("%d", &n);
	for(i = 0; i < n; i++)scanf("%d", &arr[i]);
	quickSortR(arr, n-1);
	scanf("%s", str);
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &k);
		printf("%d\n", arr[k-1]);
	}
	return 0;
}