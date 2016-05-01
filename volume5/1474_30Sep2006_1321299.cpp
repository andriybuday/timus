//1474
#include <stdio.h>
short a[800000];

int main()
{
	int N, i, j;
	scanf("%d", &N);

	if(N == 1)
	{
		printf("3\n0 2 1");
		return 0;
	}
	
	int steps = 3 + (N-1)*(N+3);
	
	printf("%d\n", steps);
	
	a[0] = -1;
	a[1] = 1; 

	for(i = 2; i <= N; i++)
	{
		int Isteps = 3 + (i-1)*(i+3);
		if(i%2)
		{
			int k = ((Isteps-1)/2) - 1;
			for(j = -1; j >= -i; j -= 2)
			{
				a[k] = j;
				k--;
			}
			for(j = -(i-1); j <= -2; j += 2)
			{
				a[k] = j;
				k--;
			}
		}
		else
		{
			int k = (Isteps/2) - 2;
			a[k + 1] = 0;
			for(j = 2; j <= i; j+=2)
			{
				a[k] = j;
				k--;
			}
			for(j = i-1; j>=1; j-=2)
			{
				a[k] = j;
				k--;
			}
		}
	
	}



if(steps%2)
{
	
	for(i = 0; i <= ((steps-1)/2) - 1; i++)printf("%d ", a[i] + N);
	for(i = ((steps-1)/2) - 1; i >= 0; i--)printf("%d ", -a[i] + N);	
	printf("%d", N);
	return 0;
	
}
else
{
	for(i = 0; i <=(steps/2) - 2; i++)printf("%d ", a[i] + N);
	printf("%d ", 0 + N);
	for(i = (steps/2) - 2; i >= 0; i--)printf("%d ", -a[i] + N);
	printf("%d", N);
}


	return 0;
}
