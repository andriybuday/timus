//#1009; #1012; #1013
#include <stdio.h>
int K, N, k;
int a[500];
int b[500];
int answer[500];
__int64 f(int n)
{	
	if(n == 0)return 0;
	if(n == 1)return k;
	if(n == 2)return K*k;
	return k*(f(n-1) + f(n-2));
}
void BigSum()//we add a and b in answer
{
	int next = 0;
	int current = 0;
	int i;
	for(i = 0; i < 500; i++)
	{
		current = a[i] + b[i] + next;
		answer[i] = current%100000;
		next = current/100000;
	}

}
void Multi_in_k()
{
	int next = 0;
	int current = 0;
	int i;
	for(i = 0; i < 500; i++)
	{
		current = k*answer[i] + next;
		answer[i] = current%100000;
		next = current/100000;
	}

}
void print()
{
	int i = 499, j;
	while((!answer[i])&&(i > 0))i--;

	printf("%d", answer[i]);
	for(j = i-1; j >= 0; j--)
	{
			if(answer[j]%100000 >= 10000)
				{
					printf("%d", answer[j]);
					continue;
				}else
					if(answer[j]%100000 >= 1000)
					{
						printf("0%d", answer[j]);
						continue;
					}else
						if(answer[j]%100000 >= 100)
						{
							printf("00%d", answer[j]);
							continue;
						}else
							if(answer[j]%100000 >= 10)
							{
								printf("000%d", answer[j]);
								continue;
							}else
								if(answer[j]%100000 >= 1)
								{
								printf("0000%d", answer[j]);
								continue;
								}
							
			printf("00000");
		}

}
void K_based(int n)
{
	if(n == 0)
	{
		printf("0");
		return;
	}
	if(n == 1)
	{
		printf("%d", k);
		return;
	}
	if(n == 2)
	{
		printf("%d", K*k);
		return;
	}
	
	answer[0] = 0;
	a[0] = k;
	b[0] = K*k;
	int i, j;
	for(i = 3; i <= n; i++)
	{
		BigSum();//answer is equl to sum of a and b
		Multi_in_k();//answer is multiplaing on num k
	
		for(j = 0; j < 500; j++)
		{
			a[j] = b[j];
			b[j] = answer[j];
			answer[j] = 0;
		}
		
	}
	for (j = 0; j < 500; j++)
	{
		answer[j] = b[j];
	}
	print();
}

int main()
{
	scanf("%d%d", &N, &K);

	k = K-1;

	K_based(N);

return 0;
} 
