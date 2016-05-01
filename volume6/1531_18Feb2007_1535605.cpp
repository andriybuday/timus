//problem J
//#include <iostream>
//#include <stdio.h>
//using namespace std;
//#1009; #1012; #1013
#include <stdio.h>
#define MAX 70
int K, N;
int a[MAX];
int b[MAX];
int answer[MAX];
void BigSum()//we add a and b in answer
{
	int next = 0;
	int current = 0;
	int i;
	for(i = 0; i < MAX; i++)
	{
		current = a[i] + b[i] + next;
		answer[i] = current%100000;
		next = current/100000;
	}

}
void Multi_in_k_a(int k)
{
	int next = 0;
	int current = 0;
	int i;
	for(i = 0; i < MAX; i++)
	{
		current = k*a[i] + next;
		a[i] = current%100000;
		next = current/100000;
	}

}
void Multi_in_k_b(int k)
{
	int next = 0;
	int current = 0;
	int i;
	for(i = 0; i < MAX; i++)
	{
		current = k*b[i] + next;
		b[i] = current%100000;
		next = current/100000;
	}

}
void Multi_in_k(int k)
{
	int next = 0;
	int current = 0;
	int i;
	for(i = 0; i < MAX; i++)
	{
		current = k*answer[i] + next;
		answer[i] = current%100000;
		next = current/100000;
	}

}
void print()
{
	int i = MAX-1, j;
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



void pow2a(int x)
{
	a[0] = 2;
	for (int i = 1; i < x; i++)
	{
		//ans *=	2;
		Multi_in_k_a(2);

	}
	//return __int64(1) << x;
	//return ans;
}
void pow2b(int x)
{
	//__int64 ans = 2;
	b[0] = 2;
	for (int i = 1; i < x; i++)
	{
		Multi_in_k_b(2);
	}
	//return __int64(1) << x;
	//return ans;
}

int main()
{
	__int64 n;
	scanf("%I64dd", &n);
	if (n == 1){
		printf("1\n");
		return 0;
	}
	if (n == 2){
		printf("4\n");
		return 0;
	}
	if (n == 3){
		printf("8\n");
		return 0;
	}
	if (n == 4){
		printf("12\n");
		return 0;
	}
	if (n == 5){
		printf("20\n");
		return 0;
	}

	//__int64 res;

	if (n % 2)
	{
		//res = pow2((n - 3)/ 2) - 1 + pow2((n - 1) / 2);
		//res = a - 1 + b;
		pow2a((n - 3)/ 2);
		pow2b((n - 1) / 2);
		BigSum();
		answer[0]--;
	}
	else
	{
		//res = pow2((n - 2) / 2 + 1) - 1;
		pow2a((n - 2) / 2 + 1);
		b[0] = 0;
		BigSum();
		answer[0]--;
		//res = a-1;
	}
	//res = res*4;
	Multi_in_k(4);


	//printf("%I64d\n", res);
	print();
	printf("\n");
	return 0;
}