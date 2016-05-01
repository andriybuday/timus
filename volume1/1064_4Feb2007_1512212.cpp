#include <stdio.h>
#define MAXN 10000

int A[MAXN];
int b[MAXN + 5];
int N;

int BinarySearch(int x)
{
  int p, q, i, L;

  p = 0;   /* Left border of the search  */
  q = N-1; /* Right border of the search */
  L = 0;   /* Comparison counter         */
  while (p <= q) {
    i = (p + q) / 2;
    ++L;
    if (A[i] == x)
	{
      //printf("Found item i = %d"" in L = %d comparisons", i, L);
      return L;
    }
    if (x < A[i])
      q = i - 1;
    else
      p = i + 1;
  }
  return -599999;
}
int main()
{
	//N = MAXN;
	for(int i = 0; i < MAXN; i++)A[i] = i;
	int I, L;
	scanf("%d%d", &I, &L);

	for(N = 0; N <= MAXN; N++)
	{
		if(BinarySearch(I) == L)b[N] = 1;
	}

	int interval_counter = 0;
	for(int i = 0; i <= MAXN; i++)
	{
		if(b[i])
		{
			++interval_counter;
			A[interval_counter] = i;

			while(b[i])i++;
			i--;
			/*
			if(A[interval_counter] == i)B[interval_counter] = i;
			else
				*/
			b[interval_counter] = i;
		}
	}
	printf("%d\n", interval_counter);
	for(int i = 1; i <= interval_counter; i++)
	{
		printf("%d %d\n", A[i], b[i]);
	}




	return 0;
}