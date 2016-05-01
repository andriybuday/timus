//1221_AC
#include <stdio.h>
int answer = 0;
int matrix[101][101];
inline int isRight(int ii, int jj, int k)
{
	int i, j;
	int begin = jj +(k-1)/2;
	int end = jj + (k-1)/2;
	for(i = ii; i <= (ii+(k-1)/2); i++)
	{
		for(j = jj; j < begin; j++)if(!matrix[i][j])return 0;

		for(j = begin; j <= end; j++)if(matrix[i][j])return 0;

		for(j = end+1; j < jj + k; j++)if(!matrix[i][j])return 0;
		begin--;
		end++;
	}
	begin++; end--;
	for(i = (ii+(k-1)/2) + 1; i < ii+k; i++)
	{
		begin++;
		end--;
		for(j = jj; j < begin; j++)if(!matrix[i][j])return 0;

		for(j = begin; j <= end; j++)if(matrix[i][j])return 0;

		for(j = end+1; j < jj + k; j++)if(!matrix[i][j])return 0;
	}
	return k;
}
int main()
{
	int N;
	int i, j, k;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &N);

	while(N)
	{
		answer = 0;

		for(i = 0; i < N; i++)for(j = 0; j < N; j++)scanf("%d", &matrix[i][j]);
		
		for	(k = N; k > 2; k--)
		{
			if(!(k%2))continue;
			for(i = 0; i <= N-k; i++)
			{
				for(j = 0; j <= N-k; j++)
				{
					if(isRight(i, j, k))
					{
						answer = k;
						printf("%d\n", k);
						goto GGG;
					}
				}
			}
		}
		GGG:
		if(!answer)printf("No solution\n");
		scanf("%d", &N);
	}

	return 0;
}