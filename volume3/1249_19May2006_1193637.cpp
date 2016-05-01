#include <stdio.h>
int prev[3007];
int next[3007];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);

	int i, j, need;

	for(i=1; i<=n;i++)
	{
		
		for(j=1; j<=m; j++)
		{
			scanf("%d", &need);
			int curr_index = j;	
				while(need)
				{
					j++;
					next[curr_index]++;
					if(j>m)break;
					scanf("%d", &need);
				}
				if((need == 0)&&(j==m)){
					next[j] = need;
				}
		}


		for(j = 1; j <= m; j++)
		{
		//---
			if((prev[j])&&(!next[j]))
			{
				int pos = j + prev[j];
				for(int k = j; k < pos; k++)
				{
					if(next[k])
					{
						printf("No");
						return 0;
					}
				}
				j = pos;
			}else
			if((!prev[j])&&(next[j]))
			{
				int pos = j + next[j];
				for(int k = j; k < pos; k++)
				{
					if(prev[k])
					{
						printf("No");
						return 0;
					}
				}
				j = pos;
			}else
			if(prev[j] != next[j])
			{
				printf("No");
				return 0;
			}
		}
		for(j = 1; j <= m; j++)
		{
		
			prev[j] = next[j];
			next[j] = 0;
		}
	}

	printf("Yes");

	return 0;
}
