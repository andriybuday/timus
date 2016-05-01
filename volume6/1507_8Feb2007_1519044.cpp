//1507_AC
#include <stdio.h>
	int a[55][55];
	int res_arr[55][55];
	int temp_matrix[55][55];
	int last_power = 1;
void add_and_multiply_matrix(int n,int power_mult)
{
	int i,tempsym = 0, pow_i, h, q, j;
	
	

	for(pow_i = last_power; pow_i < power_mult; pow_i++)	
	{
	
		for(i=0; i < n; i++){
			for(h=0; h < n; h++){
				for(q = 0; q < n; q++)
				{
					tempsym += temp_matrix[i][q] * a[q][h];
				}
				if(tempsym)temp_matrix[i][h]  = 1;//+= tempsym;
				tempsym=0;
			}
		}	
	}
	last_power = power_mult;

	for(i = 0; i < 51; i++)for(j = 0; j < 51; j++)if(temp_matrix[i][j])
	{
		res_arr[i][j]  = 1;//+= temp_matrix[i][j];
		temp_matrix[i][j] = 1;
	}

	return;
}
int main()
{
	int  n, k, i, j, elem;
	for(i = 0; i < 51; i++)for(j = 0; j < 51; j++)res_arr[i][j] = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++)for(j = 0; j < n; j++)
	{
		scanf("%d", &elem);
		if(elem)a[i][j] = 1;
	}

	for(i = 0; i < 51; i++)for(j = 0; j < 51; j++)temp_matrix[i][j] = a[i][j];


	for(k = n*(n-1); k <= n*(n+1); k++)
	{
	//	if(k >= 50)add_and_multiply_matrix(n, 100);
	//	else
			add_and_multiply_matrix(n,n + k/n);
	}
	for(i = 0; i < n; i++)for(j = 0; j < n; j++)
		if(res_arr[i][j] == 0)
		{
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
	return 0;
}